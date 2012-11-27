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
<<<<<<< HEAD
  int _range; // the pixel range that this scrollbar covers
  int _currentValue; // the current value set by the slider
public:
  
private:
  void bind(int &val, int low, int high); // binds an int between two values
=======
  float _range; // the pixel range that this scrollbar covers
  float _currentValue; // the current value set by the slider
  bool _isDragging;
  int _scaleLow;
  int _scaleHigh;
  int _scrollerHeight;
public:
  
private:
  void bind(float &val, int low, int high); // binds between two values
  void bind(int &val, int low, int high); // binds between two values
  void calculateScale();
>>>>>>> ui-dev
public:
  VertScrollBar(CGRect const& rect);
  virtual ~VertScrollBar();

<<<<<<< HEAD
  int getRange() const {return _range;}
  void setRange(int range) {_range = range;}

  int getCurrentValue() const {return _currentValue;}
  void setCurrentValue(int val) {_currentValue = val;}

=======
  float getRange() const {return _range;}
  void setRange(int range) {_range = range;}

  float getCurrentValue() const {return _currentValue;}
  void setCurrentValue(int val) {_currentValue = val;}

  virtual bool onMouseDown(CGPoint const& point);
  virtual bool onMouseUp(CGPoint const& point);
>>>>>>> ui-dev
  virtual bool onMouseDrag(CGPoint const& point);

  virtual void draw();
};

#endif // _Scroll_Bar_h_