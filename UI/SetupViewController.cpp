#include "SetupViewController.h"
#include <iostream>
#include "GlobalState.h"
#include <fstream>
#include "../core/Crawler.h"
using namespace std;

SetupViewController::SetupViewController() : ViewController()
{
  getMasterView()->setIsTopView(true); // debug
  _allowedDomains = new TitledTextInputView("Allowed Domains:");
  _blacklistedDomains = new TitledTextInputView("Blacklisted Domains:");
  _startPage = new TitledTextInputView("Start Page:");
  _maxPageCount = new TitledTextInputView("Max Page Count:");
  _cleaningToggle = new TitledToggleButton("Default Cleaning");
  _indexingToggle = new TitledToggleButton("Default Indexing");
  _loadFromCfg = new Button("Load from .cfg", CGRect(50,10,200,50));
  _saveToCfg = new Button("Save to .cfg", CGRect(50,70,200,50));
  _startJob = new Button("START", CGRect(50,130,200,50));
  _testTISV = new TextInputScrollView( CGRect(20,200,400,100) );

  _testSV = new ScrollView(CGRect(20,350,400,270));
  for (int rows = 0; rows < 50; ++rows)
  {
    for (int columns = 0; columns < 19; ++columns)
    {
      View * view;
      CGColor checkerColor;
      if (columns % 2 == rows % 2) // white if both odd or both even
      {
        checkerColor = CGColor(1.0,1.0,1.0,1.0);
      }
      else // black if one is odd and one is even
      {
        checkerColor = CGColor(0.0,0.0,0.0,1.0);
      }
      view = new View(CGRect(columns*20,rows*20,20,20), checkerColor);
      _testSV->insertSubView(view);
    }
  }

  _allowedDomains->setBounds(CGRect(500,10,400,100));
  _blacklistedDomains->setBounds(CGRect(500,110,400,100));
  _startPage->setBounds(CGRect(500,220,400,100));
  _maxPageCount->setBounds(CGRect(500,330,400,100));
  CGRect tempBnds = _cleaningToggle->getBounds();
  tempBnds.setX(500);
  tempBnds.setY(500);
  _cleaningToggle->setBounds(tempBnds);
  tempBnds = _indexingToggle->getBounds();
  tempBnds.setX(500);
  tempBnds.setY(550);
  _indexingToggle->setBounds(tempBnds);

  getMasterView()->addSubView(_allowedDomains);
  getMasterView()->addSubView(_blacklistedDomains);
  getMasterView()->addSubView(_startPage);
  getMasterView()->addSubView(_maxPageCount);
  getMasterView()->addSubView(_cleaningToggle);
  getMasterView()->addSubView(_indexingToggle);
  getMasterView()->addSubView(_loadFromCfg);
  getMasterView()->addSubView(_saveToCfg);
  getMasterView()->addSubView(_startJob);
  getMasterView()->addSubView(_testSV);

  getMasterView()->addSubView(_testTISV);

  _startJob->setOnClickCallback(&startJobButtonPressed);
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
  GlobalState::forceRedraw = true;
  /*ofstream f("tmp.cfg");
  f << _startPage->getTextInputView()->getContent()
    << "\n" << 10 << endl;*/
  Crawler thign;


}