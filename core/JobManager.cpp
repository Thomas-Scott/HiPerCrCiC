#include "JobManager.h"
#include "../UI/GlobalState.h"
using namespace std;



void * threadProcess (void * _jobManager) // the process that the threads will use to request, start, and finish crawler jobs
{
    JobManager * jobManager = (JobManager *)_jobManager;
    queue<JobInfo *> * qP = jobManager->getQueuePointer();
    JobInfo * nextJob;
    
    // acquire a lock on the queue
  while(true)
  {
    pthread_mutex_lock(jobManager->getQueueLock());
    // if jobs in queue 
    if (qP->size() > 0)
    {
      // request next job
      nextJob = qP->front();
      // pop the job from the queue
      qP->pop();
    }
    else
    {
      // set nextJob pointer to 0 so we know we didn't get any jobs
      // note that if the job was cancelled, the pointer will already be set
      // to zero
      nextJob = 0;
    }
    // unlock the queue
    pthread_mutex_unlock(jobManager->getQueueLock());
    // start up a crawler and run the job if we got one
    if (nextJob)
    {
      // start up the job
      Crawler * crawler = new Crawler();
      crawler->crawl(nextJob);
      delete crawler;
    } 
    // wait a little bit before repeating to ease strain on CPU
    sleep(1);
  } // repeat
}

JobManager::JobManager(int threadCnt)
{
  _threadCnt = threadCnt;
  _lastJobId = 0;
  _jobQueue = new queue<JobInfo *>;
  _allJobs = new set<JobInfo *>;
  _threads = new pthread_t[threadCnt];
  init();
}

JobManager::~JobManager()
{
  delete _jobQueue;
  // delete all of the jobs pointed to by _allJobs
  for(set<JobInfo*>::iterator it = _allJobs->begin(); it != _allJobs->end(); ++it)
  {
    delete (*it);
  }
  delete _allJobs;
  delete[] _threads;
}

void JobManager::init()
{
  // start the threads
  for (int i = 0; i < _threadCnt; ++i)
  {
    pthread_create(&_threads[i], NULL, threadProcess, this);
  }
}

void JobManager::queueJob(JobInfo * job)
{
  _lastJobId++;
  job->setId(_lastJobId);
  job->setStatus(IN_QUEUE);
  _allJobs->insert(job);
  _jobQueue->push(job);
  GlobalState::eventDisp->pushJobManagerEvent(JobManagerEvent(JOB_ADDED, job));
}

void JobManager::cancelJob(JobInfo * job)
{
  // if the thread the job is on is running, we need to lock the thread
  // exit the thread, delete the job, and start the thread afresh
}


