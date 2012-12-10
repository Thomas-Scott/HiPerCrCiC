// Michael Taufen 2012
#ifndef _Dynamic_Text_Input_View_h_
#define _Dynamic_Text_Input_View_h_
// TODO: test this first, then rewrite to inherit from TextInputView and override or hide the affected methods, and add the _minHeight variable
// A TextInputView that resizes vertically based on the amount of text inside it
#include "View.h"
#include <vector>
class DynamicTextInputView : public View
{
private:
  int _lineSpacing; // space between lines in pixels
  string _content;
  string::iterator _cursorPos;
  vector<string> _lines; // for rendering, splits the strings into lines based on the width of the box
  CGColor * _textColor;
  int _minHeight;
public:
private:
public:
  DynamicTextInputView(CGRect const& rect = CGRect(0,0,400,100), CGColor const& textColor = CGColor(0.0, 0.0, 0.0, 1.0), CGColor const& bgColor = CGColor(1.0, 1.0, 1.0, 1.0));
  DynamicTextInputView( DynamicTextInputView const& view );
  virtual ~DynamicTextInputView();

  CGColor getTextColor() const { return *_textColor; }
  void setTextColor(CGColor const& color);

  string getContent() const { return _content; }
  void setContent(string content) { _content = content; }

  string::iterator getCursorPos() const { return _cursorPos; }
  void setCursorPos(string::iterator pos) { _cursorPos = pos; }

  int getLineSpacing() { return _lineSpacing; }
  void setLineSpacing(int ls) { _lineSpacing = ls; }

  int getMinHeight() const {return _minHeight;}
  void setMinHeight(int val) {_minHeight = val;}

  int getMaxCharsPerLine() const;
  int getContentHeight() const;

  // TODO, override handlers to allow focus
  // handlers
  virtual bool onLeftClick(CGPoint const& pos);
  virtual void onFocusIn();
  virtual void onFocusOut();
  virtual bool onKeyDown(unsigned char const& key);

  virtual void draw();

};

#endif //_Dynamic_Text_Input_View_h_