// Michael Taufen 2012
#ifndef _Scroll_Bar_h_
#define _Scroll_Bar_h_

#include "View.h"

class VertScrollBar : public View
{
private:
  float _range; // the pixel range that this scrollbar covers
  float _currentValue; // the current value set by the slider
  bool _isDragging;
  int _scaleLow;
  int _scaleHigh;
  int _scrollerHeight;
public:
  
private:
  void bind(float &val, int low, int high); // binds between two integer values
  void bind(int &val, int low, int high);   // binds between two integer values  
  void calculateScale();
public:
  VertScrollBar(CGRect const& rect);
  virtual ~VertScrollBar();

  float getRange() const {return _range;}
  void setRange(int range) {_range = range;}

  float getCurrentValue() const {return _currentValue;}
  void setCurrentValue(int val);

  virtual bool onMouseDown(CGPoint const& point);
  virtual bool onMouseUp(CGPoint const& point);
  virtual bool onMouseDrag(CGPoint const& point);

  virtual void draw();
};

#endif // _Scroll_Bar_h_