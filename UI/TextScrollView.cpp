#include "TextScrollView.h"
#include "GlobalState.h"

TextScrollView::TextScrollView(CGRect const& rect) : TextInputScrollView(rect)
{
  registerSelfAsCrawlerListener();
  getDynamicTextInputView()->removeSelfAsKeyboardListener();
  getDynamicTextInputView()->removeSelfAsMouseListener();
}

TextScrollView::~TextScrollView()
{
  removeSelfAsCrawlerListener();
}

void TextScrollView::setContent(string content)
{
  DynamicTextInputView * iV = getDynamicTextInputView();
  iV->setContent(content);
  GlobalState::forceRedraw = true;
}