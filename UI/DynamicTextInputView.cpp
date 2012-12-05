#include "DynamicTextInputView.h"
#include "GlobalState.h"
#include <iostream>
#include "CommonGLFunctions.h"
#include "math.h"
using namespace std;

DynamicTextInputView::DynamicTextInputView(CGRect const& rect, CGColor const& textColor, CGColor const& bgColor)
  : View(rect, bgColor)
{
  _textColor = new CGColor(textColor);
  this->setFocusable(true);
  _content = "";
  _cursorPos = _content.begin();
  _lineSpacing = 14;
  _minHeight = rect.getHeight();
  this->registerSelfAsMouseListener();
  this->registerSelfAsKeyboardListener();
}
DynamicTextInputView::DynamicTextInputView( DynamicTextInputView const& view )
{
 // TODO: Make copy constructor
}
DynamicTextInputView::~DynamicTextInputView()
{
  delete _textColor;
  this->removeSelfAsMouseListener();
  this->removeSelfAsKeyboardListener();
}

void DynamicTextInputView::setTextColor(CGColor const& color)
{
  delete _textColor;
  _textColor = new CGColor(color);
}

bool DynamicTextInputView::onLeftClick(CGPoint const& pos)
{
  // Simply needs to report that it handled the click, everything else is focus based
  if (this->getGlobalBounds().isInside(pos))
  {
    return true;
  }
  else
  {
    return false;
  }
}

void DynamicTextInputView::onFocusIn()
{
  // set hasFocus to true
  //cerr << "got" << endl;
  this->setHasFocus(true);
  // let global state know we should force a redraw
  GlobalState::forceRedraw = true;
}

void DynamicTextInputView::onFocusOut()
{
  // set hasFocus to true
  //cerr << "lost" << endl;
  this->setHasFocus(false);

  // let global state know we should force a redraw
  GlobalState::forceRedraw = true;
}

bool DynamicTextInputView::onKeyDown(unsigned char const& key)
{
  if ( !getHasFocus() )
  {
    return false;
  }
  else if ( 32 <= key && key <= 126 )
  {
    _content += key;
    return true;
  }
  else
  {
    switch (key)
    {
      case 8:
        //backspace
        //cerr << "backspace" << endl;
        if (_content.length() > 0)
        {
          string::iterator it = _content.end();
          --it;
          _content.erase(it);
        }
        break;

      case 127:
        // delete implemented as backspace because on Mac OSX, the backspace 
        // key (delete) sends the ascii value for delete (127), 
        // whereas fn+delete, which simulates the forward
        // deletion property of a linux or windows keyborad, 
        // sends the ascii value for backspace (8)
        //cerr << "delete" << endl;
        if (_content.length() > 0)
        {
          string::iterator it = _content.end();
          --it;
          _content.erase(it);
        }
        break;
      case 13: // Carriage Return
        _content += '\n';
        break;
      default:
        break;
    }
    return true;
  }
}

// we are using a fixed width 8x13 font
int DynamicTextInputView::getMaxCharsPerLine() const
{
  return (this->getBounds().getWidth() - 10) / 8;
}

int DynamicTextInputView::getContentHeight() const 
{
  // character height is 13 pixels
  // return lines * (character height + space BETWEEN lines)
  // ^ the number of lines calculated in the last draw call
  //float lines =  (_content.length() / getMaxCharsPerLine()) + 1; // old way
  int lines = _lines.size();
  int height = lines * (13 + (_lineSpacing - 13));
  return  height + 6;
}

void DynamicTextInputView::draw()
{

  // Split all the lines first, then calculate height based on the number of lines


  
  // Split up and draw the text based on the width of the rectangle
  // 
  _lines.empty(); // start anew
  _lines.resize(0);
  string temp = "";
  int cnt = 0;
  const int maxChars = getMaxCharsPerLine();

  for (string::iterator it = _content.begin(); it != _content.end(); ++it)
  {
    temp += (*it);
    cnt++;
    if (cnt >= maxChars || (*it) == '\n')
    {
      _lines.push_back(temp);
      temp.clear();
      cnt = 0;
    }
  }
  // add a cursor if has focus
  // Currently the cursor is always at the end,
  // this will change when we make it so that the
  // position can be set with a mouse click or the
  // arrow keys
  if ( getHasFocus() )
  {
    if (temp.length() > 0)
    {
      temp += "~"; // there is more to push, so stick the cursor on the last line
    }
  }
  _lines.push_back(temp); // push the rest



  // Set the bounds based on number of lines calculated
  CGRect newBounds(this->getBounds());
  
  if (getContentHeight() >= _minHeight)
    newBounds.setHeight(getContentHeight());
  else
    newBounds.setHeight(_minHeight);

  this->setBounds(newBounds);

  // Draw the rect
  drawRectWithColor(this->getGlobalBounds(), this->getColor());

  // Draw the lines of text
  CGRect bounds = this->getGlobalBounds();
  int x = bounds.getX() + 5;
  int y = bounds.getY() + 14;

  for(vector<string>::iterator it = _lines.begin(); it != _lines.end(); ++it)
  {
    drawStringWithColorAndFormat(
      (*it), this->getTextColor(), CGPoint( x, y), "small fixed");
    y += this->getLineSpacing();
  }

  // Draw the border
  if (getHasFocus())
    drawBorderWithColor(bounds, CGColor(0.0,0.0,0.6,1.0));
  else
    drawBorderWithColor(bounds, CGColor(0.0,0.0,0.0,1.0));

  // Draw the subviews
  this->callDrawOnSubViews();

}
