// Michael Taufen 2012
#include "ClippedTextView.h"
#include "CommonGLFunctions.h"

ClippedTextView::ClippedTextView(CGRect const& rect, CGColor const& textColor, string content)
  : TextRenderView(rect,textColor,content) {}

ClippedTextView::~ClippedTextView(){}

void ClippedTextView::draw()
{
  CGRect gB = this->getGlobalBounds();
  CGRect previousClippingRect(getClippingRect());
  setClippingRect( getSubClippingRect(gB) );
  // renders with no background, only text
  drawStringWithColorAndFormat(
    this->getContent(),
    this->getTextColor(),
    CGPoint( gB.getX() + 10, gB.getY() + gB.getHeight()/2), "small");

  // Restore the previous clipping rect
  setClippingRect(previousClippingRect);
  callDrawOnSubViews();
}