#include "SetupViewController.h"
#include <iostream>
#include "GlobalState.h"
#include "StatusViewController.h"
#include <pthread.h>
using namespace std;


SetupViewController::SetupViewController() : ViewController()
{
  getMasterView()->setIsTopView(true); // debug


  _jobName = new TitledTextInputView("Job Name:");
  _jobName->setBounds(CGRect(10,10,400,100));

  _downloadDir = new TitledTextInputView("Download Dir:");
  _downloadDir->setBounds(CGRect(420,10,400,100));

  _startPage = new TitledTextInputView("Start Page:");
  _startPage->setBounds(CGRect(500,220,400,100));

  _maxPageCount = new TitledTextInputView("Max Page Count:");
  _maxPageCount->setBounds(CGRect(500,330,400,100));
  
  _startJob = new Button("START", CGRect(700,700,200,50));

  _aTitle = new TextRenderView();
  _aTitle->setBounds(CGRect(10,120,300,50));
  _allowedDomains = new TextInputScrollView(CGRect(10,170,300,570));

  _bTitle = new TextRenderView();
  _bTitle->setBounds(CGRect(140,120,300,50));
  _blacklistedDomains = new TextInputScrollView(CGRect(140,480,300,570));


  getMasterView()->addSubView(_allowedDomains);
  getMasterView()->addSubView(_blacklistedDomains);
  getMasterView()->addSubView(_startPage);
  getMasterView()->addSubView(_maxPageCount);

  _startJob->setOnClickCallback(&startJobButtonPressedWrapper, this);
}

SetupViewController::~SetupViewController()
{

}

void SetupViewController::init()
{

}


void SetupViewController::startJobButtonPressed()
{
  cerr << "Start Button Pressed" << endl;
  GlobalState::tabInterfaceController->selectTabWithTitle("Status");
  
  string jobName = "Test Job";
  string startPage = getStartPageInputView()->getTextInputView()->getContent().c_str();
  int maxPages = 8;//atoi(getMaxPageCntInputView()->getTextInputView()->getContent().c_str());
  JobInfo * newJob = new JobInfo(
    jobName,
    startPage,
    maxPages);

  GlobalState::jobManager->queueJob(newJob);

  GlobalState::forceRedraw = true;

}

void SetupViewController::startJobButtonPressedWrapper(void* target)
{
  if (target)
  {
    SetupViewController* myself = (SetupViewController*)target;
    myself->startJobButtonPressed();
  } 
}