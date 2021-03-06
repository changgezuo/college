#include "weather_data.hpp"
#include "current_condition.hpp"

void weather_current_demo() {
	auto w = std::make_shared<weather_data>();
	current_condition* current_display = new current_condition(w);
	current_display->register_observer();
	w->set_measurement(80, 65, 30.4);
	delete current_display;
}

int main() {
	weather_current_demo();
	
	
	return 0;
}