#include "SetupViewController.h"

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
    
  _allowedDomains->setBounds(CGRect(500,10,400,100));
  _blacklistedDomains->setBounds(CGRect(500,110,400,100));
  _startPage->setBounds(CGRect(500,220,300,100));
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
}

SetupViewController::~SetupViewController()
{

}

void SetupViewController::init()
{

}