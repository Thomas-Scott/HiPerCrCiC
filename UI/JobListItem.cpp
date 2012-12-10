// Michael Taufen 2012
#include "JobListItem.h"
#include "CommonGLFunctions.h"
#include "GlobalState.h"
#include <sstream>

JobListItem::JobListItem(JobInfo * job, CGRect const& rect) : View(rect)
{
  _job = job;
  
  CGRect bounds(rect);

  // Normalize to this instance
  bounds.setX(0);
  bounds.setY(0);
  
  bounds.setWidth(0.22*rect.getWidth());
  _jobName = new ClippedTextView(bounds, CGColor(0.0,0.0,0.0,1.0), job->getJobName());
  
  bounds.setX(0.22*rect.getWidth());
  _jobStatus = new ClippedTextView(bounds, CGColor(0.0,0.0,0.0,1.0), "Status Unavailable");
  
  bounds.setX(0.44*rect.getWidth());
  _pageProg = new ClippedTextView(bounds, CGColor(0.0,0.0,0.0,1.0), "");
  
  bounds.setX(0.66*rect.getWidth());
  _progressBar = new ProgressBar(bounds, CGColor(0.1,0.9,0.1,1.0), CGColor(0.3,0.3,0.3,1.0));
  
  bounds.setX(0.88*rect.getWidth());
  bounds.setWidth(0.06*rect.getWidth());
  _percentProg = new ClippedTextView(bounds, CGColor(0.0,0.0,0.0,1.0), "0%");
  _cancelJobButton = new CancelButton();
  bounds.setHeight(_cancelJobButton->getBounds().getHeight());
  bounds.setWidth(_cancelJobButton->getBounds().getWidth());
  bounds.setX(0.94*rect.getWidth());
  bounds.setY(rect.getHeight()/2 - bounds.getHeight()/2 );
  _cancelJobButton->setBounds(bounds);
  _cancelJobButton->setOnClickCallback(&w_cancelJobButtonPressed, this);
  
  addSubView(_jobName);
  addSubView(_jobStatus);
  addSubView(_pageProg);
  addSubView(_progressBar);
  addSubView(_percentProg);
  addSubView(_cancelJobButton);

  registerSelfAsCrawlerListener();
}

JobListItem::~JobListItem()
{

}

void JobListItem::onCrawlerUpdate()
{
  // set all of the values that will change again based on the information in the JobInfo object
  _jobStatus->setContent(_job->getStatusString());
  stringstream ss;
  ss << _job->getPagesCrawled() << "/" << _job->getMaxPages();
  _pageProg->setContent(ss.str());
  _progressBar->setPercentComplete( _job->getPagesCrawled() / _job->getMaxPages() );
  ss.str(""); // clear the ss
  ss << (_progressBar->getPercentComplete()*100) << "%";
  _percentProg->setContent(ss.str());
  GlobalState::forceRedraw = true;
}

void JobListItem::cancelJobButtonPressed()
{
  // tell the job manager to cancel the job referenced by this list item
  GlobalState::jobManager->cancelJob(_job); 
}

void JobListItem::w_cancelJobButtonPressed(void *target)
{
  JobListItem * myself = (JobListItem*)target;
  myself->cancelJobButtonPressed();
}

void JobListItem::draw()
{
  CGRect gB = this->getGlobalBounds();
  // Draw background and border
  drawRectWithColor(gB, CGColor(0.97,0.97,0.97,1.0));
  drawBorderWithColor(gB.getInset(3), CGColor(1.0,1.0,1.0,1.0));
  // Draw subviews
  callDrawOnSubViews();
}

