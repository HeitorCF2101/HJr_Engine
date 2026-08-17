#pragma once

#include "action.hpp"
#include "pch.h"

class Player : public sf::Transformable {
private:
	std::size_t a_buffer_max_size = 10;
	std::vector<Action> a_buffer = {};
	
	Action idle = Action("idle", sf::Keyboard::Key::Unknown);
	Action move_up = Action("move_up", sf::Keyboard::Key::W);
	Action move_down = Action("move_down", sf::Keyboard::Key::S);
	Action move_right = Action("move_right", sf::Keyboard::Key::D);
	Action move_left = Action("move_left", sf::Keyboard::Key::A);

public:
	std::string name = " ";
	float hp = 0.f;

	sf::Vector2f position = {0 , 0};
	float x = position.x;
	float y = position.y;

	sf::CircleShape debug_sprite = sf::CircleShape::CircleShape(20.f);

	Player() = default;

	static Player debug_player();

	void update();
};