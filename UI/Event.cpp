#include "Event.h"

Event::Event( EventType type ) : _type(type) {}
Event::Event( Event const& e ) : _type(e.getType()) {}

MouseEvent::MouseEvent( EventType type, MouseButton button, CGPoint position ) : Event(type), _button(button), _position(position) {}
MouseEvent::MouseEvent( MouseEvent const& e ) : Event(e), _button(e.getButton()), _position(e.getPosition()) {}

KeyboardEvent::KeyboardEvent( EventType type, char key ) : Event(type), _key(key) {}
KeyboardEvent::KeyboardEvent( KeyboardEvent const& e ) : Event(e), _key(e.getKey()) {}
