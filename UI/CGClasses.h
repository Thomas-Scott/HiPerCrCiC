#ifndef _CGClasses_h_
#define _CGClasses_h_

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

  float getHue() const;
  float getSaturation() const;
  float getBrightness() const;

  void setRed(const float value){ _r = value; }
  void setGreen(const float value){ _g = value; }
  void setBlue(const float value){ _b = value; }
  void setAlpha(const float value){ _a = value; }

  void setHue(const float value);
  void setSaturation(const float value);
  void setBrightness(const float value);

  void setColorWithHSB(const float hue = 1.0, const float saturation = 1.0, const float brightness = 1.0, const float alpha = 1.0);
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

  CGRect getInset(int margin) const 
  { 
    return CGRect(
      this->getX() + margin,
      this->getY() + margin,
      this->getWidth() - 2*margin,
      this->getHeight() - 2*margin ); 
  }

  void setX(const int x){ _position.setX(x); }
  void setY(const int y){ _position.setY(y); }
  void setWidth(const int width){ _size.setX(width); }
  void setHeight(const int height){ _size.setY(height); }

  bool isInside(CGPoint const& point);
  bool isIntersecting(CGRect const& rect);
  CGRect getIntersection(CGRect const& rect); // returns the intersection if the rectangles intersect, else returns the rectangle it was called on
};

#endif // _CGClasses_h_