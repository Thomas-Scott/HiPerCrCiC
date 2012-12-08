#include "JobInfo.h"
#include <vector>
using namespace std;

JobInfo::JobInfo(string name, string startPage, double pages, string dir)
{
  _jobName = name;
  _startPage = startPage;
  _downloadDir = dir;
  _pagesCrawled = 0;
  _maxPages = pages;
  _id = -1;
  _dataLog = "";
  _allowedDomains = 0;
  _blacklistedDomains = 0;
}

JobInfo::~JobInfo()
{

}

string JobInfo::getStatusString()
{
  string temp;
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

void JobInfo::splitString(string** &output, const string* input, char br)
{

  vector<string> _lines;
  // Split up the text
  _lines.empty(); // start anew
  _lines.resize(0);
  string temp = "";
  

  for (string::const_iterator it = input->begin(); it != input->end(); ++it)
  {
    temp += (*it);
    
    if ((*it) == br)
    {
      _lines.push_back(temp);
      temp.clear(); 
    }
  }
  _lines.push_back(temp); // push the rest

  output = new string*[_lines.size() + 1];

  for (int i = 0; i < _lines.size(); ++i)
  {
    output[i] = new string(_lines[i]);
  }

  output[_lines.size()] = 0;
}

void JobInfo::setAllowedFromContentString(std::string* content, char br)
{
  // deallocate allowed
  int i = 0;
  if (_allowedDomains)
  {
    while (_allowedDomains[i] != 0)
    {
      delete _allowedDomains[i];
      ++i;
    }
    delete[] _allowedDomains;
  }

  splitString(_allowedDomains, content, br);

}

void JobInfo::setBlacklistedFromContentString(std::string* content, char br)
{
  // deallocate blacklisted
  int i = 0;
  if (_blacklistedDomains)
  {
    while (_blacklistedDomains[i] != 0)
    {
      delete _blacklistedDomains[i];
      ++i;
    }
    delete[] _blacklistedDomains;
  }

  splitString(_blacklistedDomains, content, br);
}










