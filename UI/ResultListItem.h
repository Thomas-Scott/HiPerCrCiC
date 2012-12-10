// Michael Taufen 2012
#ifndef _Result_List_Item_h_
#define _Result_List_Item_h_

#include "TextScrollView.h"
#include "ClippedTextView.h"
#include "../analysis/ResultInfo.h"

class ResultListItem : public View
{
private:
  ResultInfo * _result;
  ClippedTextView * _resultName;
  ClippedTextView * _hits;
  TextScrollView * _viewer;
public:

private:

public:
  ResultListItem(ResultInfo * result, CGRect const& rect);
  virtual ~ResultListItem();

  ResultInfo * getResultInfo(){return _result;}
  void setResultInfo(ResultInfo* result){_result = result;}

  TextScrollView * getViewer(){return _viewer;}
  void setViewer(TextScrollView * viewer){_viewer = viewer;}

  virtual bool onLeftClick(CGPoint const& pos);

  virtual void draw();
};

#endif //_Result_List_Item_h_