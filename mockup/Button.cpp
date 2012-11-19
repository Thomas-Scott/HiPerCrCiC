#include "Button.h"
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<sstream>


bool Button::onButton(int x, int y)
{
  return x >= buttonPos[0]  && y >= buttonPos[1] &&
         x <= buttonPos[0] + buttonPos[2] &&
         y <= buttonPos[1] + buttonPos[3];
}

void Button::draw(){
	if ( buttonIsPressed ) glColor3f(1., 0., 0.);  // make it red
	else if ( overButton ) glColor3f(.75,.75,.75);  // light gray
	else glColor3f(.5, .5, .5);  // gray
	drawBox(buttonPos);
}

Button::Button(double x, double y, double width, double height){
	buttonPos=new double[4];
	buttonPos[0]=x;
	buttonPos[1]=y;
	buttonPos[2]=width;
	buttonPos[3]=height;
	buttonIsPressed=false;
	overButton=false;
}

Button::~Button(){
	delete [] buttonPos;
}

void Button::setPosition(double x, double y){
	buttonPos[0]=x;
	buttonPos[1]=y;
}

void Button::setWidth(double w){
	buttonPos[2]=w;
}

void Button::setHeight(double h){
	buttonPos[3]=h;
}

void Button::drawBox(double x, double y, double width, double height)
{
	glBegin(GL_POLYGON);
	glVertex2f(x, y);  // upper left
	glVertex2f(x, y + height);  // lower left
	glVertex2f(x + width, y + height);  // lower right
	glVertex2f(x + width, y);  // upper right
	glEnd();
}

void Button::drawBox(double *pos)
{
	drawBox(pos[0], pos[1], pos[2], pos[3]);
}
