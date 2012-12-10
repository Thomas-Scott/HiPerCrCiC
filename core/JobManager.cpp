#include "JobManager.h"
#include "../UI/GlobalState.h"
using namespace std;



void * threadProcess (void * _info) // the process that the threads will use to request, start, and finish crawler jobs
{
    pair<JobManager*,int> * info = (pair<JobManager*,int> *)_info;
    JobManager * jobManager = info->first;
    int threadIndex = info->second;
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
      int prevCancelType;
      // start up the job
      nextJob->setCurrentThreadIndex(threadIndex);
      pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &prevCancelType);
      nextJob->setStatus(RUNNING);
      Crawler * crawler = new Crawler();
      crawler->crawl(nextJob);
      pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &prevCancelType);
      delete crawler;
      nextJob->setCurrentThreadIndex(-1);
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
  _threads = new pthread_t*[threadCnt];
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
  pair<JobManager*,int> * info;
  // start the threads
  for (int i = 0; i < _threadCnt; ++i)
  {
    info = new pair<JobManager*,int>(this, i);
    _threads[i] = new pthread_t;
    pthread_create(_threads[i], NULL, threadProcess, info);
    //delete info; // don't delete it because the thread needs it
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

void JobManager::cancelRunningJob(JobInfo* job)
{
  int index = job->getCurrentThreadIndex();
  if (index >= 0 && index < _threadCnt)
  {
    // cancel the thread
    pthread_cancel(*(_threads[index]));
    // get it going again
    pair<JobManager*,int> * info = new pair<JobManager*,int>(this, index);
    pthread_create(_threads[index], NULL, threadProcess, info);
    //delete _threads[index];
    job->setStatus(CANCELLED);
  }
  else
  {
    cerr << "Could not find job to cancel." << endl;
  }
}

void JobManager::cancelJob(JobInfo * job)
{

  switch(job->getStatus())
  {
    case IN_QUEUE:
      job->setStatus(CANCELLED);
      break;
    case COMPLETE:
      cerr << "Job already complete, cannot cancel." << endl;
      break;
    case STOPPED:
      cerr << "Job stopped for undetermined reason, cannot cancel." << endl;
      break;
    case CANCELLED:
      cerr << "Job already cancelled." << endl;
      break;
    case RUNNING:
      cancelRunningJob(job);
      break;
    default:
      cerr << "Unable to cancel." << endl;
      break;
  }
  // So the UI will update:
  GlobalState::eventDisp->pushCrawlerEvent(CrawlerEvent(CRAWLER_UPDATE));
}


