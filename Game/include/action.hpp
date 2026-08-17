#pragma once

#include <input.h>
#include <event.h>
#include "pch.h"

class Player;

struct Action{
	std::string name;
	bool state = false;

	Key k_bind = sf::Keyboard::Key::Unknown;
	Event e_bind = Event::Event("action_event", Event_type::Idle);

	Action(std::string n, Key k);
	Action(std::string n, Event e);

	operator bool() const;
};
