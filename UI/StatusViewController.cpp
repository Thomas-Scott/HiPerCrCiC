#include "StatusViewController.h"
#include "GlobalState.h"
#include <iostream>
using namespace std;

StatusViewController::StatusViewController() : ViewController()
{
  _jobListTitle = new TextRenderView();
  _jobListTitle->setContent("Job Log:");
  _jobListTitle->setTextColor(CGColor(0.0,0.0,0.0,1.0));
  _jobListTitle->setBackgroundColor(CGColor(0.0,0.0,0.0,0.0));

  //_jobList = new ScrollView(CGRect(100,50,GlobalState::winWidth-200,400));
  //_jobList->getContentView()->setBackgroundColor(CGColor(0.2,0.2,0.2,1.0));

  _dataDump = new CrawlerRawOutputView(CGRect(100,50,GlobalState::winWidth-200,400));
   
  getMasterView()->addSubView(_jobListTitle);
  //getMasterView()->addSubView(_jobList);
  getMasterView()->addSubView(_dataDump);
}

StatusViewController::~StatusViewController()
{

}

void StatusViewController::init()
{

}

void StatusViewController::cheapFakeAddJobFunction()
{
  /*
  View * fakeJob = new View(CGRect(0, 0, GlobalState::winWidth - 200,70));
  _jobList->addSubView(fakeJob);
  fakeJob->setBackgroundColor(CGColor(1.0,1.0,1.0,0.1));

  TextRenderView * jobName = new TextRenderView();
  jobName->setContent("Job 1");
  jobName->setBounds(CGRect(0,0,100,70));
  jobName->setTextColor(CGColor(0.9,0.9,0.9,1.0));

  TextRenderView * jobStatus = new TextRenderView();
  jobStatus->setContent("Status: Complete");
  jobStatus->setBounds(CGRect(100,0,100,70));
  jobStatus->setTextColor(CGColor(0.9,0.9,0.9,1.0));

  fakeJob->addSubView(jobName);
  fakeJob->addSubView(jobStatus);
  //cout << "added WOOWOOOOWOOWOWO" << endl;
*/
}