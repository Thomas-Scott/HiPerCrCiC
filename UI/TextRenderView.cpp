// Michael Taufen 2012
#include "CommonGLFunctions.h"
#include "TextRenderView.h"
#include <iostream>

TextRenderView::TextRenderView(CGRect const& rect, CGColor const& textColor, string content) 
  : View(rect), _textColor(textColor)
{
  _content = content;
}

TextRenderView::TextRenderView(TextRenderView const& view) : View(view), _textColor(view.getTextColor())
{
  _content = view.getContent();
}

TextRenderView::~TextRenderView()
{

}

void TextRenderView::draw()
{
  // renders with no background, only text
  drawStringWithColorAndFormat(
    this->getContent(),
    this->getTextColor(),
    CGPoint( this->getGlobalBounds().getX() + 10, this->getGlobalBounds().getY() + this->getBounds().getHeight()/2) );
  // cerr << "Color Red" << this->getTextColor().getRed() << endl;
  // cerr << "should have drawn text" << endl;

  callDrawOnSubViews();

}
