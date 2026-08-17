#include "event.h"

static bool compare_with_sfml(Event e, sf::Event& sf_e){
	if (sf_e.is<sf::Event::KeyPressed>() && e.type == Event_type::Key_pressed) return true;
	else if (sf_e.is<sf::Event::KeyReleased>() && e.type == Event_type::Key_released) return true;
	else return false;
}

Event::Event(){
	name = "*";
	type = Event_type::Idle;
}

Event::Event(const std::string n, const Event_type t){
	name = n;
	type = t;
}

Event::Event(const std::string n){
	name = n;
	type = Event_type::Idle;
}

Event& Event::operator=(const Event other){
	if (name != other.name) name = other.name;
	if (type != other.type) type = other.type;
	
	return *this;
}

Event& Event::operator=(const sf::Event& sf_event){
	if (sf_event.is<sf::Event::KeyPressed>() && type == Event_type::Idle) type = Event_type::Key_pressed;
	else if (sf_event.is<sf::Event::KeyReleased>() && type == Event_type::Idle) type = Event_type::Key_released;

	return *this;
}
