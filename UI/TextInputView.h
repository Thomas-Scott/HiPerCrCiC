#ifndef _Text_Input_View_h_
#define _Text_Input_View_h_

#include "View.h"
#include <string>
#include <vector>

class TextInputView : public View
{
private:
  int _lineSpacing; // space between lines in pixels
  string _content;
  vector<string> _lines; // for rendering, splits the strings into lines based on the width of the box
  CGColor * _textColor;
public:

private:

public:
  TextInputView(CGRect const& rect = CGRect(0,0,400,100), CGColor const& textColor = CGColor(0.0, 0.0, 0.0, 1.0), CGColor const& bgColor = CGColor(1.0, 1.0, 1.0, 1.0));
  TextInputView( TextInputView const& view );
  virtual ~TextInputView();

  // TODO, override handlers to allow focus
  // handlers
  virtual bool onLeftClick(CGPoint const& pos);
  virtual void onFocusIn();
  virtual void onFocusOut();

  //virtual void draw();


};

#endif // _Text_Input_View_h_