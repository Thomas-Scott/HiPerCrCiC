#include "ProgressBar.h"
#include "CommonGLFunctions.h"

ProgressBar::ProgressBar(CGRect const& rect, CGColor const& fgC, CGColor const& bgC)
  : View(rect, bgC)
{
  _foregroundColor = new CGColor(fgC);
}

ProgressBar::~ProgressBar()
{
  delete _foregroundColor;
}

void ProgressBar::draw()
{
  CGRect gB = this->getGlobalBounds();
  drawRectWithColor(gB, this->getColor());
  
  // draw the progress bar rectangle
  drawRectWithColor(CGRect(gB.getX(),gB.getY(),gB.getWidth()*_percentComplete, gB.getHeight()), 
    *_foregroundColor);
  // draw a border
  drawBorderWithColor(gB, CGColor(0.0,0.0,0.0,1.0));

  // no subviews to call draw on
}