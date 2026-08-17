#include <player.hpp>

Player Player::debug_player(){

	Player debug_player;

	debug_player.name = "debug_player";
	debug_player.hp = 100.f;

	debug_player.position = { 0.f , 0.f };

	debug_player.x = debug_player.position.x;
	debug_player.y = debug_player.position.y;

	debug_player.debug_sprite.setFillColor(sf::Color::Green);
	debug_player.debug_sprite.setPosition({ debug_player.x, debug_player.y });

	return debug_player;
}

void Player::update(){
	//movement update
	x += float(move_right - move_left);
	y += float(move_down - move_up);

	debug_sprite.move({x , y});
	//TODO: add new actions
}
