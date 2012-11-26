#include "ScrollBar.h"
#include "CommonGLFunctions.h"
#include "GlobalState.h"
#include <iostream>


void VertScrollBar::bind(int &val, int low, int high)
{
  if (val < low)
    val = low;
  else if (val > high)
    val = high;
}

VertScrollBar::VertScrollBar(CGRect const& rect) : View(rect)
{
 _currentValue = 0;
 _range = 1; // TODO: set to 0 initially, so scrollbar only appears when view is bigger than clipping rect
 this->registerSelfAsMouseListener();
}

VertScrollBar::~VertScrollBar()
{
  this->removeSelfAsMouseListener();
}


bool VertScrollBar::onMouseDrag(CGPoint const& pos)
{
  cerr << "got drag" << endl;
  if (this->getGlobalBounds().isInside(pos))
  {
    cerr << "and drag in bounds" << endl;
    
    float fractionalPos = ( (float)(pos.getY()) / (float)(this->getBounds().getHeight()) );
    
    if (_range == 1)
      _currentValue = 0;
    else
      _currentValue = fractionalPos * _range;

    cerr << "range: " << _range << " current value: " << _currentValue << endl;
    GlobalState::forceRedraw = true;
    return true;
  }
  else
  {
    return false;
  }
}

void VertScrollBar::draw()
{

  /*
    The vertical position of the scrollHook is based off of its upper left corner
    therefore, it is at max position when the upper left corner is at max position,
    which means the maximum distance the hook can move is the height of the scale
    minus the height of the hook
  */

  // Draw the bar itself
  drawRectWithColor(this->getGlobalBounds(), CGColor(0.7,0.7,0.7,1.0));
  // Draw the thing you "grab"
  int x = this->getGlobalBounds().getX();
  int y = this->getGlobalBounds().getY() + ((_currentValue / _range) * this->getBounds().getHeight());
  int width = 20; //px
  int height = this->getBounds().getHeight() / _range;
  height = 200;

  drawRectWithColor(CGRect(x, y, width, height), CGColor(0.3,0.3,0.3,1.0));

}


