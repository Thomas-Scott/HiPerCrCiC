#ifndef _Event_h_
#define _Event_h_

#include "CGClasses.h"

enum EventClassification {
  MOUSE_EVENT,
  KEYBOARD_EVENT,
  ALL,
  NONE
};

enum EventType {
  MOUSE_CLICK, MOUSE_DRAG,
  MOUSE_DOWN, MOUSE_MOVE, 
  MOUSE_OVER, MOUSE_OUT, MOUSE_UP, 
  FOCUS_IN, FOCUS_OUT, KEY_DOWN, 
  KEY_UP, KEY_PRESS
};

enum MouseButton {
  RIGHT_MOUSE_BUTTON,
  LEFT_MOUSE_BUTTON,
  MIDDLE_MOUSE_BUTTON
};

class Event
{
private: // private vars
  EventType _type;
public: // public vars

private: // private methods
  
public: // public methods
  Event(EventType type);
  Event( Event const& e );
  virtual ~Event();
  EventType getType() const { return _type; }
  void setType(EventType type) { _type = type; }
};

class MouseEvent : public Event
{
private: // private vars
  MouseButton _button;
  CGPoint _position;
public: // public vars

private: // private methods

public: // public methods
  MouseEvent(EventType type, MouseButton button, CGPoint const& position);
  MouseEvent(MouseEvent const& e);
  virtual ~MouseEvent();
  MouseButton getButton() const { return _button; }
  CGPoint getPosition() const { return _position; }

};

class KeyboardEvent : public Event
{
private: // private vars
  char _key;
public: // public vars

private: // private methods

public: // public methods
  KeyboardEvent(EventType type, unsigned char key);
  KeyboardEvent(KeyboardEvent const& e);
  virtual ~KeyboardEvent();
  char getKey() const { return _key; }
};

#endif // _Event_h_