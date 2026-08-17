#include "..\..\Engine\Engine.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <pch.h>

#include <player.hpp>

enum Window_configurations {
	HEIGHT = 720,
	LENGTH = 1280,

	VSYNC = false,
	MAX_FPS = 60,

	MOUSE_CAPTURED = false, 
};

int main(){

	// Creating window and configuring it
	sf::RenderWindow window(sf::VideoMode({LENGTH , HEIGHT}), "Game Window");
	
	window.setVerticalSyncEnabled(VSYNC);
	window.setFramerateLimit(MAX_FPS);

	sf::CircleShape debug_circle(30.f);
	debug_circle.setFillColor(sf::Color::Green);

	sf::Clock frame_time;

	Input_manager input(10);

	Renderer renderer(&window);

	Player player;
	player = Player::debug_player();

	while(window.isOpen()){

		auto delta_time = frame_time.restart();

		while(const std::optional event = window.pollEvent()){
			if(event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
		}

		input.update();
		player.update();
		renderer.submit(&player.debug_sprite);
		
		renderer.update();
	}
	
	return 0;
}