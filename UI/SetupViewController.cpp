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
  _jobName->setBounds(CGRect(10,10,250,70));
  getMasterView()->addSubView(_jobName);

  _downloadDir = new TitledTextInputView("Download Dir:");
  _downloadDir->setBounds(CGRect(270,10,250,70));
  getMasterView()->addSubView(_downloadDir);

  _startPage = new TitledTextInputView("Start Page:");
  _startPage->setBounds(CGRect(530,10,400,70));
  getMasterView()->addSubView(_startPage);

  _maxPageCount = new TitledTextInputView("Max Page Count:");
  _maxPageCount->setBounds(CGRect(730,330,180,70));
  getMasterView()->addSubView(_maxPageCount);
  
  _startJob = new Button("START", CGRect(730,600,200,50));
  _startJob->setOnClickCallback(&startJobButtonPressedWrapper, this);
  getMasterView()->addSubView(_startJob);

  _aTitle = new TextRenderView();
  _aTitle->setBounds(CGRect(10,120,300,50));
  _aTitle->setTextColor(CGColor(0,0,0,1));
  _aTitle->setContent("Allowed Domains:");
  getMasterView()->addSubView(_aTitle);
  _allowedDomains = new TextInputScrollView(CGRect(10,170,350,400));
  getMasterView()->addSubView(_allowedDomains);

  _bTitle = new TextRenderView();
  _bTitle->setBounds(CGRect(370,120,300,50));
  _bTitle->setTextColor(CGColor(0,0,0,1));
  _bTitle->setContent("Blacklisted Domains:");
  getMasterView()->addSubView(_bTitle);
  _blacklistedDomains = new TextInputScrollView(CGRect(370,170,350,400));
  getMasterView()->addSubView(_blacklistedDomains);

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