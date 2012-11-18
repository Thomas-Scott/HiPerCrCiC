#include <iostream>
#include "View.h"
#include "CommonGLFunctions.h"

//#include "CommonGLFunctions.h"

// Public Methods

// |-----------------------------|
// | Constructors and Destructor |
// |-----------------------------|

View::View(const CGRect &rect, const CGColor &color, string id, bool isTopView) // default values provided in header
{
  _viewBounds = new CGRect(rect);
  _backgroundColor = new CGColor(color);
  _id = id;
  _isTopView = isTopView;
  _superView = 0; // set superView to null initially
  _focusable = false;
  _canRecieve = true;
}

View::View(View const& view)
{
  _viewBounds = new CGRect( view.getBounds() );
  _backgroundColor = new CGColor( view.getColor() );
  _id = view.getId();
  _isTopView = view.getIsTopView(); // Note: making more than one top view may get dangerous, USE CAUTION
  _superView = view.getSuperView();
  _focusable = view.getFocusable();
  _canRecieve = view.getCanRecieve();
}

View::~View()
{
  for(set<View*>::iterator it = _subViews.begin(); it != _subViews.end(); ++it) // delete all subviews
  {
     delete *it;
  }
  delete _viewBounds;
  delete _backgroundColor;
}

// |-----------------------------|
// |    Getters and Setters      |
// |-----------------------------|

void View::setBounds(CGRect const& bounds)
{
  delete _viewBounds;
  _viewBounds = new CGRect(bounds);
}

void View::setBackgroundColor(CGColor const& color)
{
  delete _backgroundColor;
  _backgroundColor = new CGColor (color);
}

View* View::getSubViewWithId(const string id) // returns the address of the subView with the given id, returns 0 if subview not found
{
  for(set<View*>::iterator it = _subViews.begin(); it != _subViews.end(); ++it) // delete all subviews
  {
    if(*it) // if the pointed to space of the vector is not a null pointer it is an initialized subview
      if( id == (*it)->getId() )
        return *it;
  }
  // else  
  std::cerr << "Error:\tNo subView exists with designated id `" << id << "`. Returning 0. [In: View::getSubViewWithId(const string id)]" << std::endl;
  return 0;
}

void View::setCanRecieveRecursive(bool val)
{
    this->setCanRecieve(val);
    for (set<View*>::iterator it = _subViews.begin(); it !=_subViews.end(); ++it)
    {
      (*it)->setCanRecieveRecursive(val);
    }
}

// |-----------------------------|
// |          Checkers           |
// |-----------------------------|

bool View::isInsideBounds(CGPoint const& point)
{
  return getBounds().isInside(point);
}

// |-----------------------------|
// |    Adders and Removers      |
// |-----------------------------|

View* View::addSubView(View * view) // adds the pointed to subview to this view and returns a pointer to it
{
  view->_superView = this;
  _subViews.insert(view);
  return view;
}

View* View::addSubView() // same as above, but empty
{
  View* view = new View();
  view->_superView = this;
  _subViews.insert(view);
  return view;
}

bool View::removeSubViewWithId(const string id) // removes the subview with the given id from this view and calls its destructor
{
  for (set<View*>::iterator it = _subViews.begin(); it != _subViews.end(); ++it) // delete all subviews
  {
    if ( (*it)->getId() == id )
    {
      delete *it; // de-initialize the View * of matching id
      _subViews.erase(it); // remove the pointer to the now deleted subview from the set
      return true;
    }
  }
  //else
  std::cerr << "Error:\tNo subView exists with designated id`" << id << "`. [In: View::removeSubViewWithId(const string id)]" << std::endl;
  return false;
}

bool View::removeSubViewWithPointer(View * const viewPointer)
{
  set<View*>::iterator it = _subViews.find(viewPointer);
  if (it != _subViews.end())
  {
    delete *it;
    _subViews.erase(it);
    return true;
  }
  else
  {
    std::cout << "Error:\tNo subView could be matched with provided pointer. [In: View::removeSubViewWithPointer(View * const viewPointer)]" << std::endl;
    return false;
  }
    
}

void View::removeSelf() // removes this subview from the superview by telling the superview to call its removeSubView with this subView's id
{
  if (_superView)
  {
    _superView->removeSubViewWithPointer(this); // passes this view's id to the removeSubView function of the superView
  }
  else if (_isTopView)
  {
    std::cerr << "Error:\tView is top level of view hierarchy. Cannot remove self; must be removed by view controller. [In: View::removeSelf()]" << std::endl;
  }
  else
  {
    std::cerr << "Error:\tView *_superView is null. [In: View::removeSelf()]" << std::endl;
  }
}

// Handlers

bool View::mouseClickHandler(CGPoint const& point)
{
  if (isInsideBounds(point))
    return true;
  else
    return false;
}

void View::onLeftClick(CGPoint const& pos)
{
  cerr << this->getId() << ": onLeftClick recieved" << endl;
}

void View::onRightClick(CGPoint const& pos)
{
  cerr << this->getId() << ": onRightClick recieved" << endl;
}

void View::onMouseDown(CGPoint const& pos)
{
  cerr << this->getId() << ": onMouseDown recieved" << endl;
}

void View::onMouseMove(CGPoint const& pos)
{
  cerr << this->getId() << ": onMouseMove recieved" << endl;
}

void View::onMouseOver(CGPoint const& pos)
{
  cerr << this->getId() << ": onMouseOver recieved" << endl;
}

void View::onMouseOut(CGPoint const& pos)
{
  cerr << this->getId() << ": onMouseOut recieved" << endl;
}

void View::onMouseUp(CGPoint const& pos)
{
  cerr << this->getId() << ": onMouseUp recieved" << endl;
}

void View::onFoucsIn()
{
  cerr << this->getId() << ": onFoucsIn recieved" << endl;
}

void View::onFocusOut()
{
  cerr << this->getId() << ": onFocusOut recieved" << endl;
}

void View::onKeyDown(char const& key)
{
  cerr << this->getId() << ": onKeyDown recieved" << endl;
}

void View::onKeyUp(char const& key)
{
  cerr << this->getId() << ": onKeyUp recieved" << endl;
}

void View::onKeyPress(char const& key)
{
  cerr << this->getId() << ": onKeyPress recieved" << endl;
}


// |-----------------------------|
// |         Render Code         |
// |-----------------------------|

void View::draw() 
{
  // draw this view first, then call draw on all of the subviews.
  // Use the superview pointer to do the math for relative coords
  // TODO: remember to handle if top view or superview undefined

  // Set up coords
  //  Save individual variables of bounds to restore later
  int x = this->getBounds().getX();
  int y = this->getBounds().getY();
  int width = this->getBounds().getWidth();
  int height = this->getBounds().getHeight();

  // Set bounds to absolute coordinates
  if (_superView)
  {
    this->setBounds( CGRect(
      _superView->getBounds().getX() + x,
      _superView->getBounds().getY() + y,
      width,
      height) );
  }
  else if (_isTopView)
  {
    // Bounds may remain the same, are probably being set from a controller of some sort
  }
  else
  {
    // Something may be amiss, issue a warning, but continue undeterred
    cerr << "Warning:\tSomething may be amiss. The superview is undefined, but this view is not marked as the top of its hierarchy." << endl;
  }
  
  
  // Draw this view
  //
  drawRectWithColor(this->getBounds(), this->getColor());

  // Iterate over and draw subviews
  callDrawOnSubViews();
  // Restore bounds rectangle to relative coordinates
  this->setBounds( CGRect(x, y, width, height) );
}

void View::callDrawOnSubViews()
{
  if (_subViews.size() > 0) // no point in trying to draw nothing
  {
    for (set<View *>::iterator it = _subViews.begin(); it != _subViews.end(); ++it)
    {
      (*it)->draw();
    }
  }
}




