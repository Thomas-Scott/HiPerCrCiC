#include "TabBarController.h"
#include <iostream>

TabBarController::TabBarController(CGRect const& rect)
{
  _currentRegion = new CGRect(rect);
  _barViewController = new TabBarViewController();
}

TabBarController::~TabBarController()
{
  delete _barViewController;
  for(map<string, ViewController *>::iterator it = _tabContentControllers.begin();
    it != _tabContentControllers.end(); ++it)
  {
    delete it->second;
  }
  delete _currentRegion;
}

void TabBarController::setTabBarViewController(TabBarViewController const& viewController)
{
  delete _barViewController;
  _barViewController = new TabBarViewController(viewController);
}

void TabBarController::setCurrentView(ViewController * content)
{
  _currentViewController = content; // no deallocation here, because _currentView is a duplicate of a pointer in the set
}

ViewController * TabBarController::getContentViewControllerWithTitle(string title)
{
  map<string, ViewController *>::iterator it = _tabContentControllers.find(title);
  if (it != _tabContentControllers.end()) // then a viewController with that title was found
  {
    return it->second;
  }
  else
  {
    std::cout << "Error:\tNo ViewController with provided title could be found." << std::endl;
    return 0;
  }
}

void TabBarController::addTab(string title, ViewController * content)
{
  // TODO: guard against adding two tabs with the same title, would have to use a multimap for this anyway
  
  if(_barViewController->getTabCount() == 0)
  {
    _barViewController->addTabWithTitle(title, true); // is the first tab
  }
  else
  {
    _barViewController->addTabWithTitle(title);
  }
  _tabContentControllers.insert(pair<string, ViewController *>(title, content));
}

bool TabBarController::removeTabWithTitle(string title)
{
  _barViewController->removeTabWithTitle(title);
  map<string, ViewController *>::iterator it = _tabContentControllers.find(title);
  if (it != _tabContentControllers.end()) // then a viewController with that title was found
  {
    delete it->second;
    _tabContentControllers.erase(it);
    return true;
  }
  else
  {
    std::cout << "Error:\tNo ViewController with provided title `" << title << "` could be found." << std::endl;
    return false;
  }
}

// Handlers

void TabBarController::tabSelectedWithTitle(string title)
{
  ViewController * temp = getContentViewControllerWithTitle(title);
  if (temp)
  {
    _currentViewController = temp;
  }
}

bool TabBarController::mouseClickHandler(CGPoint const& point)
{
  View * tabBarMasterView = _barViewController->getMasterView();
  View * currentContentMasterView = _currentViewController->getMasterView();
  if (tabBarMasterView->isInsideBounds(point))
  {
    // iterate through subviews of tabBarMasterView to see if any were clicked
    if (_barViewController->getTabCount() > 0)
    {

      set<View *> * subViews = tabBarMasterView->getPointerToSubViewSet();
      for (set<View *>::iterator it = subViews->begin(); it != subViews->end(); ++it)
      {
        if ( (*it)->isInsideBounds(point) )
        {
          // then this BarItem was clicked
          (*it)->mouseClickHandler(point); // call it's mouseClickHandler
          // set the current view controller to the view with the same title as this button
          string title = (*it)->getId(); // we have set the id to be the same as the title
          ViewController * tempVCP = getContentViewControllerWithTitle(title);
          setCurrentView(tempVCP);
        }
      }

    }
    
    return true; // since this should return true if any space controlled by this controller was clicked
  }
  else if (currentContentMasterView->isInsideBounds(point))
  {
    // call mouseClickHandler on the master view of the current contentViewController
    currentContentMasterView->mouseClickHandler(point);
    return true;
  }
  else
  {
    // the mouse click did not occur inside the application space represented by this TabBarController
    return false;
  }

}

void TabBarController::drawViews()
{
 
  View * tabBarMasterView = _barViewController->getMasterView();
  View * currentContentMasterView = _currentViewController->getMasterView();

   // first update the view bounds as necessary, based on _currentRegion
  tabBarMasterView->setBounds(CGRect(
    _currentRegion->getX(), 
    _currentRegion->getY(), 
    _currentRegion->getWidth(), 
    100));

  currentContentMasterView->setBounds(CGRect(
    _currentRegion->getX(), 
    _currentRegion->getY() + 100, 
    _currentRegion->getWidth(), 
    _currentRegion->getHeight() - 100));

  // then call the appropriate draw methods, 
  // drawing the content first, then the tabBar
  currentContentMasterView->draw();
  tabBarMasterView->draw();
}
