#ifndef _Toggle_Button_h_
#define _Toggle_Button_h_

#include "View.h"

class ToggleButton : public View
{
private: // v
  bool _isActive;

public: //v

private: //m

public: // m
  ToggleButton(CGRect const& rect = CGRect(0,0,20,20));
  //TODO: copy const
  virtual ~ToggleButton();

  bool getIsActive(){ return _isActive; }
  void setIsActive(bool val) { _isActive = val; }
  void toggleIsActive();

  virtual bool onLeftClick(CGPoint const& pos);
  virtual void draw();
};

#endif // _Toggle_Button_h_