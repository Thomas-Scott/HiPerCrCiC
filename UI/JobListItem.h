#ifndef _Job_List_Item_h_
#define _Job_List_Item_h_


#include "CancelButton.h"
#include "ClippedTextView.h"
#include "ProgressBar.h"

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

  virtual void onCrawlerUpdate();
  virtual void draw();


};

#endif //_Job_List_Item_h_