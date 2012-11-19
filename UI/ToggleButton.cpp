#include "ToggleButton.h"
#include "CommonGLFunctions.h"
#include "GlobalState.h"
#include <iostream>

#ifdef MACOSX
#include <GLUT/glut.h>
#else
//#include <GL/glut.h>
#endif
#include <GLUT/glut.h> //

ToggleButton::ToggleButton() : View(CGRect(0,0,20,20))
{
  _isActive = false;
  _color = new CGColor(0.0,0.0,0.0,1.0);
  this->registerSelfAsMouseListener();
}

ToggleButton::~ToggleButton()
{
  this->removeSelfAsMouseListener();
}

void ToggleButton::toggleIsActive()
{
  if (_isActive)
  {
    _isActive = false;
  }
  else
  {
    _isActive = true;
  }
}

bool ToggleButton::onLeftClick(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos))
  {
    toggleIsActive();
    GlobalState::forceRedraw = true;
    return true;
  }
  else
  {
    return false;
  }
}

bool ToggleButton::onMouseOver(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos))
  {
    _color->setBrightness(0.7);
    GlobalState::forceRedraw = true;
    return true;
  }
  else
  {
    _color->setBrightness(0.0);
    return false;
  }
}

void ToggleButton::draw()
{
  // Draw the rect
  drawRectWithColor(this->getGlobalBounds(), this->getColor());
  // Draw the border
  drawBorderWithColor(this->getGlobalBounds(), *_color, 2);
  // Draw the check if active
  // TODO: only call globalBounds twice, once for X, once for Y
  // same for width and height
  int x = this->getGlobalBounds().getX();
  int y = this->getGlobalBounds().getY();
  int width = this->getBounds().getWidth();
  int height = this->getBounds().getHeight();
  if (_isActive)
  {
    drawRectWithColor(this->getGlobalBounds().getInset(width / 5), *_color);
  }
}