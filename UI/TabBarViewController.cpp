#include "TabBarViewController.h"
#include "BarItem.h"

TabBarViewController::TabBarViewController() : ViewController()
{
  _tabCount = 0;
}

TabBarViewController::~TabBarViewController()
{

}

void TabBarViewController::addTabWithTitle(string title, bool first)
{
  View * masterView = getMasterView();
  BarItem * itemToAdd;
  if (first)
  {
    itemToAdd = new BarItem(title, 0, 0, 
      200, masterView->getBounds().getHeight() - 20);
    itemToAdd->setState(ACTIVE);
  }
  else
  {
      itemToAdd = new BarItem(title, _last, 0, 
        200, masterView->getBounds().getHeight() - 20);
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


void TabBarViewController::update()
{
  // do any updating or stuff here
  getMasterView()->draw();
}







