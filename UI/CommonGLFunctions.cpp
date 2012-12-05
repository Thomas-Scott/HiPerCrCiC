

#ifdef MACOSX
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include "CommonGLFunctions.h"
#include <algorithm>
#include "GlobalState.h"
using namespace std;

void drawRectWithColor( CGRect const& rect, CGColor const& color)
{
  //glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
  
  glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
  //glColor3f(0.2, 0.8, 0.2);
  // cerr << "Values that just got passed: " << " " << color.getRed() << " " << color.getGreen() << " " << color.getBlue() << endl;

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
    glColor4f(startColor.getRed(), startColor.getGreen(), startColor.getBlue(), startColor.getAlpha()); // start
    glVertex2d(x0, y0);
    glVertex2d(x1, y0);
    glColor4f(endColor.getRed(), endColor.getGreen(), endColor.getBlue(), endColor.getAlpha()); // end
    glVertex2d(x1, y1);
    glVertex2d(x0, y1);
  glEnd();
}

void drawStringWithColorAndFormat( std::string text, CGColor const& color, CGPoint const& position, std::string format )
{
  glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
  glRasterPos2f(position.getX(), position.getY());
  //glColor3f(color.getRed(), color.getGreen(), color.getBlue());
  int length = text.length();

  if (format.find("big") != std::string::npos)
  {
    for (int i = 0; i < length; ++i)
      if (text[i] != '\n')
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
  }
  else if (format.find("medium") != std::string::npos)
  {
    for (int i = 0; i < length; ++i)
      if (text[i] != '\n')
      {
        if (format.find("fixed") != std::string::npos)
          glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
        else
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
      }
  }
  else if (format.find("small") != std::string::npos)
  {
    for (int i = 0; i < length; ++i)
      if (text[i] != '\n')
      {
        if (format.find("fixed") != std::string::npos)
          glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
        else
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
      }
  }
  else // default size is 18 == big
  {
    for (int i = 0; i < length; ++i)
      if (text[i] != '\n') // don't draw newline characters
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
  }

}

void enableClippingRect()
{
  glEnable(GL_SCISSOR_TEST);
}

void disableClippingRect()
{
  glDisable(GL_SCISSOR_TEST);
}

void setClippingRect(CGRect const& rect)
{
  // since x and y are the upper left in our coord. systen,
  // but the lower left of the scissor box in OpenGL's coordinate system,
  // we need to set the Y to winHeight - (Y + HEIGHT) to transform to openGL
  glScissor(rect.getX(), GlobalState::winHeight - (rect.getY() + rect.getHeight()), rect.getWidth(), rect.getHeight());
}

CGRect getClippingRect()
{
  GLint box[4];
  glGetIntegerv(GL_SCISSOR_BOX, box);
  CGRect temp(box[0],box[1],box[2],box[3]);
  // since x and y are the upper left in our coord. systen,
  // but the lower left of the scissor box in OpenGL's coordinate system,
  // we need to set the Y to winHeight - (Y + HEIGHT) to transform back to our coord. system
  temp.setY( GlobalState::winHeight - (temp.getY() + temp.getHeight()) );
  return temp;
}
