#include "CGClasses.h"
#include "math.h"

//|----------------------------|
//|         CGColor            |
//|----------------------------|

CGColor::CGColor(CGColor const& color)
{
  _r = color.getRed();
  _g = color.getGreen();
  _b = color.getBlue();
  _a = color.getAlpha();
}

//|----------------------------|
//|         CGPoint            |
//|----------------------------|

CGPoint::CGPoint(CGPoint const& point)
{
  _x = point.getX();
  _y = point.getY();
}

//|----------------------------|
//|         CGRect             |
//|----------------------------|

CGRect::CGRect(const int x, const int y, const int width, const int height) // addition of default arguments make this a default constructor
{
  _position.setX(x);
  _position.setY(y);
  _size.setX(width);
  _size.setY(height);
}

CGRect::CGRect(CGRect const& rect)
{
  _position.setX(rect.getX());
  _position.setY(rect.getY());
  _size.setX(rect.getWidth());
  _size.setY(rect.getHeight());
}

bool CGRect::isInside(CGPoint const& point)
{
  if ( ( (point.getX() > _position.getX()) && (point.getX() < _position.getX() + _size.getX()) ) 
    && ( (point.getY() > _position.getY()) && (point.getY() < _position.getY() + _size.getY()) ) )
  {
    return true;
  }
  else
  {
    return false;
  }
}