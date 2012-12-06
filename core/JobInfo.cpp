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