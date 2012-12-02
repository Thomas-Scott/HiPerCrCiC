#include "Button.h"
#include "GlobalState.h"
#include <iostream>

void (Button::*onClickCallback)() = 0;

Button::Button(string title, CGRect const& rect, CGColor const& up, CGColor const& down, CGColor const& over, CGColor const& textColor) : View(rect)
{
  _titleView = new TextRenderView(CGRect(0,0,rect.getWidth(),rect.getHeight()), textColor, title);
  _upColor = new CGColor(up);
  _downColor = new CGColor(down);
  _overColor = new CGColor(over);
  this->setBackgroundColor(*_upColor);
  registerSelfAsMouseListener();
  addSubView(_titleView);
  _hasHover = false;
}

Button::~Button()
{
  removeSelfAsMouseListener();
  delete _upColor;
  delete _downColor;
  delete _overColor;
  delete _titleView;
}

bool Button::onMouseDown(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos))
  {
    this->setBackgroundColor(*_downColor);
    GlobalState::forceRedraw = true;
    return true;
  }
  else
  {
    return false;
  }
}

bool Button::onMouseUp(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos))
  {
    this->setBackgroundColor(*_overColor);
    GlobalState::forceRedraw = true;
    return true;
  }
  else
  {
    this->setBackgroundColor(*_upColor);
    GlobalState::forceRedraw = true;
    return false;
  }
}

bool Button::onLeftClick(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos))
  {
    if (_onClickCallback)
    {
      _onClickCallback();
    }
    return true;
  }
  else
  {
    return false;
  }
}

bool Button::onMouseOver(CGPoint const& pos)
{
  if (this->getGlobalBounds().isInside(pos))
  {
    this->setBackgroundColor(*_overColor);
    _hasHover = true;
    GlobalState::forceRedraw = true;
    return false; // return false here so that other buttons can recieve
    // the onMouseOver event and cancel their hover if the mouse moves too
    // quickly to another button
  }
  else
  {
    this->setBackgroundColor(*_upColor);
    _hasHover = false;
    GlobalState::forceRedraw = true;
    return false;
  }
}

void Button::setOnClickCallback(void(*functionPtr)())
{
  _onClickCallback = functionPtr;
}
