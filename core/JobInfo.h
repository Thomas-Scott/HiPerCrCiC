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
    std::string** _allowedDomains;
    std::string** _blacklistedDomains;
    int _currentThreadIndex; // -1 if not running
  public:

  private:
    // Takes an UNINITIALIZED array of string pointers, a string pointer for the input to split, and a character to split on
    void splitString(std::string** &output, const std::string* input, char br);

  public:
    JobInfo(std::string name, std::string startPage, double pages = 1, std::string dir = ".");
    ~JobInfo();

    std::string getJobName(){return _jobName;}
    std::string getStartPage(){return _startPage;}
    std::string getDownloadDir(){return _downloadDir;}
    double getMaxPages(){return _maxPages;}
    JobStatus getStatus(){return _status;}
    std::string getStatusString();
    int getId(){return _id;}
    std::string** getAllowedPtr(){return _allowedDomains;}
    std::string** getBlacklistedPtr(){return _blacklistedDomains;}
    int getCurrentThreadIndex(){return _currentThreadIndex;}

    void setJobName(std::string val){ _jobName = val; }
    void setStartPage(std::string val){ _startPage = val; }
    void setDownloadDir(std::string val){ _downloadDir = val; }
    void setMaxPages(double val){ _maxPages = val; }
    void setStatus(JobStatus val) { _status = val;}
    void setId(int val){_id = val;}
    void setCurrentThreadIndex(int val){_currentThreadIndex = val;}

    void setAllowedFromContentString(std::string* content, char br);
    void setBlacklistedFromContentString(std::string* content, char br);

    double getPagesCrawled(){return _pagesCrawled;}
    void setPagesCrawled(double val){_pagesCrawled = val;}

    void appendToLog(std::string data){_dataLog += data;}

};

#endif // _Job_Info_h_