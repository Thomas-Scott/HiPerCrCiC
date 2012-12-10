// Michael Taufen 2012
#include "TabBarViewController.h"
#include <iostream>

TabBarViewController::TabBarViewController() : ViewController()
{
  _tabCount = 0;

  View * masterView = getMasterView();
  CGColor temp = CGColor();
  temp.setColorWithHSB(0.0, 0.0, 0.0);
  masterView->setBackgroundColor(temp);
}

TabBarViewController::~TabBarViewController()
{

}

void TabBarViewController::addTabWithTitle(string title, bool first)
{
  if(title == "")
  {
    std::cerr << "A unique, non-empty title must be specified to add a new tab." << std::endl;
    return;
  }
  View * masterView = getMasterView();
  BarItem * itemToAdd;
  if (first)
  {
    itemToAdd = new BarItem(title, 0, 0, 
      200, masterView->getBounds().getHeight() );
    itemToAdd->setState(ACTIVE);
  }
  else
  {
      itemToAdd = new BarItem(title, _last, 0, 
        200, masterView->getBounds().getHeight() );
      itemToAdd->setState(INACTIVE);
      // set the _next pointer of the previous BarItem to the new BarItem
      _last->setNext(itemToAdd);
  }
  itemToAdd->setId(title); //set it's id to the same as the title to help find it later
  masterView->addSubView(itemToAdd);
  _last = itemToAdd;
  _tabCount++;
}

bool TabBarViewController::removeTabWithTitle(string title)
{
  View * masterView = getMasterView();
  if ( masterView->getSubViewWithId(title) )
  {
    BarItem * itemToRemove = ((BarItem *) (masterView->getSubViewWithId(title)) );
    
    itemToRemove->getNext()->setPrevious(itemToRemove->getPrevious());
    itemToRemove->getPrevious()->setNext(itemToRemove->getNext());

    if ( masterView->removeSubViewWithId(title) )
    {
      _tabCount--;
      return true;      
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}







