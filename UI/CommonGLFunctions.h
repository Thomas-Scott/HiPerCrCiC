#ifndef _Common_GL_Functions_h_
#define _Common_GL_Functions_h_

#ifdef MACOSX
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "CGClasses.h"
#include <algorithm>
using namespace std;

void drawRectWithColor( CGRect const& rect, CGColor const& color)
{
  glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
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

#endif //_Common_GL_Functions_h_