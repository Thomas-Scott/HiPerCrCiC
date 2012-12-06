#ifndef _View_h_
#define _View_h_

#include <set>
#include <string>
#include "CGClasses.h"
#include "Event.h"
using namespace std;

class View
{
private: // private variables
  View *_superView; // set to 0 until added to superview BY THE SUPERVIEW, is zero if topmost view
  set<View *> _subViews;

  bool _isTopView;
  string _id; // initialized to ""
  
  CGRect *_viewBounds;
  CGColor *_backgroundColor;

  bool _focusable; // whether or not this view can recieve focus
  bool _canRecieve;
  EventClassification _acceptedEvents;
  bool _hasFocus;

public: // public variables

private: // private methods

public: // public methods

// Constructors and Destructor
  View(CGRect const& rect = CGRect(0,0,100,100), CGColor const& color = CGColor(1.0, 1.0, 1.0, 1.0), string id = "", bool isTop = false);
  View(View const& view);
  virtual ~View();

// Getters and Setters
  View * getSuperView() const { return _superView; } // returns a pointer to the superview
      // No setter for _superView, that is done in addSubView

  string getId() const { return _id; }
  void setId(string id) { _id = id; }

  bool getIsTopView() const { return _isTopView; }
  void setIsTopView(bool n) { _isTopView = n; }

  CGRect getBounds() const { return *_viewBounds; }
  void setBounds(CGRect const& bounds);
  CGRect getGlobalBounds() const; // recursively goes up to the top of the view hierarchy to return the globally positioned bounding box of this view

  CGColor getColor() const { return *_backgroundColor; }
  void setBackgroundColor(CGColor const& color);

  bool getFocusable() const { return _focusable; }
  void setFocusable(bool val) { _focusable = val; }

  bool getHasFocus() const { return _hasFocus; }
  void setHasFocus(bool val) { if (_focusable) _hasFocus = val; } // guards against changing the fous of a non-focusable element

  bool getCanRecieve() const { return _canRecieve; }
  void setCanRecieve(bool val) { _canRecieve = val; }
  void setCanRecieveRecursive(bool val);

  View* getSubViewWithId(const string id); // returns a pointer to the subView with the given id, returns 0 if subview not found
 
  set<View *> * getPointerToSubViewSet(){ return &_subViews; }
  
  EventClassification getAcceptedEvents() const { return _acceptedEvents; }
  void setAcceptedEvents(EventClassification eC) { _acceptedEvents = eC; }


// Checkers
  bool isInsideBounds(CGPoint const& point);
// ViewAdders and ViewRemovers  
  View* addSubView(View * view); // adds the pointed to subview to this view, sets its superView pointer, and returns a pointer to it
  View* addSubView(); // same as above, but subview is empty
  bool removeSubViewWithId(const string id); // removes the subview with the given id from this view and calls its destructor
  bool removeSubViewWithPointer(View * const viewPointer);
  void removeSelf(); // removes this subview from the superview by telling the superview to call its removeSubView with this subView's id

// Handlers : for old system, soon to be deprecated
  virtual bool mouseClickHandler(CGPoint const& point);

// Event Handlers for new system, return true when handled, false otherwise
  virtual bool onLeftClick(CGPoint const& pos);
  virtual bool onRightClick(CGPoint const& pos);
  virtual bool onMouseDown(CGPoint const& pos);
  virtual bool onMouseMove(CGPoint const& pos);
  virtual bool onMouseOver(CGPoint const& pos);
  virtual bool onMouseOut(CGPoint const& pos);
  virtual bool onMouseUp(CGPoint const& pos);
  virtual bool onMouseDrag(CGPoint const& pos);
  virtual void onFocusIn();
  virtual void onFocusOut();
  virtual bool onKeyDown(unsigned char const& key);
  virtual bool onKeyUp(unsigned char const& key);
  virtual bool onKeyPress(unsigned char const& key);
  virtual void onCrawlerUpdate();

// Self-registration
  virtual void registerSelfAsMouseListener();
  virtual void registerSelfAsKeyboardListener();

  virtual void removeSelfAsMouseListener();
  virtual void removeSelfAsKeyboardListener();

  virtual void registerSelfAsCrawlerListener();
  virtual void removeSelfAsCrawlerListener();
// Render Code
  virtual void draw(); // draws the view inside its rectangle, can be overridden in subtypes
  virtual void callDrawOnSubViews();

};
#endif // _View_h_