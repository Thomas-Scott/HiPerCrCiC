#ifndef _Job_List_Item_h_
#define _Job_List_Item_h_

#include "ClippedTextView.h"
#include "CancelButton.h"
#include "ProgressBar.h"
#include "../core/JobInfo.h"

class JobListItem : public View
{
private:
  JobInfo * _job;
  ClippedTextView * _jobName;
  ClippedTextView * _jobStatus;
  ClippedTextView * _pageProg;
  ProgressBar * _progressBar;
  ClippedTextView * _percentProg;
  CancelButton * _cancelJobButton;
public:

private:

public:
  JobListItem(JobInfo * job, CGRect const& rect);
  virtual ~JobListItem();

  JobInfo * getJobPointer(){return _job;}
  void setJobPointer(JobInfo * job){_job = job;}

  virtual void onCrawlerUpdate(string data);
  virtual void draw();


};

#endif //_Job_List_Item_h_