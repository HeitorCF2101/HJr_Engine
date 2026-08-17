#include <action.hpp>

Action::Action(std::string n, Event e){
	name = n;
	e_bind = e;
}

Action::Action(std::string n, Key k){
	name = n;
	k_bind = k;
}

Action::operator bool() const{
	return state;
}