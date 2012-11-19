#include <iostream>
#include <string.h>
#include <GL/glut.h>
#include "Textbox.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

void Textbox::draw(){
	glColor3f(.25,.25,.25);
        drawBox(textBox);
	if (overTextBox) glColor3f(1,1,1);  //black
	else glColor3f(1,1,1);
	drawBox(innerBox);
	glColor3f(0,0,0);  // white
	if ( overTextBox ) { // draw with a cursor
		string withCursor(textInBox);
		withCursor += '|';
		Textbox::drawText( innerBox[0]+5, innerBox[1]+innerBox[3]-10, withCursor.c_str() );
  	} else Textbox::drawText( innerBox[0]+5, innerBox[1]+innerBox[3]-10, textInBox );
}

void Textbox::drawText(double x, double y, const char *text)
{
  glRasterPos2f( x, y );
  int length = strlen(text);
  for (int j = 0; j < length; j++){
    	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[j]);
	}
}

Textbox::Textbox(double x, double y, double width, double height){
	textInBox=new char[80];
	for (int i=0;i<80;i++) textInBox[i]=' ';
	overTextBox=false;
	textBox=new double[4]{x,y,width,height};
	innerBox=new double[4]{x+5,y+5,width-10,height-10};
}

Textbox::~Textbox(){
	delete [] textBox;
	delete [] innerBox;
	//delete [] textInBox;
}

void Textbox::setText(const char * t){
	strcpy(textInBox,t);	
}

void Textbox::drawBox(double x, double y, double width, double height)
{
        glBegin(GL_POLYGON);
        glVertex2f(x, y);  // upper left
        glVertex2f(x, y + height);  // lower left
        glVertex2f(x + width, y + height);  // lower right
        glVertex2f(x + width, y);  // upper right
        glEnd();
}
void Textbox::drawBox(double * pos)
{
        drawBox(pos[0], pos[1], pos[2], pos[3]);
}

void Textbox::drawBox()
{
        drawBox(textBox[0], textBox[1], textBox[2], textBox[3]);
	drawBox(innerBox[0],innerBox[1],innerBox[2],innerBox[3]);
}
