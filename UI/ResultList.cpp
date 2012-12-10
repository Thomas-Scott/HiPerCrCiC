// Michael Taufen 2012
#include "ResultList.h"

ResultList::ResultList(CGRect const& rect, TextScrollView* viewer) : ScrollView(rect)
{
  _listItemHeight = 50;
  _viewer = viewer;
  registerSelfAsQueryEngineListener();
}

ResultList::~ResultList()
{

}

void ResultList::addResultToList(ResultInfo * result)
{
  ResultListItem * resultLI;
  resultLI = new ResultListItem(result, 
    CGRect(
      0,
      (_resultList.size()) * _listItemHeight,
      this->getBounds().getWidth(),
      _listItemHeight));
  resultLI->setViewer(_viewer);
  _resultList.push_back(resultLI);
  this->insertSubView(resultLI);
}

void ResultList::onResultFound(ResultInfo* result)
{
  addResultToList(result);
}