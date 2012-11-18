#include "TextInputView.h"
#include "GlobalState.h"
#include <iostream>

TextInputView::TextInputView(CGRect const& rect, CGColor const& textColor, CGColor const& bgColor)
  : View(rect, bgColor)
{
  _textColor = new CGColor(textColor);
  this->setFocusable(true);
  CGColor temp( this->getColor() );
  temp.setColorWithHSB(temp.getHue(), temp.getSaturation(), 0.0);
  this->setBackgroundColor(temp);
}
TextInputView::TextInputView( TextInputView const& view )
{

}
TextInputView::~TextInputView()
{

}

bool TextInputView::onLeftClick(CGPoint const& pos)
{
  cerr << "text box" << ": onLeftClick recieved" << endl;
  // Simply needs to report that it handled the click, everything else is focus based
  if (this->getGlobalBounds().isInside(pos))
  {
    cerr << "was inside bounds" << endl;
    return true;
  }
  else
  {
    return false;
  }
}

void TextInputView::onFocusIn()
{
  // set hasFocus to true, raise brigtness
  cerr << "text box getting focus" << endl;
  this->setHasFocus(true);
  CGColor temp( this->getColor() );
  temp.setColorWithHSB(temp.getHue(), temp.getSaturation(), 1.0);
  this->setBackgroundColor(temp);
  // let global state know we should force a redraw of this section
  GlobalState::forceRedraw = true;
}

void TextInputView::onFocusOut()
{
  // set hasFocus to true, lower brigtness
  cerr << "text box losing focus" << endl;
  this->setHasFocus(false);
  CGColor temp( this->getColor() );
  temp.setColorWithHSB(temp.getHue(), temp.getSaturation(), 0.97);
  this->setBackgroundColor(temp);
  // let global state know we should force a redraw of this section
  GlobalState::forceRedraw = true;
}
/*
void TextInputView::draw()
{

}
*/