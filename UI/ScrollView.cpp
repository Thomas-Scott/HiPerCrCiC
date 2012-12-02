#include "ScrollView.h"
#include "CommonGLFunctions.h"
#include "GlobalState.h"
#include <iostream>


ScrollView::ScrollView(CGRect const& rect) : View(rect)
{
  _vertScrollBar = new VertScrollBar(
    CGRect(rect.getWidth()-20,0,20,rect.getHeight()) );
  _contentView = new View(
    CGRect(0,0,rect.getWidth()-20, rect.getHeight()) );
  this->addSubView(_contentView);
  this->addSubView(_vertScrollBar);
}

ScrollView::~ScrollView()
{
  // delete _horizScrollBar;
  delete _vertScrollBar;
  delete _contentView;
}

View * ScrollView::insertSubView(View * view)
{
  _contentView->addSubView(view);
  // recalculate the size of the contentView,
  // should only add things to the bottom or to the right
  set<View *> * setPtr = _contentView->getPointerToSubViewSet();
  int maxXW = 0;
  int maxYH = 0;
  for (set<View *>::iterator it = setPtr->begin(); it != setPtr->end(); ++it)
  {
    // find the maximum x + width and y + height values in the subview set
    // oh gawd should be recursive on subviews -_-
    int XW = (*it)->getBounds().getX()+(*it)->getBounds().getWidth();
    int YH = (*it)->getBounds().getY()+(*it)->getBounds().getHeight();
    if (XW > maxXW)
      maxXW = XW;
    if (YH > maxYH)
      maxYH = YH;
  }
  // resize the content view accordingly, with a minimum size being the size defined
  // in the constructor

  if (this->getBounds().isInside(CGPoint(maxXW, maxYH)))
  {
    CGRect rect = this->getBounds();
    _contentView->setBounds(CGRect(0,0,rect.getWidth()-20, rect.getHeight()));
  }
  else // it's bigger, need resize to edge of biggest piece
  {
    _contentView->setBounds(CGRect(0,0,maxXW,maxYH));
  }
  return view;
}



void ScrollView::draw()
{
  CGRect gB = this->getGlobalBounds();

  // The range should be the height difference between the contentView and the scrollView, minimum 0
  // Because that is the range of offset available
  int newRange = _contentView->getBounds().getHeight() - gB.getHeight();
  if (newRange > 0)
    _vertScrollBar->setRange(newRange + 1); // +1 because no scrolling is range 1
  else
    _vertScrollBar->setRange(1);
  
  //cerr << "newRange: " << newRange << endl;


  
  CGRect rect(_contentView->getBounds());

  if (_forceToBottom)
  {
    _vertScrollBar->setCurrentValue(_vertScrollBar->getRange());
  }
  rect.setY(- _vertScrollBar->getCurrentValue());
  _contentView->setBounds(rect);
  

  //enableClippingRect();
  // Save the previous clipping rect
  CGRect previousClippingRect(getClippingRect());
  // Set the clipping rect for this view
  setClippingRect(
    CGRect(gB.getX(), gB.getY(), gB.getWidth(), gB.getHeight()) );
  
  callDrawOnSubViews();
  
  // Restore the previous clipping rect
  setClippingRect(previousClippingRect);
  //disableClippingRect();
  
  _vertScrollBar->draw();
  // could redraw the scrollbars here if necessary, or not add them as subviews and exc. draw here...
}