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

void drawClippedStringWithColorAndFormat(
  std::string text,
  CGColor const& color,
  std::string format,
  CGRect const& clippingRect);

#endif //_Common_GL_Functions_h_