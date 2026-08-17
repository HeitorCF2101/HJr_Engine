#include "renderer.h"

Renderer::Renderer(sf::RenderWindow* target){
	targeted_window = target;
}

void Renderer::draw(){
	std::size_t max_buffer_size = 10;
	for (int i = 0; i < draw_queue.size(); i++) {
		auto& obj_to_draw = draw_queue.back();
		targeted_window->draw(*obj_to_draw);
	}

	if(draw_queue.size() > max_buffer_size) draw_queue.pop_back();
}

void Renderer::clear(){
	targeted_window->clear();
}

void Renderer::update(){
	clear();
	draw();
	targeted_window->display();
}

void Renderer::submit(sf::Drawable* to_draw){
	draw_queue.push_back(to_draw);
}

