#include "JobListItem.h"
#include "CommonGLFunctions.h"

JobListItem::JobListItem(JobInfo * job, CGRect const& rect) : View(rect)
{
  _job = job;
  
  CGRect bounds(rect);
  
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
  bounds.setY(rect.getY() 
    + (rect.getHeight()/2 - _cancelJobButton->getBounds().getHeight()/2) );
  _cancelJobButton->setBounds(bounds);
}

JobListItem::~JobListItem()
{

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

