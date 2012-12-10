// Michael Taufen 2012
#ifndef _Common_GL_Functions_h_
#define _Common_GL_Functions_h_

#include <string>
#include "CGClasses.h"

void drawRectWithColor(
  CGRect const& rect,
  CGColor const& color );

void drawBorderWithColor( 
  CGRect const& rect,
  CGColor const& borderColor,
  int thickness = 2,
  std::string format = "all");

void drawLinearGradient(
  CGRect const& rect,
  CGColor const& startColor,
  CGColor const& endColor );

void drawStringWithColorAndFormat(
  std::string text,
  CGColor const& color,
  CGPoint const& position,
  std::string format = "");

void enableClippingRect();
void disableClippingRect();
void setClippingRect(CGRect const& rect);
CGRect getClippingRect();
CGRect getSubClippingRect(CGRect const& rect); //makes a clipping rect based off of the visible space in the intersection of the argument and the current clipping rect

#endif //_Common_GL_Functions_h_