// Michael Taufen 2012
#ifndef _Job_List_h_
#define _Job_List_h_

#include "ScrollView.h"
#include "JobListItem.h"
#include <list>

class JobList : public ScrollView
{
  private:
    std::list<JobListItem *> _jobList;
    int _listItemHeight;
  public:
    JobList(CGRect const& rect);
    virtual ~JobList();

    void addJobToList(JobInfo * job);

    virtual void onJobAdded(JobInfo * job);
};

#endif //_Job_List_h_