#ifndef _Search_View_Controller_h_
#define _Search_View_Controller_h_

#include "ViewController.h"
#include "TitledTextInputView.h"
#include "Button.h"
#include "TextScrollView.h"
#include "ResultList.h"

class SearchViewController : public ViewController
{
private:
  TitledTextInputView * _indexerDirName;
  TitledTextInputView * _query;
  TitledTextInputView * _queryDirName;
  Button * _runIndexerButton;
  Button * _runQueryButton;
  TextScrollView * _fileViewer;
  ResultList * _results;
public:

private:
  void init();

public:
  SearchViewController();
  // TODO: copy const
  virtual ~SearchViewController();
 
  TitledTextInputView * getIndexerDirName(){return _indexerDirName;}
  TitledTextInputView * getQueryDirName(){return _queryDirName;}
  TitledTextInputView * getQuery(){return _query;}

  void runIndexerButtonPressed();
  static void w_runIndexerButtonPressed(void* target); // correct naming convention

  void runQueryButtonPressed();
  static void w_runQueryButtonPressed(void* target);

};

#endif // _Search_View_Controller_h_