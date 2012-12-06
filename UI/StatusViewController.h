#ifndef _Status_View_Controller_h_
#define _Status_View_Controller_h_

#include "ViewController.h"
#include "ScrollView.h"
#include "TextRenderView.h"
#include "CrawlerRawOutputView.h"

class StatusViewController : public ViewController
{
private:
  TextRenderView * _jobListTitle;
  ScrollView * _jobList;
  CrawlerRawOutputView * _dataDump;

public:

private:
  void init();

public:
  StatusViewController();
  // TODO: copy const
  virtual ~StatusViewController();

};

#endif // _Status_View_Controller_h_