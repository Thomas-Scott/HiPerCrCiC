#ifndef _Text_Scroll_View_h_
#define _Text_Scroll_View_h_
#include "TextInputScrollView.h"

class TextScrollView : public TextInputScrollView
{
public:
  TextScrollView(CGRect const& rect);
  virtual ~TextScrollView();

  void setContent(string content);
};

#endif // _Text_Scroll_View_h_