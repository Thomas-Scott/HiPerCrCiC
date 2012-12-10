// Michael Taufen 2012
#ifndef _Text_Render_View_h
#define _Text_Render_View_h

#include "View.h"

class TextRenderView : public View
{
private: // private variables
  string _content;
  CGColor _textColor;

public: // public variables

private: // private methods

public: // public methods
  TextRenderView(CGRect const& rect = CGRect(0,0,200,50), CGColor const& textColor = CGColor(1.0, 1.0, 1.0, 1.0), string content = "");
  TextRenderView(TextRenderView const& view);
  virtual ~TextRenderView();

  string getContent() const { return _content; }
  void setContent(string content) {_content = content; }

  CGColor getTextColor() const { return _textColor; }
  void setTextColor(CGColor textColor) { _textColor = textColor; }

  virtual void draw();
};

#endif //_Text_Render_View_h