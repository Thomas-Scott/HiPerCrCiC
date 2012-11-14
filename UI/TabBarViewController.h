#ifndef _Tab_Bar_View_Controller_h_
#define _Tab_Bar_View_Controller_h_

#include "ViewController.h"
#include "BarItem.h"
using namespace std;

class TabBarViewController : public ViewController
{
private: // private variables
  int _tabCount;
  BarItem * _last;
public: // public variables

private: // private methods
  void (*_setCurrentTab)(string title);
public: // public methods
// Constructors and Destructors
  TabBarViewController();
  virtual ~TabBarViewController();

// Getters and Setters
  int getTabCount() const { return _tabCount; }

// Adders and removers
  void addTabWithTitle(string title, bool first = false); // adds a tab with the given title to the end of the list of tabs
  bool removeTabWithTitle(string title); // removes the tab with the given title and resets the references appropriately

// Actions


};

#endif // _Tab_Bar_View_Controller_h_