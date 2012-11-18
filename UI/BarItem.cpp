#include "BarItem.h"
#include "CommonGLFunctions.h"
#include "TextRenderView.h"

#include <iostream>
using namespace std;

BarItem::BarItem(string title, BarItem * prev, BarItem * nxt, 
  int width, int height)
  : View( CGRect(0, 0, width, height) )
{
  _title = title;
  _previous = prev;
  _next = nxt;

  // Add a TextRenderView subview with the title
  TextRenderView * tempPtr = new TextRenderView( 
    CGRect(0, 0, width, height),
    CGColor(1.0, 1.0, 1.0, 1.0),
    title );
  this->addSubView( tempPtr );
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

void BarItem::setState(BarItemState state)
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

  //CGColor borderColor = CGColor(0.0, 0.0, 0.0, 1.0);
  CGColor start = CGColor();
  CGColor end = CGColor();
  CGColor borderStart = CGColor(0.9, 0.9, 0.9, 1.0);
  CGColor borderEnd = CGColor(0.3, 0.3, 0.3, 1.0);
  // Draw this view 
  if (ACTIVE == this->getState())
  {

    this->setBackgroundColor( CGColor(0.2, 0.8, 0.2, 1.0) ); // greenish
    CGColor test = this->getColor();

    //borderColor = CGColor(0.8, 0.0, 0.0, 1.0);
    start.setColorWithHSB((212.0/360.0), 0.0, 0.9);
    end.setColorWithHSB((212.0/360.0), 0.0, 0.15);
    borderStart = CGColor(1.0, 1.0, 1.0, 1.0);
    borderEnd = CGColor(0.4, 0.4, 0.4, 1.0);

    cerr << _title << endl;
    cerr << "ACTIVE" << endl;
    cerr << (test.getRed()) << " " << (test.getGreen()) << " " << (test.getBlue()) << " " << (test.getAlpha()) << endl;

  }
  else if (INACTIVE == this->getState())
  {
    this->setBackgroundColor( CGColor(0.8, 0.8, 0.2, 1.0) ); // yellowish
    start.setColorWithHSB((212.0/360.0), 0.0, 0.0);
    end.setColorWithHSB((212.0/360.0), 0.0, 0.1);
    CGColor test = this->getColor();

    cerr << _title << endl;
    cerr << "INACTIVE" << endl;
    cerr << (test.getRed()) << " " << (test.getGreen()) << " " << (test.getBlue()) << " " << (test.getAlpha()) << endl;
  }
  else
  {
    cerr << "NEITHER" << endl;
  }
  //drawRectWithColor(this->getBounds(), this->getColor());
  // Border Rect
  drawLinearGradient(
    this->getBounds(),
    borderStart,
    borderEnd );
  // Inner Rect
  drawLinearGradient(
    this->getBounds().getInset(1),
    start,
    end );
  //drawBorderWithColor(this->getBounds(), borderColor);
  // Draw subviews
  callDrawOnSubViews();
}