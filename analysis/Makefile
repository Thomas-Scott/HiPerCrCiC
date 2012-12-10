OPTS = -Wall -g
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
endif
LIBS = -lclucene -I/usr/local/include -lm -lobjc -lstdc++

Analysis: QueryEngine.o Indexer.o AnalysisMain.o
	g++ $(OPTS) -o Analysis QueryEngine.o Indexer.o AnalysisMain.o $(LIBS)
    
AnalysisMain.o: AnalysisMain.cpp AnalysisMain.h
	g++ $(OPTS) -c AnalysisMain.cpp

QueryEngine.o: QueryEngine.cpp QueryEngine.h HardCoded.h
	g++ $(OPTS) -c QueryEngine.cpp 

Indexer.o: Indexer.cpp Indexer.h HardCoded.h
	g++ $(OPTS) -c Indexer.cpp
