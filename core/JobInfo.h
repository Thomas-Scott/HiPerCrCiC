#ifndef _Job_Info_h_
#define _Job_Info_h_

#include <string>

enum JobStatus {
  RUNNING,
  STOPPED,
  IN_QUEUE,
  COMPLETE,
  CANCELLED
}; // difference between stopped and cancelled is that cancelled implies that the user cancelled the job

class JobInfo
{
  private:
    std::string _jobName;
    std::string _startPage;
    std::string _downloadDir;
    double _pagesCrawled;
    double _maxPages;
    JobStatus _status;
    int _id; // -1 if not queued into the jobmanager
    std::string _dataLog;

  public:
    JobInfo(std::string name, std::string startPage, double pages = 1, std::string dir = ".");
    ~JobInfo();

    std::string getJobName(){return _jobName;}
    std::string getStartPage(){return _startPage;}
    std::string getDownloadDir(){return _downloadDir;}
    double getMaxPages(){return _maxPages;}
    JobStatus getStatus(){return _status;}
    int getId(){return _id;}

    void setJobName(std::string val){ _jobName = val; }
    void setStartPage(std::string val){ _startPage = val; }
    void setDownloadDir(std::string val){ _downloadDir = val; }
    void setMaxPages(double val){ _maxPages = val; }
    void setStatus(JobStatus val) { _status = val;}
    void setId(int val){_id = val;}

    double getPagesCrawled(){return _pagesCrawled;}
    void setPagesCrawled(double val){_pagesCrawled = val;}

    void appendToLog(std::string data){_dataLog += data;}

};

#endif // _Job_Info_h_