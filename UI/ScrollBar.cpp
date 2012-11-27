#include "ScrollBar.h"
#include "CommonGLFunctions.h"
#include "GlobalState.h"
#include <iostream>


<<<<<<< HEAD
=======
void VertScrollBar::bind(float &val, int low, int high)
{
  if (val < low)
    val = low;
  else if (val > high)
    val = high;
}

>>>>>>> ui-dev
void VertScrollBar::bind(int &val, int low, int high)
{
  if (val < low)
    val = low;
  else if (val > high)
    val = high;
}

VertScrollBar::VertScrollBar(CGRect const& rect) : View(rect)
{
<<<<<<< HEAD
 _currentValue = 0;
 _range = 1; // TODO: set to 0 initially, so scrollbar only appears when view is bigger than clipping rect
=======
  _isDragging = false;
 _currentValue = 0;
 _range = 1;
 _scaleLow = 0;
 _scaleHigh = rect.getHeight();
>>>>>>> ui-dev
 this->registerSelfAsMouseListener();
}

VertScrollBar::~VertScrollBar()
{
  this->removeSelfAsMouseListener();
}

<<<<<<< HEAD

bool VertScrollBar::onMouseDrag(CGPoint const& pos)
{
  cerr << "got drag" << endl;
  if (this->getGlobalBounds().isInside(pos))
  {
    cerr << "and drag in bounds" << endl;
    
    float fractionalPos = ( (float)(pos.getY()) / (float)(this->getBounds().getHeight()) );
    
=======
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

>>>>>>> ui-dev
    if (_range == 1)
      _currentValue = 0;
    else
      _currentValue = fractionalPos * _range;

<<<<<<< HEAD
    cerr << "range: " << _range << " current value: " << _currentValue << endl;
=======
>>>>>>> ui-dev
    GlobalState::forceRedraw = true;
    return true;
  }
  else
  {
    return false;
  }
<<<<<<< HEAD
=======

>>>>>>> ui-dev
}

void VertScrollBar::draw()
{

  /*
    The vertical position of the scrollHook is based off of its upper left corner
    therefore, it is at max position when the upper left corner is at max position,
    which means the maximum distance the hook can move is the height of the scale
    minus the height of the hook
  */
<<<<<<< HEAD

  // Draw the bar itself
  drawRectWithColor(this->getGlobalBounds(), CGColor(0.7,0.7,0.7,1.0));
  // Draw the thing you "grab"
  int x = this->getGlobalBounds().getX();
  int y = this->getGlobalBounds().getY() + ((_currentValue / _range) * this->getBounds().getHeight());
  int width = 20; //px
  int height = this->getBounds().getHeight() / _range;
  height = 200;

  drawRectWithColor(CGRect(x, y, width, height), CGColor(0.3,0.3,0.3,1.0));
=======
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
>>>>>>> ui-dev

}


