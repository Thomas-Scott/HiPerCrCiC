

#ifdef MACOSX
#include <GLUT/glut.h>
#else
//#include <GL/glut.h>
#endif
#include <GLUT/glut.h>
#include <iostream>
#include "CommonGLFunctions.h"
#include <algorithm>
using namespace std;

void drawRectWithColor( CGRect const& rect, CGColor const& color)
{
  //glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
  
  glColor3f(color.getRed(), color.getGreen(), color.getBlue());
  //glColor3f(0.2, 0.8, 0.2);
  cerr << "Values that just got passed: " << " " << color.getRed() << " " << color.getGreen() << " " << color.getBlue() << endl;

  double x0 = min(rect.getX(), rect.getX() + rect.getWidth());
  double x1 = max(rect.getX(), rect.getX() + rect.getWidth());
  double y0 = min(rect.getY(), rect.getY() + rect.getHeight());
  double y1 = max(rect.getY(), rect.getY() + rect.getHeight());
  glBegin(GL_QUADS);
    glVertex2d(x0, y0);
    glVertex2d(x1, y0);
    glVertex2d(x1, y1);
    glVertex2d(x0, y1);
  glEnd();
}

void drawBorderWithColor( CGRect const& rect, CGColor const& borderColor, int thickness, std::string format ) 
{
  // not the most efficient way to do it... but easy :)
  CGRect top(
    rect.getX(),
    rect.getY(),
    rect.getWidth(),
    thickness );
  CGRect bottom(
    rect.getX(),
    rect.getY() + rect.getHeight() - thickness,
    rect.getWidth(),
    thickness );
  CGRect left(
    rect.getX(),
    rect.getY(),
    thickness,
    rect.getHeight() );
  CGRect right(
    rect.getX() + rect.getWidth() - thickness,
    rect.getY(),
    thickness,
    rect.getHeight() );

  if (format.find("all") != std::string::npos)
  {
    drawRectWithColor(top, borderColor);
    drawRectWithColor(bottom, borderColor);
    drawRectWithColor(left, borderColor);
    drawRectWithColor(right, borderColor);
  }
  else
  {
    if (format.find("top") != std::string::npos)
    {
      drawRectWithColor(top, borderColor);
    }
    if (format.find("bottom") != std::string::npos)
    {
      drawRectWithColor(bottom, borderColor);
    }
    if (format.find("left") != std::string::npos)
    {
      drawRectWithColor(left, borderColor);
    }
    if (format.find("right") != std::string::npos)
    {
      drawRectWithColor(right, borderColor);
    }
  }
}

void drawLinearGradient( CGRect const& rect, CGColor const& startColor, CGColor const& endColor )
{
  double x0 = min(rect.getX(), rect.getX() + rect.getWidth());
  double x1 = max(rect.getX(), rect.getX() + rect.getWidth());
  double y0 = min(rect.getY(), rect.getY() + rect.getHeight());
  double y1 = max(rect.getY(), rect.getY() + rect.getHeight());
  glBegin(GL_QUADS);
    glColor3f(startColor.getRed(), startColor.getGreen(), startColor.getBlue()); // start
    glVertex2d(x0, y0);
    glVertex2d(x1, y0);
    glColor3f(endColor.getRed(), endColor.getGreen(), endColor.getBlue()); // end
    glVertex2d(x1, y1);
    glVertex2d(x0, y1);
  glEnd();
}

void drawStringWithColorAndFormat( std::string text, CGColor const& color, std::string format )
{

}

void drawClippedStringWithColorAndFormat( std::string text, CGColor const& color, std::string format, CGRect const& clippingRect )
{

}
