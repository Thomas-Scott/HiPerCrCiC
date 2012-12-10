// Michael Taufen 2012
#ifndef _Event_Dispatch_h_
#define _Event_Dispatch_h_

#include <queue>
#include <set>
#include "Event.h"
#include "View.h"
using namespace std;

class EventDispatcher
{
private: // var
  // Event Queues
  queue<MouseEvent> _mouseEventQueue;
  queue<KeyboardEvent> _keyboardEventQueue;
  queue<CrawlerEvent> _crawlerEventQueue;
  queue<JobManagerEvent> _jobManagerEventQueue;
  queue<QueryEngineEvent> _queryEngineEventQueue;

  // Event Listener Vectors
  set<View *> _mouseEventListeners;
  set<View *> _keyboardEventListeners; // keyboard events are prioritized to the element with focus
  set<View *> _crawlerEventListeners;
  set<View *> _jobManagerEventListeners;
  set<View *> _queryEngineEventListeners;
  View * _currentFocus; // recieves keyboard events unless it doesn't exist
public: // var

private: // method
  
  void processNextMouseEvent();
  void processNextKeyboardEvent();
  void processNextCrawlerEvent();
  void processNextJobManagerEvent();
  void processNextQueryEngineEvent();
public: // method
  EventDispatcher();
  ~EventDispatcher();

  void registerMouseListener(View * view);
  void registerKeyboardListener(View * view);
  void registerCrawlerListener(View * view);
  void registerJobManagerListener(View * view);
  void registerQueryEngineListener(View * view);

  bool removeMouseListenerWithPointer(View * const viewPointer);
  bool removeKeyboardListenerWithPointer(View * const viewPointer);
  bool removeCrawlerListenerWithPointer(View * const viewPointer);
  bool removeJobManagerListenerWithPointer(View * const viewPointer);
  bool removeQueryEngineListenerWithPointer(View * const viewPointer);

  void pushMouseEvent(MouseEvent e);
  void pushKeyboardEvent(KeyboardEvent e);
  void pushCrawlerEvent(CrawlerEvent e);
  void pushJobManagerEvent(JobManagerEvent e);
  void pushQueryEngineEvent(QueryEngineEvent e);

  void eventLoop();
};

#endif // _Event_Dispatch_h_