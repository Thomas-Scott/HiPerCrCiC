#ifndef _Crawler_Raw_Output_View_h_
#define _Crawler_Raw_Output_View_h_

#include "TextInputScrollView.h"

class CrawlerRawOutputView : public TextInputScrollView
{
public:
  CrawlerRawOutputView(CGRect const& rect);
  virtual ~CrawlerRawOutputView();

  virtual void onCrawlerUpdate(string data);
};

#endif //_Crawler_Raw_Output_View_h_