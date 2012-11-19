#ifndef _Button_h_
#define _Button_h_

#include "TextRenderView.h"

class Button : public View
{
private: //v
  CGColor * _downColor;
  CGColor * _upColor;
  CGColor * _overColor;
  TextRenderView * _titleView;


public: //v

private: // m

public: // m
  Button(string title,
    CGRect const& rect = CGRect(0,0,100,50),
    CGColor const& up = CGColor(0.8,0.8,0.8,1.0),
    CGColor const& down = CGColor(0.2,0.2,0.6,1.0),
    CGColor const& over = CGColor(0.6,0.6,0.6,1.0),
    CGColor const& textColor = CGColor(1.0,1.0,1.0,1.0));
  // TODO: copy const
  virtual ~Button();

  virtual bool onMouseDown(CGPoint const& pos);
  virtual bool onMouseUp(CGPoint const& pos);
  virtual bool onLeftClick(CGPoint const& pos);
  virtual bool onMouseOver(CGPoint const& pos);

};

#endif // _Button_h_