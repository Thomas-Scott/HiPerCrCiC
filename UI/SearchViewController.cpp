#include "SearchViewController.h"
#include <fstream>
#include <iostream>

SearchViewController::SearchViewController() : ViewController()
{
  
  _filename = new TitledTextInputView("Filename:");
  _filename->setBounds(CGRect(10,10,160,100));

  _openButton = new Button("Open File", CGRect(10,165,100,50));
  _openButton->setOnClickCallback(&w_fileOpenButtonPressed, this);

  _fileViewer = new TextScrollView(CGRect(220,10,800,600));


  getMasterView()->addSubView(_filename);
  getMasterView()->addSubView(_openButton);
  getMasterView()->addSubView(_fileViewer);
}

SearchViewController::~SearchViewController()
{

}

void SearchViewController::init()
{

}

void SearchViewController::fileOpenButtonPressed()
{
  cerr << "File Open Button Pressed" << endl;
  string filename = _filename->getTextInputView()->getContent();
  cerr << "Filename: " << filename << endl;
  
  ifstream file(filename.c_str());

  string data;
  if ( file.fail() )
  {
    data = "File could not be opened.";
  }
  else
  {
    data = string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
  }
  
  //file.close();

  cerr << "Data: " << data << endl;

  _fileViewer->setContent(data);

}

void SearchViewController::w_fileOpenButtonPressed(void *target)
{
  if (target)
  {
    SearchViewController* myself = (SearchViewController*)target;
    myself->fileOpenButtonPressed();
  }

}