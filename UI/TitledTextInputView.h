#ifndef _Titled_Text_Input_View_h
#define _Titled_Text_Input_View_h

#include "View.h"
#include "TextRenderView.h"
#include "TextInputView.h"

class TitledTextInputView : public View
{
private: // v
  TextRenderView * titleView;
  TextInputView * textView;

public: // v

private: // m

public: // m
  TitledTextInputView();
  // TODO: add copy constructor
  ~TitledTextInputView();

  

};

#endif // _Titled_Text_Input_View_h