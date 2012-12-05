#include "ViewController.h"


// |-----------------------------|
// | Constructors and Destructor |
// |-----------------------------|

ViewController::ViewController()
{
  _masterView = new View();// should make this the dimensions of the screen, which the viewcontroller should have access to
  _masterView->setIsTopView(true);
}

ViewController::ViewController(ViewController const& viewC)
{
  _masterView = viewC.getMasterView();
}

ViewController::~ViewController()
{
  delete _masterView;
}


// |-----------------------------|
// |    Getters and Setters      |
// |-----------------------------|


void ViewController::setMasterView(View const& view)
{
  delete _masterView;
  _masterView = new View(view);
}



// |-----------------------------|
// |   Init and Running Code     |
// |-----------------------------|

void ViewController::loadView() //initializes all of the stuff in the masterView
{

}

void ViewController::drawMaster() // updates any data and then calls the draw function of the master view
{
  _masterView->draw();
}

void ViewController::update() // updates any data
{
  /* code */
}
