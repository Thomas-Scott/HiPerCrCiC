#ifndef _Bar_Item_h_
#define _Bar_Item_h_

#include <string>

#include "View.h"


class BarItem : public View
{

private: // private variables
BarItem * _previous; // non-const pointer to a const value
BarItem * _next;
std::string _title;

public: // public variables

private: // private methods
  
public: // public methods
// Constructors and Destructors
  BarItem(string title, BarItem * prev, BarItem * nxt, 
    int width, int height);
  virtual ~BarItem();

// Getters and Setters
  BarItem * getPrevious() const { return _previous; }
  void setPrevious(BarItem * item);

  BarItem * getNext() const { return _next; }
  void setNext(BarItem * item);

  string getTitle() const { return _title; }
  void setTitle(string t);

// Handlers
  virtual bool mouseClickHandler(CGPoint const& point); // returns true if clicked, false otherwise

// Render Code
  virtual void draw();

};

#endif // _Bar_Item_h_