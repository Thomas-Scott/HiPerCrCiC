
#include<iostream>
#include<fstream>
using namespace std;
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<sstream>
#include "Button.h"
#include "Textbox.h"

int WIDTH = 700;  // width of the user window
int HEIGHT = 400;  // height of the user window
char programName[] = "HiPerCrCiC";
int stage=0;

Button startButton (550,300,125,75);
Button loadConfig (50,75,100,50);
Button saveConfig (50,150,100,50);

Textbox startPage (300,175,400,30);
Textbox maxCount (300,225,400,30);
Textbox blacklisted (300,125,400,30);
Textbox allowedDomains (300,75,400,30);
Textbox progress (150,300,350,30);
Textbox query (300,25,250,30);

void drawText(double x, double y, const char *text)
{
  glRasterPos2f( x, y );
  int length = strlen(text);
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
}


void drawWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	startButton.draw();
	loadConfig.draw();
	saveConfig.draw();
	
	startPage.draw();
	maxCount.draw();
	blacklisted.draw();
	allowedDomains.draw();
	query.draw();

	progress.draw();

	drawText(50,100,"Load Config");
	drawText(50,175,"Save Config");
	//query.setText("smdsf");	
	drawText(165, 45,"Query:");	
	drawText(165,190,"Start Page:");
	drawText(165,240,"Max Count:");
	drawText(165,140,"BlackListed:");
	drawText(165,90,"Allow Domains:");
	drawText(588,340,"START");
	drawText(75,315,"Status:");
	glutSwapBuffers();
}

void step(int i){
	switch (i){
		case 1:
			progress.setText("Welcome!");
			break;
		case 2:
			query.setText("schmorkleblinxx");
			break;
		case 3:
			allowedDomains.setText("http://www.cnn.com;http://www.zombo.com");
			break;
		case 4:
			blacklisted.setText("http://www.wikipedia.com;http://www.fox.com");
			break;
		case 5:
			startPage.setText("http://www.cnn.com/walrus_llama_death_match");
			break;
		case 6:
			maxCount.setText("9,261");
			break;
		case 7:
			progress.setText("Starting up!");
			break;
		case 8:
			progress.setText("Grabbed: 5/10,000 pages");
			break;
		case 9:
			progress.setText("Crawling completed!");
			break;
		case 10:
			progress.setText("Analysis beginning...");
			break;
		case 11:
			progress.setText("Indexing web pages.");
			break;
		case 12:
			progress.setText("Searching for query hits...");
			break;
		case 13:
			progress.setText("Search completed.");
			break;
		case 14:
			progress.setText("Outputting data...");
			break;
		case 15:
			progress.setText("HiPerCrCiC task complete.");
			break;
	}
}


void exitAll()
{
	int win = glutGetWindow();
	glutDestroyWindow(win);
	exit(0);
}

void keyboard( unsigned char c, int x, int y )
{
	switch(c) {
		case ' ':
			stage++;
			step(stage);
			break;
		case 'q':
		case 'Q':
		case 27:
			exitAll();
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   WIDTH = w;  HEIGHT = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
  cout << "Welcome to " << programName << "." << endl;
}


// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.
void init_gl_window()
{
  char *argv[] = { programName };
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  glutDisplayFunc(drawWindow);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  //Commented out mouse functions for demonstration purposes.
  //glutMouseFunc(mouse);
  //glutMotionFunc(mouse_motion);
  //glutPassiveMotionFunc(mouse_motion);
  glutMainLoop();
}

int main()
{
	init_gl_window();
	exitAll();
}
