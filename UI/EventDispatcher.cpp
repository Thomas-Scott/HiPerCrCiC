#include "EventDispatcher.h"
#include <iostream>

EventDispatcher::EventDispatcher()
{
  _currentFocus = 0; // should always be null unless something has focus
}

void EventDispatcher::registerMouseListener(View * view)
{
  _mouseEventListeners.insert(view);
}

void EventDispatcher::registerKeyboardListener(View * view)
{
  _keyboardEventListeners.insert(view);
}

bool EventDispatcher::removeMouseListenerWithPointer(View * const viewPointer)
{
  set<View*>::iterator it = _mouseEventListeners.find(viewPointer);
  if (it != _mouseEventListeners.end())
  {
    _mouseEventListeners.erase(it);
    return true;
  }
  else
  {
    std::cout << "Error:\tNo listener could be matched with provided pointer. [In: EventDispatcher::removeKeyboardListenerWithPointer(View * const viewPointer)]" << std::endl;
    return false;
  }
}

bool EventDispatcher::removeKeyboardListenerWithPointer(View * const viewPointer)
{
  set<View*>::iterator it = _keyboardEventListeners.find(viewPointer);
  if (it != _keyboardEventListeners.end())
  {
    _keyboardEventListeners.erase(it);
    return true;
  }
  else
  {
    std::cout << "Error:\tNo listener could be matched with provided pointer. [In: EventDispatcher::removeKeyboardListenerWithPointer(View * const viewPointer)]" << std::endl;
    return false;
  }
}

void EventDispatcher::pushMouseEvent(MouseEvent e)
{
  _mouseEventQueue.push(e);
}

void EventDispatcher::pushKeyboardEvent(KeyboardEvent e)
{
  _keyboardEventQueue.push(e);
}

void EventDispatcher::processNextMouseEvent()
{
  if (_mouseEventQueue.size() > 0)
  {
    MouseEvent e(_mouseEventQueue.front());
    if (_mouseEventListeners.size() > 0)
    {
      for (set<View*>::iterator it = _mouseEventListeners.begin();
       it != _mouseEventListeners.end(); ++it)
      {
        switch(e.getType())
        {
          case MOUSE_LEFT_CLICK:
            (*it)->onLeftClick(e.getPosition());
            if ( (*it)->getFocusable() ) // give focus if focusable
            {
              _currentFocus = (*it);
              _currentFocus->onFoucsIn();
            }
            else // if this is a non-focusable element, remove focus from whatever has it
            {
              _currentFocus->onFocusOut();
              _currentFocus = 0;
            }
            break;
          case MOUSE_RIGHT_CLICK:
            (*it)->onRightClick(e.getPosition());
            break;
          case MOUSE_UP:
            (*it)->onMouseUp(e.getPosition());
            break;
          case MOUSE_DOWN:
            (*it)->onMouseDown(e.getPosition());
            break;
          case MOUSE_MOVE:
            (*it)->onMouseMove(e.getPosition());
            break;
          case MOUSE_OVER:
            (*it)->onMouseOver(e.getPosition());
            break;
          case MOUSE_OUT:
            (*it)->onMouseOut(e.getPosition());
            break;
          default:
            // do nothing, event is discarded
            break;
        }
      }
    }
    _mouseEventQueue.pop();
  }
}

void EventDispatcher::processNextKeyboardEvent()
{
  if (_keyboardEventQueue.size() > 0)
  {
    KeyboardEvent e(_keyboardEventQueue.front());
    if (_keyboardEventListeners.size() > 0)
    {
      if (!_currentFocus)
      {
        for (set<View*>::iterator it = _keyboardEventListeners.begin();
         it != _keyboardEventListeners.end(); ++it)
        {
          switch(e.getType())
          {
            case KEY_PRESS:
              (*it)->onKeyDown(e.getKey());
              break;
            case KEY_DOWN:
              (*it)->onRightClick(e.getKey());
              break;
            case KEY_UP:
              (*it)->onMouseUp(e.getKey());
              break;
            default:
              // do nothing, event is discarded
              break;
          }
        }
      }
      // pass the keyboard events to whatever view has focus, if it is an event listener
      else if (_keyboardEventListeners.find(_currentFocus) != _keyboardEventListeners.end())
      {
        switch(e.getType())
        {
          case KEY_PRESS:
            (_currentFocus)->onKeyDown(e.getKey());
            break;
          case KEY_DOWN:
            (_currentFocus)->onRightClick(e.getKey());
            break;
          case KEY_UP:
            (_currentFocus)->onMouseUp(e.getKey());
            break;
          default:
            // do nothing, event is discarded
            break;
        }
      }
    }
    _keyboardEventQueue.pop();
  }
}


void EventDispatcher::eventLoop()
{
  processNextMouseEvent();
  processNextKeyboardEvent();
}