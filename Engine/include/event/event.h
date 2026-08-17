#pragma once

#include "keyboard.h"
#include <iostream>

enum class Event_type {
	//Keyboard event types
	Idle = false,

	Key_pressed = 1,
	Key_released = 2,

	//Mouse event types
	Mouse_button_pressed = 3,
	Mouse_button_released = 4,
	Mouse_move = 5,
	Mouse_wheel_scrolled = 6,

	//Gamepad event types
	Gamepad_button_pressed = 7,
	Gamepad_button_released = 8,
	Gamepad_axis_moved = 9,

	//Window event type
	Window_closed = 10,
	Window_resized = 11,
	Window_focused = 12
};

class Event {
public:
	std::string name;

	Event_type type = Event_type::Idle;

	Key event_key = sf::Keyboard::Key::Unknown;

	Event();

	Event(const std::string n, const Event_type t);

	Event(const std::string n);

	Event& operator=(const Event other);

	Event& operator=(const sf::Event& sf_event);

};

static bool compare_with_sfml(Event e, sf::Event& sf_e);