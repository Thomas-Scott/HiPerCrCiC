// Michael Taufen 2012
#ifndef _Tab_Bar_Controller_h_
#define _Tab_Bar_Controller_h_

#include <map>
#include <string>
#include "TabBarViewController.h"
using namespace std;

class TabBarController
{
private: // private variables
  TabBarViewController * _barViewController; // controls the actual bar of tabs
  map<string, ViewController *> _tabContentControllers; // the ViewControllers that manage the content of one tab each
  ViewController * _currentViewController; // the view associated with the currently selected tab
  CGRect * _currentRegion; // a CGRect representing the space available to draw this application space in
public: // public variables

private: // private methods

public: // public methods
// Constructors and Destructors
  TabBarController(CGRect const& rect);
  // No copy constructor for now, not needed
  ~TabBarController();

// Getters and Setters
  TabBarViewController * getTabBarViewController() const { return _barViewController; }
  void setTabBarViewController(TabBarViewController const& viewController);

  ViewController * getCurrentView() const { return _currentViewController; }
  void setCurrentView(ViewController * content);

  ViewController * getContentViewControllerWithTitle(string title);

// Adders and Removers
  void addTab(string title, ViewController * content); // cannot add empty tabs

  bool removeTabWithTitle(string title);

// Handlers
  void tabSelectedWithTitle(string title);
  bool mouseClickHandler(CGPoint const& point);

// Manipulators
  void selectTabWithTitle(string title);

// Render code
  void drawViews();

};

#endif // _Tab_Bar_Controller_h_