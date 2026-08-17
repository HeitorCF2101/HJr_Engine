#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Renderer {
private:
	sf::RenderWindow* targeted_window;
	std::vector<sf::Drawable*> draw_queue;

public:
	Renderer(sf::RenderWindow* target);

	void draw();

	void clear();

	void update();

	void submit(sf::Drawable* to_draw);
};