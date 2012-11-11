#ifndef _CGClasses_h_
#define _CGClasses_h_

enum State {ACTIVE, INACTIVE};

class CGColor
{
private: // private variables
  float _r, _g, _b, _a;
public: // public variables

private: // private methods
  
public: // public methods
  CGColor(const float red = 1.0, const float green = 1.0, const float blue = 1.0, const float alpha = 1.0)
    : _r(red), _g(green), _b(blue), _a(alpha){};

  CGColor(CGColor const& color);

  float getRed() const { return _r; }
  float getGreen() const { return _g; }
  float getBlue() const { return _b; }
  float getAlpha() const { return _a; }

  void setRed(const float value){ _r = value; }
  void setGreen(const float value){ _g = value; }
  void setBlue(const float value){ _b = value; }
  void setAlpha(const float value){ _a = value; }
};

class CGPoint
{
private: // private variables
  int _x, _y;
public: // public variables

private: // private methods

public: // public methods
  CGPoint(const int x = 0, const int y = 0)
    : _x(x), _y(y){};

  CGPoint(CGPoint const& point);

  int getX() const { return _x; }
  int getY() const { return _y; }

  void setX(const int x){ _x = x; }
  void setY(const int y){ _y = y; }
};

class CGRect
{
private: // private variables
  CGPoint _position, _size;
public: // public variables

private: // private methods

public: // public methods
  CGRect(const int x = 0, const int y = 0, const int width = 100, const int height = 100);

  CGRect(CGRect const& rect); // copy constructor

  int getX() const { return _position.getX(); }
  int getY() const { return _position.getY(); }
  int getWidth() const { return _size.getX(); }
  int getHeight() const { return _size.getY(); }

  void setX(const int x){ _position.setX(x); }
  void setY(const int y){ _position.setY(y); }
  void setWidth(const int width){ _size.setX(width); }
  void setHeight(const int height){ _size.setY(height); }

  bool isInside(CGPoint const& point);
};

#endif // _CGClasses_h_