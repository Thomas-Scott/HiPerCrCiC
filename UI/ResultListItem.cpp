#include "ResultListItem.h"
#include "CommonGLFunctions.h"
#include "GlobalState.h"
#include <iostream>
#include <sstream>
#include <fstream>

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

  _viewer = 0;

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
  if (this->getGlobalBounds().isInside(pos))
  {
    if (_viewer)
    {
      string data;
      ifstream file(_result->getFilename().c_str());

      if ( file.fail() )
      {
        data = "File could not be opened.";
      }
      else
      {
        data = string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
      }
      
      //file.close();
    
      _viewer->setContent(data);
      _viewer->setForceToBottom(true);
      GlobalState::forceRedraw = true;
    }
    else
    {
      cerr << "Viewer not set." << endl;
    }
    return true;
  }
  else
  {
    return false;
  }
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