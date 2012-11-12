OPTS = -Wall -g
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

all: UIApplication clean

UIApplication: UIApplication.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o 
	g++ $(OPTS) -o UIApplication UIApplication.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o $(LIBS)

UIApplication.o: UIApplication.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c UIApplication.cpp

BarItem.o: BarItem.h BarItem.cpp
	g++ $(OPTS) -c BarItem.h BarItem.cpp

View.o: View.h View.cpp
	g++ $(OPTS) -c View.h View.cpp

TabBarViewController.o: TabBarViewController.h TabBarViewController.cpp
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
