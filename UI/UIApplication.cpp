#include <iostream>
#include <fstream>
using namespace std;

#ifdef MACOSX
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include <math.h>
#include <stdlib.h>
#include "TabBarController.h"

/*
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, windowWidth, 0.0, windowHeight, znear, zfar);

*/


bool mouseIsDragging = false;

int WIDTH = 720;  // width of the user window (640 + 80)
int HEIGHT = 540;  // height of the user window (480 + 60)
char programName[] = "Web Crawler UI Application";
TabBarController * masterController;


void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw stuff
  masterController->drawViews();

  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

// process keyboard events
void keyboard( unsigned char c, int x, int y )
{
  int win = glutGetWindow();
  switch(c) {
    case 'q':
    case 'Q':
    case 27:
      // get rid of the window (as part of shutting down)
      glutDestroyWindow(win);
      exit(0);
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

// the reshape function handles the case where the user changes the size
//   of the window.  We need to fix the coordinate
//   system, so that the drawing area is still the unit square.
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   WIDTH = w;  HEIGHT = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
}

// the mouse function is called when a mouse button is pressed down or released
void mouse(int button, int state, int x, int y)
{
  if ( GLUT_LEFT_BUTTON == button ) {
    if ( GLUT_DOWN == state )
    {
      mouseIsDragging = true;
      // the user just pressed down on the mouse-- do something

    }
    else
    {
      
      mouseIsDragging = false;
      // the user just let go the mouse-- do something
      masterController->mouseClickHandler( CGPoint(x, y) );
    }
  } 
  else if ( GLUT_RIGHT_BUTTON == button )
  {
    // right click stuff here
  }
  glutPostRedisplay();
}

// the mouse_motion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouse_motion(int x,int y)
{
  // the mouse button is pressed, and the mouse is moving....

  glutPostRedisplay();
}

// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);

  // welcome message
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
  char *argv[] = {programName};
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  //glEnable (GL_BLEND);
  //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  glutDisplayFunc(drawWindow);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutMainLoop();
}

void loadUIComponents()
{
  masterController = new TabBarController( CGRect(0,0,WIDTH,HEIGHT) );

  ViewController * content1 = new ViewController();
  ViewController * content2 = new ViewController();
  ViewController * content3 = new ViewController();
  content2->getMasterView()->setBackgroundColor( CGColor(0.5, 0.5, 0.8, 1.0) );

  masterController->addTab("Test Tab", content1);
  masterController->addTab("Test Tab 2", content2);
  masterController->addTab("Test Tab 3", content3);
}

int main()
{
  loadUIComponents();
  init_gl_window();
}
