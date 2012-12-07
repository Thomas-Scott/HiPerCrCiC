#ifndef _Status_View_Controller_h_
#define _Status_View_Controller_h_

#include "ViewController.h"
#include "TextRenderView.h"
#include "JobList.h"

class StatusViewController : public ViewController
{
private:
  TextRenderView * _jobListTitle;
  JobList * _jobList;

public:

private:
  void init();

public:
  StatusViewController();
  // TODO: copy const
  virtual ~StatusViewController();

};

#endif // _Status_View_Controller_h_