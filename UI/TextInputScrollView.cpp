// Michael Taufen 2012
#include "TextInputScrollView.h"

TextInputScrollView::TextInputScrollView(CGRect const& rect) : ScrollView(rect)
{
  _textInputView = new DynamicTextInputView(getContentView()->getBounds());

  // CAREFULLY! replace the content view with the text input view
  removeSubViewWithPointer(getContentView()); // also deletes the content view from memory
  setContentView(_textInputView);
  addSubView(getContentView());
  _textInputView->setContent("");
  _prevContent = _textInputView->getContent();
}

TextInputScrollView::~TextInputScrollView()
{
  // DO NOT DELETE _textInputView here because it is the content view,
  // and it is deleted in the super class!!!!!!!!!!!!!!!
}

void TextInputScrollView::draw() 
{
  if (_prevContent != _textInputView->getContent())
  {
    // then the content has changed, force scroll to bottom
    setForceToBottom(true);
    _prevContent = _textInputView->getContent();
  }
  ScrollView::draw();
  setForceToBottom(false);
}