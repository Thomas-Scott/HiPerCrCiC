// Michael Taufen 2012
#ifndef _Result_List_h_
#define _Result_List_h_

#include "ResultListItem.h"
#include <list>

class ResultList : public ScrollView
{
  private:
    std::list<ResultListItem *> _resultList;
    int _listItemHeight;
    TextScrollView * _viewer;
  public:
    ResultList(CGRect const& rect, TextScrollView * viewer);
    virtual ~ResultList();

    void addResultToList(ResultInfo * result);

    virtual void onResultFound(ResultInfo * result);
};

#endif //_Result_List_h_