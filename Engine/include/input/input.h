#pragma once
#include "keyboard.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <deque>
#include <array>
#include <iostream>

class Input_manager {
public:

	Input_manager(size_t buffer_size = 10);

	void update();

	bool is_key_pressed(Key key) const;
	bool is_key_held(Key key) const;
	bool is_key_released(Key key) const;

	bool was_key_pressed_within(Key key, size_t frames) const;

	void debug();

	bool has_event();

private:
	size_t m_buffer_size;

	using KeyBoardState = std::array<bool, sf::Keyboard::KeyCount>;

	std::deque<KeyBoardState> m_buffer;

};