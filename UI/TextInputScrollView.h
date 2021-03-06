// Michael Taufen 2012
#ifndef _Text_Input_Scroll_View_h_
#define _Text_Input_Scroll_View_h_

#include "ScrollView.h"
#include "DynamicTextInputView.h"

class TextInputScrollView : public ScrollView
{
private:
  DynamicTextInputView * _textInputView;
  string _prevContent; // for scrolling to bottom on content change
public:
private:
public:
  TextInputScrollView(CGRect const& rect);
  virtual ~TextInputScrollView();
  
  DynamicTextInputView * getDynamicTextInputView(){return _textInputView;}
  virtual void draw();
};


#endif // _Text_Input_Scroll_View_h_