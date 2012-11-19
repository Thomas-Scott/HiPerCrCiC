# this Makefile is intended to make any of the examples in this directory
#all:  proto-texture proto-ui proto-ui2 proto-counting proto-windows proto-sound proto-chat 

# the following lines pertain to using sound
# if you download FMOD onto your own machine, change the line below
FMOD_DIR = /usr/local/dept/apps/fmod
FMOD_INCLUDE = -I$(FMOD_DIR)/api/inc -I$(FMOD_DIR)/examples/common
FMOD_LIB = $(FMOD_DIR)/api/lib/libfmodex64.so

# the following lines pertain to setting up compiler options and libraries
OPTS = -Wall -g -std=c++11
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif
make-all: clean uiclass

uiclass: uiclass.o Textbox.o Button.o
	g++ $(OPTS) $(MACOSX_DEFINE) -o uiclass uiclass.o Textbox.o Button.o $(LIBS)

proto-ui: proto-ui.o
	g++ $(OPTS) -o proto-ui proto-ui.o $(LIBS)

proto-ui.o: proto-ui.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-ui.cpp

proto-ui2: proto-ui2.o texture.o
	g++ $(OPTS) -o proto-ui2 proto-ui2.o texture.o $(LIBS)

proto-ui2.o: proto-ui2.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-ui2.cpp

Button.o: Button.cpp Button.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c Button.cpp

Textbox.o: Textbox.cpp Textbox.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c Textbox.cpp

Printbox.o: Printbox.cpp Printbox.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c Printbox.cpp

clean:
	rm -rf *.o *.gch uiclass proto-ui
