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

  // Event Listener Vectors
  set<View *> _mouseEventListeners;
  set<View *> _keyboardEventListeners; // keyboard events are prioritized to the element with focus
  set<View *> _crawlerEventListeners;
  View * _currentFocus; // recieves keyboard events unless it doesn't exist
public: // var

private: // method
  
  void processNextMouseEvent();
  void processNextKeyboardEvent();
  void processNextCrawlerEvent();
public: // method
  EventDispatcher();
  ~EventDispatcher();

  void registerMouseListener(View * view);
  void registerKeyboardListener(View * view);
  void registerCrawlerListener(View * view);

  bool removeMouseListenerWithPointer(View * const viewPointer);
  bool removeKeyboardListenerWithPointer(View * const viewPointer);
  bool removeCrawlerListenerWithPointer(View * const viewPointer);

  void pushMouseEvent(MouseEvent e);
  void pushKeyboardEvent(KeyboardEvent e);
  void pushCrawlerEvent(CrawlerEvent e);

  void eventLoop();
};

#endif // _Event_Dispatch_h_