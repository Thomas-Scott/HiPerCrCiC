#include "ResultInfo.h"

ResultInfo::ResultInfo(string filename, string dir, int hits)
{
  _filename = filename;
  _directory = dir;
  _hits = hits;
}

ResultInfo::~ResultInfo()
{
  
}
