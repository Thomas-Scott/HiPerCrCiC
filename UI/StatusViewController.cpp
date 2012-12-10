// Michael Taufen 2012
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

  _jobList = new JobList(CGRect(100,50,GlobalState::winWidth-200,400));
   
  getMasterView()->addSubView(_jobListTitle);
  //getMasterView()->addSubView(_jobList);
  getMasterView()->addSubView(_jobList);
}

StatusViewController::~StatusViewController()
{

}
