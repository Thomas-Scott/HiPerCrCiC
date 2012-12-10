// Michael Taufen 2012
#ifndef _Result_Info_h_
#define _Result_Info_h_

#include <string>
using namespace std;

class ResultInfo
{
private:
  string _filename;
  string _directory;
  int _hits;
public:
  ResultInfo(string filename, string dir, int hits);
  ~ResultInfo();

  string getFilename(){return _filename;}
  string getDirectory(){return _directory;}
  int getHits(){return _hits;}

  void setFilename(string val){ _filename = val;}
  void setDirectory(string val){ _directory = val;}
  void setHits(int val){ _hits = val;}


};

#endif //_Result_Info_h_