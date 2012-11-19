#ifndef _Titled_Text_Input_View_h
#define _Titled_Text_Input_View_h

#include "TextRenderView.h"
#include "TextInputView.h"

using namespace std;

class TitledTextInputView : public View
{
private: // v
  TextRenderView * _titleView;
  TextInputView * _textInputView;

public: // v

private: // m

public: // m
  TitledTextInputView(string title, CGRect const& rect = CGRect(0, 0, 400, 150));
  // TODO: add copy constructor
  virtual ~TitledTextInputView();

  TextRenderView * getTitleView() { return _titleView; }
  TextInputView * getTextInputView() { return _textInputView; }

  virtual void draw();
};

#endif // _Titled_Text_Input_View_h