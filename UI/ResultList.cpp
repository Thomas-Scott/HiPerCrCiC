#include "ResultList.h"

ResultList::ResultList(CGRect const& rect) : ScrollView(rect)
{
  _listItemHeight = 50;
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

  _resultList.push_back(resultLI);
  this->insertSubView(resultLI);
}

void ResultList::onResultFound(ResultInfo* result)
{
  addResultToList(result);
}