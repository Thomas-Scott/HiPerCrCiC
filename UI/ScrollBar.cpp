#include "ScrollBar.h"
#include "CommonGLFunctions.h"
#include "GlobalState.h"
#include <iostream>


void VertScrollBar::bind(float &val, int low, int high)
{
  if (val < low)
    val = low;
  else if (val > high)
    val = high;
}

void VertScrollBar::bind(int &val, int low, int high)
{
  if (val < low)
    val = low;
  else if (val > high)
    val = high;
}

VertScrollBar::VertScrollBar(CGRect const& rect) : View(rect)
{
  _isDragging = false;
 _currentValue = 0;
 _range = 1;
 _scaleLow = 0;
 _scaleHigh = rect.getHeight();
 this->registerSelfAsMouseListener();
}

VertScrollBar::~VertScrollBar()
{
  this->removeSelfAsMouseListener();
}

void VertScrollBar::calculateScale()
{
  float totalHeight = this->getBounds().getHeight();
  _scrollerHeight = (totalHeight / _range) * totalHeight;
  bind(_scrollerHeight, 20, totalHeight);
  _scaleLow = _scrollerHeight / 2;
  _scaleHigh = totalHeight - _scaleLow;
  cerr << "low,high,height: " << _scaleLow << endl;
  cerr << "low,high,height: " << _scaleHigh << endl;
  cerr << "low,high,height: " << _scrollerHeight << endl;
}

bool VertScrollBar::onMouseDown(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos))
  {
    _isDragging = true;
    float localMouseY = pos.getY() - this->getGlobalBounds().getY();
    
    // figure out the scale low and sclae high based on the range
    calculateScale();

    bind(localMouseY, _scaleLow, _scaleHigh);

    float fractionalPos = (localMouseY - _scaleLow) / (float)(_scaleHigh - _scaleLow);

    if (_range == 1)
      _currentValue = 0;
    else
      _currentValue = fractionalPos * _range;

    GlobalState::forceRedraw = true;
    return true;
  }
  else
  {
    return false;
  }
}

bool VertScrollBar::onMouseUp(CGPoint const& pos)
{
  _isDragging = false;
  return false;
}

bool VertScrollBar::onMouseDrag(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos) && _isDragging)
  {
    float localMouseY = pos.getY() - this->getGlobalBounds().getY();
    
    // figure out the scale low and sclae high based on the range
    calculateScale();

    bind(localMouseY, _scaleLow, _scaleHigh);

    float fractionalPos = (localMouseY - _scaleLow) / (float)(_scaleHigh - _scaleLow);

    if (_range == 1)
      _currentValue = 0;
    else
      _currentValue = fractionalPos * _range;

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
  // slider scale is center start to center end
  calculateScale();
  // Draw the bar itself

  drawRectWithColor(this->getGlobalBounds(), CGColor(0.3,0.3,0.3,1.0));

  // Draw the thing you "grab"
  int x = this->getGlobalBounds().getX();
  // for y we do the center position of the scroller minus half the scroller height
  

  int localCenterY = _scaleLow + (_scaleHigh - _scaleLow)*(_currentValue/_range);
  int y = this->getGlobalBounds().getY() + (localCenterY - _scrollerHeight/2);
  

  int width = 20; //px
  int height = _scrollerHeight;

  drawRectWithColor(CGRect(x, y, width, height), CGColor(0.7,0.7,0.7,1.0));

}


