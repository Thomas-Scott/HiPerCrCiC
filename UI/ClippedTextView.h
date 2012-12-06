#ifndef _Clipped_Text_View_
#define _Clipped_Text_View_

#include "TextRenderView.h"

class ClippedTextView : public TextRenderView
{
public:
  ClippedTextView(CGRect const& rect, CGColor const& textColor, string content);
  virtual ~ClippedTextView();
  virtual void draw();
};

#endif //_Clipped_Text_View_