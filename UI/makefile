OPTS = -Wall -g
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

all: UIApplication clean

UIApplication: UIApplication.o EventDispatcher.o Event.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o TextRenderView.o TextInputView.o GlobalState.o
	g++ $(OPTS) -o UIApplication UIApplication.o EventDispatcher.o Event.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o TextRenderView.o TextInputView.o GlobalState.o $(LIBS)

UIApplication.o: TabBarController.h UIApplication.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c UIApplication.cpp

EventDispatcher.o: Event.h View.h EventDispatcher.h EventDispatcher.cpp
	g++ $(OPTS) -c EventDispatcher.h EventDispatcher.cpp

Event.o: CGClasses.h Event.h Event.cpp
	g++ $(OPTS) -c Event.h Event.cpp

GlobalState.o: GlobalState.h
	g++ $(OPTS) -c GlobalState.h GlobalState.cpp

BarItem.o: View.h BarItem.h BarItem.cpp
	g++ $(OPTS) -c BarItem.h BarItem.cpp

TextInputView.o: View.h CommonGLFunctions.h TextInputView.h TextInputView.cpp
	g++ $(OPTS) -c TextInputView.h TextInputView.cpp

TextRenderView.o: View.h CommonGLFunctions.h TextRenderView.h TextRenderView.cpp
	g++ $(OPTS) -c TextRenderView.h TextRenderView.cpp

View.o: View.h View.cpp
	g++ $(OPTS) -c View.h View.cpp

TabBarViewController.o: ViewController.h TabBarViewController.h TabBarViewController.cpp
	g++ $(OPTS) -c TabBarViewController.h TabBarViewController.cpp

ViewController.o: ViewController.h ViewController.cpp
	g++ $(OPTS) -c ViewController.h ViewController.cpp

TabBarController.o: TabBarController.h TabBarController.cpp
	g++ $(OPTS) -c TabBarController.h TabBarController.cpp

CommonGLFunctions.o: CommonGLFunctions.h CommonGLFunctions.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c CommonGLFunctions.h CommonGLFunctions.cpp

CGClasses.o: CGClasses.h CGClasses.cpp
	g++ $(OPTS) -c CGClasses.h CGClasses.cpp

# Currently removing the precompiled headers because the dependency graph is working
# but not completely correct, so things don't exactly get done right on recompile
clean:
	rm -rf *.o *.gch UIApplication
