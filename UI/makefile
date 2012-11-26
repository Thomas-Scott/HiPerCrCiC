OPTS = -Wall -g
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

all: clean UIApplication

UIApplication: UIApplication.o EventDispatcher.o Event.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o TextRenderView.o TextInputView.o TitledTextInputView.o ToggleButton.o TitledToggleButton.o GlobalState.o SetupViewController.o Button.o ScrollBar.o ScrollView.o
	g++ $(OPTS) -o UIApplication UIApplication.o EventDispatcher.o Event.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o TextRenderView.o TextInputView.o TitledTextInputView.o ToggleButton.o TitledToggleButton.o GlobalState.o SetupViewController.o Button.o ScrollBar.o ScrollView.o $(LIBS)

UIApplication.o: TabBarController.h UIApplication.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c UIApplication.cpp

EventDispatcher.o: Event.h View.h EventDispatcher.h EventDispatcher.cpp
	g++ $(OPTS) -c EventDispatcher.h EventDispatcher.cpp

Event.o: CGClasses.h Event.h Event.cpp
	g++ $(OPTS) -c Event.h Event.cpp

GlobalState.o: GlobalState.h
	g++ $(OPTS) -c GlobalState.h GlobalState.cpp

Button.o: View.h TextRenderView.h Button.h Button.cpp
	g++ $(OPTS) -c Button.h Button.cpp

ScrollView.o: Scrollbar.h ScrollView.h ScrollView.cpp
	g++ $(OPTS) -c ScrollView.h ScrollView.cpp

ScrollBar.o: View.h ScrollBar.h ScrollBar.cpp
	g++ $(OPTS) -c ScrollBar.h ScrollBar.cpp

BarItem.o: View.h BarItem.h BarItem.cpp
	g++ $(OPTS) -c BarItem.h BarItem.cpp

SetupViewController.o: TitledToggleButton.h TitledTextInputView.h SetupViewController.h SetupViewController.cpp
	g++ $(OPTS) -c SetupViewController.h SetupViewController.cpp

TitledToggleButton.o: View.h TextRenderView.h ToggleButton.h ToggleButton.cpp
	g++ $(OPTS) -c TitledToggleButton.h TitledToggleButton.cpp 

ToggleButton.o: View.h ToggleButton.h ToggleButton.cpp
	g++ $(OPTS) -c ToggleButton.h ToggleButton.cpp

TitledTextInputView.o: View.h TitledTextInputView.h TitledTextInputView.cpp
	g++ $(OPTS) -c TitledTextInputView.h TitledTextInputView.cpp

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
