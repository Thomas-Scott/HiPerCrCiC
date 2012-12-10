#ifndef _Result_List_h_
#define _Result_List_h_

#include "ScrollView.h"
#include "ResultListItem.h"
#include <list>

class ResultList : public ScrollView
{
  private:
    std::list<ResultListItem *> _resultList;
    int _listItemHeight;
  public:
    ResultList(CGRect const& rect);
    virtual ~ResultList();

    void addResultToList(ResultInfo * result);

    virtual void onResultFound(ResultInfo * result);
};

#endif //_Result_List_h_