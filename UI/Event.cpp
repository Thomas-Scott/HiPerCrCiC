#include "Event.h"

Event::Event( EventType type ) : _type(type) {}
Event::Event( Event const& e ) : _type(e.getType()) {}
Event::~Event()
{

}

MouseEvent::MouseEvent( EventType type, MouseButton button, CGPoint const& position ) : Event(type), _button(button), _position(position) {}
MouseEvent::MouseEvent( MouseEvent const& e ) : Event(e), _button(e.getButton()), _position(e.getPosition()) {}
MouseEvent::~MouseEvent()
{
  
}

KeyboardEvent::KeyboardEvent( EventType type, unsigned char key ) : Event(type), _key(key) {}
KeyboardEvent::KeyboardEvent( KeyboardEvent const& e ) : Event(e), _key(e.getKey()) {}
KeyboardEvent::~KeyboardEvent()
{
  
}



CrawlerEvent::CrawlerEvent(EventType type, std::string data) : Event(type), _data(data) {}
CrawlerEvent::CrawlerEvent(CrawlerEvent const& e) : Event(e), _data(e.getDataString()) {}
CrawlerEvent::~CrawlerEvent()
{

}
