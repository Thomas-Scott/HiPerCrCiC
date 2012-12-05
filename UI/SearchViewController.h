#ifndef _Search_View_Controller_h_
#define _Search_View_Controller_h_

#include "ViewController.h"
#include "TitledTextInputView.h"
#include "Button.h"
#include "TextScrollView.h"

class SearchViewController : public ViewController
{
private:
  TitledTextInputView * _filename;
  Button * _openButton;
  TextScrollView * _fileViewer;
public:

private:
  void init();

public:
  SearchViewController();
  // TODO: copy const
  virtual ~SearchViewController();
  void fileOpenButtonPressed();
  static void w_fileOpenButtonPressed(void* target); // correct naming convention

};

#endif // _Search_View_Controller_h_