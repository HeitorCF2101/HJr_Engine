#include "keyboard.h"

Key::Key(const std::string n){
	name = n;
	code = sf::Keyboard::Key::Unknown;
}

Key::Key(const std::string n, sf::Keyboard::Key c){
	name = n;
	code = c;
	scan_code = sf::Keyboard::delocalize(c);
}

Key::Key(const sf::Keyboard::Key sfml_key){
	code = sf::Keyboard::localize(sf::Keyboard::delocalize(sfml_key));
	name = "sfml_" + sf::Keyboard::getDescription(sf::Keyboard::delocalize(sfml_key));
}

Key::operator int() const{
	return static_cast<int>(code);
}
