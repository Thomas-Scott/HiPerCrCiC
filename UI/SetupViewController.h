#ifndef _Setup_View_Controller_h_
#define _Setup_View_Controller_h_

#include "ViewController.h"
#include "TitledTextInputView.h"
#include "TitledToggleButton.h"
#include "Button.h"
#include "ScrollView.h"
#include "TextInputScrollView.h"

class SetupViewController : public ViewController
{
private:
  /*
Stuff needed:
  load from .cfg button
  save to .cfg button
  Allowed Domains TitledTextInputView, All TitledToggleButton
  Blacklisted Domains ""
  Start Page ""
  Max page count ""
  Use default cleaning TitledToggleButton
  Use default indexing TitledToggleButton
  Start button
  */
  TitledTextInputView * _allowedDomains;
  TitledTextInputView * _blacklistedDomains;
  TitledTextInputView * _startPage;
  TitledTextInputView * _maxPageCount;
  TitledToggleButton * _cleaningToggle;
  TitledToggleButton * _indexingToggle;
  Button * _loadFromCfg;
  Button * _saveToCfg;
  Button * _startJob;
  ScrollView * _testSV;
  TextInputScrollView * _testTISV;
public:

private:
  void init();

public:
  SetupViewController();
  // TODO: copy const
  virtual ~SetupViewController();

};

#endif // _Setup_View_Controller_h_