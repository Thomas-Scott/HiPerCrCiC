#ifndef _Titled_Toggle_Button_h_
#define _Titled_Toggle_Button_h_


#include "TextRenderView.h"
#include "ToggleButton.h"
#include "GlobalState.h"

class TitledToggleButton : public View
{
private:
  TextRenderView * _titleView;
  ToggleButton * _toggleButton;
public:

private:

public:
  TitledToggleButton(string title);
  // TODO: cpy cnst
  ~TitledToggleButton();

  TextRenderView * getTitleView() { return _titleView; }
  ToggleButton * getToggleButton() { return _toggleButton; }

  virtual void draw();
};

#endif // _Titled_Toggle_Button_h_