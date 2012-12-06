#ifndef _Crawler_Raw_Output_View_h_
#define _Crawler_Raw_Output_View_h_

#include "TextInputScrollView.h"

class CrawlerRawOutputView : public TextInputScrollView
{
public:
  CrawlerRawOutputView(CGRect const& rect);
  virtual ~CrawlerRawOutputView();

  virtual void onCrawlerUpdate();
};
// TODO: remove this class before final submission, as it is fully deprecated
#endif //_Crawler_Raw_Output_View_h_