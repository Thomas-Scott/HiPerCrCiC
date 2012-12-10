#ifndef _Result_List_Item_h_
#define _Result_List_Item_h_

#include "ClippedTextView.h"
#include "../analysis/ResultInfo.h"

class ResultListItem : public View
{
private:
  ResultInfo * _result;
  ClippedTextView * _resultName;
  ClippedTextView * _hits;
public:

private:

public:
  ResultListItem(ResultInfo * result, CGRect const& rect);
  virtual ~ResultListItem();

  ResultInfo * getResultInfo(){return _result;}
  void setResultInfo(ResultInfo* result){_result = result;}

  virtual bool onLeftClick(CGPoint const& pos);

  virtual void draw();
};

#endif //_Result_List_Item_h_