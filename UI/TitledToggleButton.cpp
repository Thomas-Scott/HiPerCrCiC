#include "TitledToggleButton.h"

TitledToggleButton::TitledToggleButton(string title)
{
  _titleView = new TextRenderView(CGRect(22,-10,100,50), CGColor(0.0,0.0,0.0,1.0), title);
  _toggleButton = new ToggleButton();
  _toggleButton->setBounds(CGRect(0,0,20,20));
  this->addSubView(_titleView);
  this->addSubView(_toggleButton);

} 

TitledToggleButton::~TitledToggleButton()
{

}

void TitledToggleButton::draw()
{
  callDrawOnSubViews();
}