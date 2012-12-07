#include "JobInfo.h"

JobInfo::JobInfo(std::string name, std::string startPage, double pages, std::string dir)
{
  _jobName = name;
  _startPage = startPage;
  _downloadDir = dir;
  _pagesCrawled = 0;
  _maxPages = pages;
  _id = -1;
  _dataLog = "";
}

JobInfo::~JobInfo()
{

}

std::string JobInfo::getStatusString()
{
  std::string temp;
  switch (_status)
  {
    case RUNNING:
      return "Running";
      break;
    case STOPPED:
      return "Stopped";
      break;
    case IN_QUEUE:
      return "In Queue";
      break;
    case COMPLETE:
      return "Complete";
      break;
    case CANCELLED:
      return "Cancelled";
      break;
    default:
      return "Status Unavailable";
      break;
  }
}