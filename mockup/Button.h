#ifndef _BUTTON_
#define _BUTTON_
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<sstream>

class Button{
	bool buttonIsPressed=false;
	bool overButton=false;
	double * buttonPos;
	void drawBox(double x, double y, double width, double height);
	void drawBox(double* pos);
	public:
		Button(double x, double y, double width, double height);
		~Button();
		bool getPressed() {return buttonIsPressed;}
		bool getOver() {return overButton;}
		void draw();
		bool onButton(int x,int y);
		void setHeight(double h);
		void setWidth(double w);
		void setPosition(double x, double y);
};
#endif // _BUTTON_
