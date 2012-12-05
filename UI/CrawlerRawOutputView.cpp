#include "CrawlerRawOutputView.h"
#include "GlobalState.h"

CrawlerRawOutputView::CrawlerRawOutputView(CGRect const& rect) : TextInputScrollView(rect)
{
  registerSelfAsCrawlerListener();
  getDynamicTextInputView()->removeSelfAsKeyboardListener();
  getDynamicTextInputView()->removeSelfAsMouseListener();
}

CrawlerRawOutputView::~CrawlerRawOutputView()
{
  removeSelfAsCrawlerListener();
}

void CrawlerRawOutputView::onCrawlerUpdate(string data)
{
  DynamicTextInputView * iV = getDynamicTextInputView();
  string content = iV->getContent();
  content += data;
  iV->setContent(content);
  GlobalState::forceRedraw = true;
}