#include "BarItem.h"
#include "CommonGLFunctions.h"

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

// Handlers

bool BarItem::mouseClickHandler(CGPoint const& point)
{
  if (isInsideBounds(point))
  {
    // perform any effects related to a click here
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
  if (!_previous)
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
  drawRectWithColor(this->getBounds(), this->getColor());
  // Draw subviews
  callDrawOnSubViews();
}