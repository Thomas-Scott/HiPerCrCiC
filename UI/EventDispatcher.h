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

  // Event Listener Vectors
  set<View *> _mouseEventListeners;
  set<View *> _keyboardEventListeners; // keyboard events are prioritized to the element with focus
  View * _currentFocus; // recieves keyboard events unless it doesn't exist
public: // var

private: // method
  
  void processNextMouseEvent();
  void processNextKeyboardEvent();
public: // method
  EventDispatcher();
  ~EventDispatcher();

  void registerMouseListener(View * view);
  void registerKeyboardListener(View * view);

  bool removeMouseListenerWithPointer(View * const viewPointer);
  bool removeKeyboardListenerWithPointer(View * const viewPointer);

  void pushMouseEvent(MouseEvent e);
  void pushKeyboardEvent(KeyboardEvent e);

  void eventLoop();
};

#endif // _Event_Dispatch_h_