#include "JobList.h"

JobList::JobList(CGRect const& rect) : ScrollView(rect)
{
  _listItemHeight = 50;
  registerSelfAsJobManagerListener();
}

JobList::~JobList()
{

}

void JobList::addJobToList(JobInfo * job)
{
  JobListItem * jobLI;
    jobLI = new JobListItem(job,
      CGRect(
        0,
        (_jobList.size()+1) * _listItemHeight,
        this->getBounds().getWidth(),
        _listItemHeight));

  _jobList.push_back(jobLI);
  this->insertSubView(jobLI);
}

void JobList::onJobAdded(JobInfo * job)
{
  addJobToList(job);
}
