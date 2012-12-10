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

  _results = new ResultList(CGRect(10,345,280,280));
  getMasterView()->addSubView(_results);
   
  _fileViewer = new TextScrollView(CGRect(320,10,700,600));
  getMasterView()->addSubView(_fileViewer);
 
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
  /*
  cerr << "File Open Button Pressed" << endl;
  string filename = _filename->getTextInputView()->getContent();
  cerr << "Filename: " << filename << endl;
  
  ifstream file(filename.c_str());

  string data;
  if ( file.fail() )
  {
    data = "File could not be opened.";
  }
  else
  {
    data = string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  }
  
  //file.close();

  cerr << "Data: " << data << endl;

  _fileViewer->setContent(data);
  */
  char path[] = "test";
  char target[] = "testIndexed";
  bool clear = false;
  Indexer i(path, target, clear);
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
  // for now just push some queryengine events on to the stack
  //ResultInfo * result;
  //for (int i = 0; i < 5; ++i)
  //{
  //  result = new ResultInfo("test", "testINdexed", i);
  //  GlobalState::eventDisp->pushQueryEngineEvent(QueryEngineEvent(RESULT_FOUND, result));
  //}
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