#ifndef current_condition_h
#define current_condition_h

#include "observer.hpp"
#include "display_element.hpp"

#include<iostream>
#include<memory>

class current_condition:public observer, public display_element {
private:
	double temperature;
	double humidity;
	double pressure;
	std::shared_ptr<subject>weather_data;
public:
	current_condition(std::shared_ptr<subject> w) :
		temperature(0.0f), humidity(0.0f),pressure(0.0f), weather_data(std::move(w)) {
	}
	void register_observer() {
		weather_data->register_observer(this);
	}
	~current_condition() {
		weather_data->register_observer(this);
	}
	void update(double t, double h, double p) {
		temperature = t;
		humidity = h;
		pressure = p;
		display();
	}

	void display() {
		std::cout << "Current conditions : " << temperature << "F degrees and"
			<< humidity << "% humidity" << std::endl;
	}
};



#endif
