// Michael Taufen 2012
#include "SearchViewController.h"
#include <fstream>
#include <iostream>
#include "../analysis/Indexer.h"
#include "../analysis/QueryEngine.h"
#include "GlobalState.h"
#include <pthread.h>

SearchViewController::SearchViewController() : ViewController()
{
  
  

  _indexerDirName = new TitledTextInputView("Indexer Directory:");
  _indexerDirName->setBounds(CGRect(10,10,160,75));
  getMasterView()->addSubView(_indexerDirName);

  _runIndexerButton = new Button("Run Indexer", CGRect(10,95,200,30));
  _runIndexerButton->setOnClickCallback(&w_runIndexerButtonPressed, this);
  getMasterView()->addSubView(_runIndexerButton);

  _queryDirName = new TitledTextInputView("Query Directory:");
  _queryDirName->setBounds(CGRect(10,135,160,75));
  getMasterView()->addSubView(_queryDirName);

  _query = new TitledTextInputView("Query:");
  _query->setBounds(CGRect(10,220,160,75));
  getMasterView()->addSubView(_query);

  _runQueryButton = new Button("Run Query", CGRect(10,305,200,30));
  _runQueryButton->setOnClickCallback(&w_runQueryButtonPressed, this);
  getMasterView()->addSubView(_runQueryButton);

  _fileViewer = new TextScrollView(CGRect(320,10,700,600));
  getMasterView()->addSubView(_fileViewer);

  _results = new ResultList(CGRect(10,345,280,280), _fileViewer);
  getMasterView()->addSubView(_results);
}

SearchViewController::~SearchViewController()
{
  delete _runIndexerButton;
  delete _indexerDirName;
  delete _queryDirName;
  delete _query;
  delete _runQueryButton;
  delete _results;
  delete _fileViewer;
}

void SearchViewController::init()
{

}

void SearchViewController::runIndexerButtonPressed()
{
  string path = _indexerDirName->getTextInputView()->getContent();
  string target = path + "Indexed";
  char _path[path.length() + 1];
  char _target[path.length() + 8];
  for(int i = 0; i <= path.length(); ++i)
  {
    _path[i] = path.c_str()[i];
  }
  for(int i = 0; i <= target.length(); ++i)
  {
    _target[i] = target.c_str()[i];
  }
  bool clear = false;
  Indexer i(_path, _target, clear);
  i.execute();

}

void SearchViewController::w_runIndexerButtonPressed(void *target)
{
  if (target)
  {
    SearchViewController* myself = (SearchViewController*)target;
    myself->runIndexerButtonPressed();
  }

}

void * queryProcess(void * _searchViewController)
{
  SearchViewController * svC = (SearchViewController*)_searchViewController;
  string dir = svC->getQueryDirName()->getTextInputView()->getContent();
  string query = svC->getQuery()->getTextInputView()->getContent();

  QueryEngine engine(dir, query);
  cerr << "Q:" << query << endl;
  engine.execute();
  engine.getResults();

  pthread_exit(NULL);
}

void SearchViewController::runQueryButtonPressed()
{
  
  pthread_t thread;
  pthread_create(&thread, NULL, queryProcess, this);

  
}

void SearchViewController::w_runQueryButtonPressed(void *target)
{
  if (target)
  {
    SearchViewController* myself = (SearchViewController*)target;
    myself->runQueryButtonPressed();
  }
}