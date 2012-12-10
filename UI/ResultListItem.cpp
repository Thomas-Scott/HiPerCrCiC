#include "ResultListItem.h"
#include "CommonGLFunctions.h"
#include <sstream>

ResultListItem::ResultListItem(ResultInfo * result, CGRect const& rect) : View(rect)
{
  _result = result;

  CGRect bounds(rect);
  bounds.setX(0);
  bounds.setY(0);

  bounds.setWidth(0.66*rect.getWidth());
  _resultName = new ClippedTextView(bounds, CGColor(0,0,0,1), result->getFilename());
  addSubView(_resultName);

  bounds.setWidth(0.33*rect.getWidth());
  bounds.setX(0.66*rect.getWidth());

  stringstream ss;
  ss << result->getHits();
  _hits = new ClippedTextView(bounds, CGColor(0,0,0,1), ss.str());
  addSubView(_hits);

  registerSelfAsMouseListener();
}

ResultListItem::~ResultListItem()
{
  removeSelfAsMouseListener();
  delete _result;
  delete _resultName;
  delete _hits;
}

bool ResultListItem::onLeftClick(CGPoint const& pos)
{
  // open the result in the viewer
  return false;
}

void ResultListItem::draw()
{
  CGRect gB = this->getGlobalBounds();
  // Draw background and border
  drawRectWithColor(gB, CGColor(0.97,0.97,0.97,1.0));
  drawBorderWithColor(gB, CGColor(1.0,1.0,1.0,1.0));
  // Draw subviews
  callDrawOnSubViews();
}