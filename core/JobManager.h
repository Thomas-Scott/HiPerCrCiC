#ifndef _Job_Manager_h_
#define _Job_Manager_h_

#include <queue>
#include <set>
#include <pthread.h>
#include "Crawler.h"


class JobManager
{
private: //v
  std::queue<JobInfo *> * _jobQueue;
  std::set<JobInfo *> * _allJobs;
  pthread_t * _threads;
  int _threadCnt;
  int _lastJobId; // job id's will start at 0 and just increment by 1 with each job added

  pthread_mutex_t _queueLock;
public: //v

private: //m

public: //m
  JobManager(int threadCnt = 3);
  ~JobManager();

  void init(); // starts up the threads

  void queueJob(JobInfo * job);
  void cancelJob(JobInfo * job);

  pthread_mutex_t * getQueueLock(){ return &_queueLock; }
  std::queue<JobInfo *> * getQueuePointer(){ return _jobQueue; }
};

#endif // _Job_Manager_h_