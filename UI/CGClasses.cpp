#include <algorithm>
#include "CGClasses.h"
using namespace std;

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

float CGColor::getHue() const
{

  float red = 255.0*_r;
  float green = 255.0*_g;
  float blue = 255.0*_b;

  float M = max(max(red, green), blue);
  float m = min(min(red, green), blue);
  float chroma = M - m;
  float huePrime, hue;



  if (0 == chroma)
  {
    huePrime = 0;
  }
  else if (M == _r)
  {
    huePrime = ( (int)( (green - blue)/chroma ) ) % 6;
  }
  else if (M == _g)
  {
    huePrime = (blue - red) / chroma + 2;
  }
  else if (M == _b)
  {
    huePrime = (red - green) / chroma + 4;
  }
  else
  {
    huePrime = 0; // just in case
  }

  hue = 60*huePrime; // linearly map to a 60 degree section of the hexagon morphed into a circle

  // normalize hue to a value between 0.0 and 1.0
  hue /= 360.0;

  return hue;
}

float CGColor::getSaturation() const
{
  float red = 255.0*_r;
  float green = 255.0*_g;
  float blue = 255.0*_b;

  float M = max(max(red, green), blue);
  float m = min(min(red, green), blue);
  float chroma = M - m;

  if (0 == chroma)
  {
    return 0;
  } 
  else
  {
    return (chroma / M) / 100; // because Saturation(HSV==HSB) == C/V == C/B == C/M, and this is normalized
  } 
}

float CGColor::getBrightness() const
{
 // Brightness = max(R, G, B)
  return max(max(_r, _g), _b);
}

void CGColor::setHue(const float value)
{
  setColorWithHSB(value, getSaturation(), getBrightness(), getAlpha());
}

void CGColor::setSaturation(const float value)
{
  setColorWithHSB(getHue(), value, getBrightness(), getAlpha());
}

void CGColor::setBrightness(const float value)
{
  setColorWithHSB(getHue(), getSaturation(), value, getAlpha());
}

void CGColor::setColorWithHSB(
  const float h, 
  const float s, 
  const float b, 
  const float alpha )
{
  float hue = h * 360.0;
  float sat = s * 100.0;
  float brt = b * 100.0;

  float chroma = brt * sat;
  float huePrime = hue / 60.0;
  float x = chroma * (1 - abs( ( (int) huePrime % 2) - 1) );
  float match = brt - chroma;

  float R1 = 0; 
  float G1 = 0; 
  float B1 = 0;

  if (0 <= huePrime && huePrime < 1)
  {
    R1 = chroma;
    G1 = x;
    B1 = 0;
  }
  else if (1 <= huePrime && huePrime < 2)
  {
    R1 = x;
    G1 = chroma;
    B1 = 0;
  }
  else if (2 <= huePrime && huePrime < 3)
  {
    R1 = 0;
    G1 = chroma;
    B1 = x;
  }
  else if (3 <= huePrime && huePrime < 4)
  {
    R1 = 0;
    G1 = x;
    B1 = chroma;
  }
  else if (4 <= huePrime && huePrime < 5)
  {
    R1 = x;
    G1 = 0;
    B1 = chroma;
  }
  else if (5 <= huePrime && huePrime < 6)
  {
    R1 = chroma;
    G1 = 0;
    B1 = x;
  }
  
  // now add color match and normalize to set values
  _r = (R1 + match) / 255.0;
  _g = (G1 + match) / 255.0;
  _b = (B1 + match) / 255.0;

  _a = alpha; // set alpha channel directly, no adjustments necessary

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