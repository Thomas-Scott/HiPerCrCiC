#ifndef _TEXTBOX_
#define _TEXTBOX_

class Textbox{
	double * textBox;
	double * innerBox;
	char * textInBox;
	bool overTextBox;
	void drawBox(double x, double y, double width, double height);
	void drawBox(double * pos);
	void drawBox();
	public:
		void draw();
		Textbox(double x, double y, double width, double height);
		~Textbox();
		void drawText(double x, double y, const char *);
		void setText(const char * t);
};


#endif //_TEXTBOX_
