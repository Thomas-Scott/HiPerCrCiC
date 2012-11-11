OPTS = -Wall -g
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

all: proto-draw clean 

proto-draw: proto-draw.o ColorPoint2.o Shape.o Rectangle.o Circle.o
	g++ $(OPTS) -o proto-draw ColorPoint2.o proto-draw.o Shape.o Rectangle.o Circle.o $(LIBS)

proto-draw.o: Rectangle.h Circle.h proto-draw.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-draw.cpp

Circle.o: Circle.h Circle.cpp
	g++ -g -c Circle.h Circle.cpp

Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -g -c Rectangle.h Rectangle.cpp

Shape.o: Shape.h Shape.cpp
	g++ -g -c Shape.h Shape.cpp

ColorPoint2.o: ColorPoint2.h ColorPoint2.cpp
	g++ -g -c ColorPoint2.h ColorPoint2.cpp

clean:
	rm -rf *.o ShapeDriver RectangleDriver CircleDriver ShapeDriver1 ShapeDriver2