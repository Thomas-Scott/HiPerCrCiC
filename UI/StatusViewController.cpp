#include "StatusViewController.h"
#include "GlobalState.h"

StatusViewController::StatusViewController() : ViewController()
{
  _jobListTitle = new TextRenderView();
  _jobListTitle->setContent("Jobs:");
  _jobListTitle->setTextColor(CGColor(0.0,0.0,0.0,1.0));
  _jobListTitle->setBackgroundColor(CGColor(0.0,0.0,0.0,0.0));

  _jobList = new ScrollView(CGRect(100,50,GlobalState::winWidth-200,400));
   
  getMasterView()->addSubView(_jobListTitle);
  getMasterView()->addSubView(_jobList);
}

StatusViewController::~StatusViewController()
{

}

void StatusViewController::init()
{

}