#include "BarItem.h"
#include "CommonGLFunctions.h"

#include <iostream>
using namespace std;

BarItem::BarItem(string title, BarItem * prev, BarItem * nxt, 
  int width, int height)
  : View( CGRect(0, 0, width, height) )
{
  _title = title;
  _previous = prev;
  _next = nxt;
}

BarItem::~BarItem()
{

}

void BarItem::setPrevious(BarItem * item)
{
  _previous = item;
}

void BarItem::setNext(BarItem * item)
{
  _next = item;
}

void BarItem::setTitle(string t)
{
  _title = t;
}

void BarItem::setState(State state)
{
  _state = state;
}

// Special functions
void BarItem::deactivateRest()
{
  if(!_previous) // this is first element
  {
    deactivateForward();
  }
  else if(!_next) // this is last element
  {
    deactivateBackward();
  }
  else // this is somewhere in the middle
  {
    deactivateForward();
    deactivateBackward();
  }
}

void BarItem::deactivateForward()
{
  if(_next)
  {
    _next->setState(INACTIVE);
    _next->deactivateForward();
  }
}

void BarItem::deactivateBackward()
{
  if(_previous)
  {
    _previous->setState(INACTIVE);
    _previous->deactivateBackward();
  }
}

// Handlers

bool BarItem::mouseClickHandler(CGPoint const& point)
{
  if ( isInsideBounds(point) )
  {
    // perform any effects related to a click here
    this->setState( ACTIVE );
    deactivateRest();
    return true;
  }
  else
  {
    return false;
  }
}

// Render Code

void BarItem::draw()
{
  // TODO: Separate these into update and draw functions
  // if not first bar item in list, set position based on previous bar item
  if (_previous)
  {
    CGRect newBounds( _previous->getBounds() );
    newBounds.setX( newBounds.getX() + newBounds.getWidth() );
    newBounds.setWidth( this->getBounds().getWidth() );
    newBounds.setHeight( this->getBounds().getHeight() );
    this->setBounds( newBounds );
  }
  else // otherwise set position to the bottom left of the superview
  {
    View * superView = getSuperView();
    CGRect newBounds( superView->getBounds() );
    newBounds.setWidth( this->getBounds().getWidth() );
    newBounds.setHeight( this->getBounds().getHeight() );
    this->setBounds( newBounds );
  }

  // Draw this view 
  if (ACTIVE == this->getState())
  {
    cout << _title << endl;
    cout << "ACTIVE" << endl;
    this->setBackgroundColor( CGColor(0.2, 0.8, 0.2, 1.0) ); // greenish
    CGColor test = this->getColor();
    cout << (test.getRed()) << " " << (test.getGreen()) << " " << (test.getBlue()) << " " << (test.getAlpha()) << endl;
  }
  else if (INACTIVE == this->getState())
  {
    cout << _title << endl;
    cout << "INACTIVE" << endl;
    this->setBackgroundColor( CGColor(0.8, 0.8, 0.2, 1.0) ); // yellowish
    CGColor test = this->getColor();
    cout << (test.getRed()) << " " << (test.getGreen()) << " " << (test.getBlue()) << " " << (test.getAlpha()) << endl;
  }
  else
  {
    cout << "NEITHER" << endl;
  }
  drawRectWithColor(this->getBounds(), this->getColor());
  // Draw subviews
  callDrawOnSubViews();
}