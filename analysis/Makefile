OPTS = -Wall -g
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
endif
LIBS = -lclucene -I/usr/common/include -lm -lobjc -lstdc++

Analysis: QueryEngine.o Indexer.o Messages.pb.o Docs.pb.o AnalysisMain.o
	g++ $(OPTS) -o Analysis QueryEngine.o Indexer.o AnalysisMain.o $(LIBS)
    
AnalysisMain.o: AnalysisMain.cpp AnalysisMain.h
	g++ $(OPTS) -c AnalysisMain.cpp

Messages.pb.o: Messages.pb.cc Messages.pb.h
	g++ $(OPTS) -c Messages.pb.cc

Docs.pb.o: Docs.pb.cc Docs.pb.h
	g++ $(OPTS) -c Docs.pb.cc 

QueryEngine.o: QueryEngine.cpp QueryEngine.h HardCoded.h
	g++ $(OPTS) -c QueryEngine.cpp 

Indexer.o: Indexer.cpp Indexer.h HardCoded.h
	g++ $(OPTS) -c Indexer.cpp
