#include "input.h"

Input_manager::Input_manager(size_t buffer_size) : m_buffer_size(buffer_size){
	KeyBoardState emptyState{};
	emptyState.fill(false);

	for (int i = 0; i < m_buffer_size; i++) {
		m_buffer.push_back(emptyState);
	}

}

void Input_manager::update(){
	//input and event update module
	KeyBoardState new_state{};

	std::vector<Key> keys_pressed;
	std::vector<Key> keys_released;

	for (int i = 0; i < Keyboard::all_Keys.size(); i++) {
		new_state[i] = sf::Keyboard::isKeyPressed(Keyboard::all_Keys.at(i).code);

		if(is_key_pressed(Keyboard::all_Keys.at(i))) keys_pressed.push_back(Keyboard::all_Keys.at(i));
		else if(is_key_released(Keyboard::all_Keys.at(i))) keys_released.push_back(Keyboard::all_Keys.at(i));

	}

	m_buffer.push_front(new_state);

	if(m_buffer.size() > m_buffer_size){
		m_buffer.pop_back();
	}

}

bool Input_manager::is_key_pressed(Key key) const {
	return m_buffer[0][int(key)] && !m_buffer[1][int(key)];
}

bool Input_manager::is_key_held(Key key) const{
	return m_buffer[0][int(key)];
}

bool Input_manager::is_key_released(Key key) const{
	return !m_buffer[0][int(key)] && m_buffer[1][int(key)];
}

bool Input_manager::was_key_pressed_within(Key key, size_t frames) const{

	if (frames >= m_buffer_size) frames = m_buffer_size - 1;

	for (size_t i = 0; i < frames; i++) {
		if(m_buffer[i][int(key)] && !m_buffer[i + 1][int(key)]){
			return true;
		}
	}

	return false;
}

void Input_manager::debug(){
	for(const Key& key : Keyboard::all_Keys){
		if(m_buffer[0][int(key)]){
			std::cout << key.name << "\n";
		}
	}
}