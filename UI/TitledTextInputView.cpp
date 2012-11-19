#include "TitledTextInputView.h"

TitledTextInputView::TitledTextInputView(string title, CGRect const& rect) : View(rect)
{
  _titleView = new TextRenderView(
    CGRect(0,0,rect.getWidth(),40),
    CGColor(1.0, 1.0, 1.0, 1.0),
    title );
  _textInputView = new TextInputView(
    CGRect(0,42,rect.getWidth(),rect.getHeight()-42) );

  _titleView->setTextColor(CGColor(0.0,0.0,0.0,1.0));
  _titleView->setBackgroundColor(CGColor(0.0,0.0,0.0,0.0)); // transparent

  this->addSubView(_titleView);
  this->addSubView(_textInputView);
}

TitledTextInputView::~TitledTextInputView()
{
  // subviews are deleted by View's destructor
}

void TitledTextInputView::draw()
{
  CGRect rect = this->getBounds();
  _textInputView->setBounds(CGRect(0,42,rect.getWidth(),rect.getHeight()-42));
  callDrawOnSubViews();
}