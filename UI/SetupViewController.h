#ifndef _Setup_View_Controller_h_
#define _Setup_View_Controller_h_

#include "ViewController.h"
#include "TextRenderView.h"
#include "TitledToggleButton.h"
#include "Button.h"
#include "TitledTextInputView.h"
#include "TextInputScrollView.h"
#include "../core/Crawler.h"

class SetupViewController : public ViewController
{
private:
  TitledTextInputView * _jobName;
  TitledTextInputView * _downloadDir;
  TitledTextInputView * _startPage;
  TitledTextInputView * _maxPageCount;

  TextRenderView * _aTitle;
  TextInputScrollView * _allowedDomains;

  TextRenderView * _bTitle;
  TextInputScrollView * _blacklistedDomains;
  
  Button * _startJob;

public:

private:
  void init();

public:
  SetupViewController();
  // TODO: copy const
  virtual ~SetupViewController();
  void startJobButtonPressed();
  static void startJobButtonPressedWrapper(void* target); // naming convention should be w_[functionname]

};

#endif // _Setup_View_Controller_h_