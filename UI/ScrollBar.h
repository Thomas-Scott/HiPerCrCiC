#ifndef _Scroll_Bar_h_
#define _Scroll_Bar_h_

#include "View.h"

class HorizScrollBar : public View
{
private:

public:

private:

public:

};

class VertScrollBar : public View
{
private:
  int _range; // the pixel range that this scrollbar covers
  int _currentValue; // the current value set by the slider
public:
  
private:
  void bind(int &val, int low, int high); // binds an int between two values
public:
  VertScrollBar(CGRect const& rect);
  virtual ~VertScrollBar();

  int getRange() const {return _range;}
  void setRange(int range) {_range = range;}

  int getCurrentValue() const {return _currentValue;}
  void setCurrentValue(int val) {_currentValue = val;}

  virtual bool onMouseDrag(CGPoint const& point);

  virtual void draw();
};

#endif // _Scroll_Bar_h_