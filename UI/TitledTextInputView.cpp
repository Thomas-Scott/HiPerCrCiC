#include "TitledTextInputView.h"

TitledTextInputView::TitledTextInputView(string title, CGRect const& rect) : View(rect)
{
  _titleView = new TextRenderView(
    CGRect(0,0,rect.getWidth(),50),
    CGColor(1.0, 1.0, 1.0, 1.0),
    title );
  _textInputView = new TextInputView(
    CGRect(0,52,rect.getWidth(),rect.getHeight()-52) );

  _titleView->setTextColor(CGColor(0.0,0.0,0.0,1.0));

  this->addSubView(_titleView);
  this->addSubView(_textInputView);
}

TitledTextInputView::~TitledTextInputView()
{

}