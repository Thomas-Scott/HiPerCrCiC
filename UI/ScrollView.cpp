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
  
  int newRange = _contentView->getBounds().getHeight();
  _vertScrollBar->setRange(newRange);
  
  cerr << "newRange: " << newRange << endl;


  
  CGRect rect(_contentView->getBounds());
  rect.setY(- _vertScrollBar->getCurrentValue());
  _contentView->setBounds(rect);
  CGRect gB = this->getGlobalBounds();

  //enableClippingRect();
  setClippingRect(
    CGRect(gB.getX(), gB.getY(), gB.getWidth(), gB.getHeight()) );
  
  callDrawOnSubViews();
  setClippingRect(CGRect(0,0,GlobalState::winWidth,GlobalState::winHeight));
  //disableClippingRect();
  
  _vertScrollBar->draw();
  // could redraw the scrollbars here if necessary, or not add them as subviews and exc. draw here...
}