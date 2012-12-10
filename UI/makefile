OPTS = -Wall -g
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -lclucene -I/usr/include -I/usr/include/GL -L/usr/lib -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++ -lcurl

endif

all: clean UIApplication

UIApplication: UIApplication.o EventDispatcher.o Event.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o TextRenderView.o TextInputView.o TitledTextInputView.o ToggleButton.o TitledToggleButton.o GlobalState.o SetupViewController.o Button.o ScrollBar.o ScrollView.o DynamicTextInputView.o TextInputScrollView.o SearchViewController.o StatusViewController.o QueueNode.o Parser.o Crawler.o TextScrollView.o JobInfo.o JobManager.o JobList.o JobListItem.o ProgressBar.o CancelButton.o ClippedTextView.o Indexer.o QueryEngine.o ResultList.o ResultListItem.o ResultInfo.o
	g++ $(OPTS) -o UIApplication UIApplication.o EventDispatcher.o Event.o CGClasses.o CommonGLFunctions.o TabBarController.o ViewController.o TabBarViewController.o View.o BarItem.o TextRenderView.o TextInputView.o TitledTextInputView.o ToggleButton.o TitledToggleButton.o GlobalState.o SetupViewController.o Button.o ScrollBar.o ScrollView.o DynamicTextInputView.o TextInputScrollView.o SearchViewController.o StatusViewController.o QueueNode.o Parser.o Crawler.o TextScrollView.o JobInfo.o JobManager.o JobList.o JobListItem.o ProgressBar.o CancelButton.o ClippedTextView.o Indexer.o QueryEngine.o ResultList.o ResultListItem.o ResultInfo.o $(LIBS)

ResultList.o: ResultList.h ResultList.cpp
	g++ $(OPTS) -c ResultList.h ResultList.cpp

ResultListItem.o: ResultListItem.h ResultListItem.cpp
	g++ $(OPTS) -c ResultListItem.h ResultListItem.cpp

ResultInfo.o: ../analysis/ResultInfo.h ../analysis/ResultInfo.cpp
	g++ $(OPTS) -c ../analysis/ResultInfo.h ../analysis/ResultInfo.cpp 

QueryEngine.o: ../analysis/QueryEngine.cpp ../analysis/QueryEngine.h ../analysis/HardCoded.h
	g++ $(OPTS) -c ../analysis/QueryEngine.h ../analysis/QueryEngine.cpp 

Indexer.o: ../analysis/Indexer.cpp ../analysis/Indexer.h ../analysis/HardCoded.h
	g++ $(OPTS) -c ../analysis/Indexer.h ../analysis/Indexer.cpp

QueueNode.o: ../core/QueueNode.h ../core/queuenode.cpp
	g++ $(OPTS) -c ../core/QueueNode.h ../core/queuenode.cpp

Parser.o: ../core/Parser.h ../core/parser.cpp
	g++ $(OPTS) -c ../core/Parser.h ../core/parser.cpp

Crawler.o: ../core/Crawler.h ../core/crawler.cpp
	g++ $(OPTS) -c ../core/Crawler.h ../core/crawler.cpp

JobList.o: JobList.h JobList.cpp
	g++ $(OPTS) -c JobList.h JobList.cpp

JobListItem.o: JobListItem.h JobListItem.cpp
	g++ $(OPTS) -c JobListItem.h JobListItem.cpp

ClippedTextView.o: ClippedTextView.h ClippedTextView.cpp
	g++ $(OPTS) -c ClippedTextView.h ClippedTextView.cpp

CancelButton.o: CancelButton.h CancelButton.cpp
	g++ $(OPTS) -c CancelButton.h CancelButton.cpp

ProgressBar.o: ProgressBar.h ProgressBar.cpp
	g++ $(OPTS) -c ProgressBar.h ProgressBar.cpp

JobManager.o: ../core/JobManager.h ../core/JobManager.cpp
	g++ $(OPTS) -c ../core/JobManager.h ../core/JobManager.cpp

JobInfo.o: ../core/JobInfo.h ../core/JobInfo.cpp
	g++ $(OPTS) -c ../core/JobInfo.h ../core/JobInfo.cpp

UIApplication.o:  GlobalState.h TabBarController.h EventDispatcher.h TextInputView.h TitledTextInputView.h ToggleButton.h TitledToggleButton.h SetupViewController.h UIApplication.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c UIApplication.cpp

EventDispatcher.o: Event.h View.h EventDispatcher.h EventDispatcher.cpp
	g++ $(OPTS) -c EventDispatcher.h EventDispatcher.cpp

Event.o: CGClasses.h Event.h Event.cpp
	g++ $(OPTS) -c Event.h Event.cpp

GlobalState.o: GlobalState.h
	g++ $(OPTS) -c GlobalState.h GlobalState.cpp

TextScrollView.o: TextScrollView.h TextScrollView.cpp
	g++ $(OPTS) -c TextScrollView.h TextScrollView.cpp

TextInputScrollView.o: ScrollView.h TextInputScrollView.h TextInputScrollView.cpp
	g++ $(OPTS) -c TextInputScrollView.h TextInputScrollView.cpp

DynamicTextInputView.o: View.h DynamicTextInputView.h DynamicTextInputView.cpp
	g++ $(OPTS) -c DynamicTextInputView.h DynamicTextInputView.cpp

Button.o: View.h TextRenderView.h Button.h Button.cpp
	g++ $(OPTS) -c Button.h Button.cpp

ScrollView.o: Scrollbar.h ScrollView.h ScrollView.cpp
	g++ $(OPTS) -c ScrollView.h ScrollView.cpp

ScrollBar.o: View.h ScrollBar.h ScrollBar.cpp
	g++ $(OPTS) -c ScrollBar.h ScrollBar.cpp

BarItem.o: View.h BarItem.h BarItem.cpp
	g++ $(OPTS) -c BarItem.h BarItem.cpp

SearchViewController.o: TitledToggleButton.h TitledTextInputView.h SearchViewController.h SearchViewController.cpp
	g++ $(OPTS) -c SearchViewController.h SearchViewController.cpp

StatusViewController.o: TitledToggleButton.h TitledTextInputView.h StatusViewController.h StatusViewController.cpp
	g++ $(OPTS) -c StatusViewController.h StatusViewController.cpp

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
	rm -rf ../UI/*.o ../UI/*.gch ../analysis/*.o ../analysis/*.gch ../core/*.o ../core/*.gch UIApplication
