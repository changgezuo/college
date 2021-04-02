#ifndef current_condition_h
#define current_condition_h

#include "observer.h"
#include "display.h"

#include<iostream>
#include<memory>

class current_condition:public observer, public display {
private:
	double temperature;
	double humidity;
	double pressure;
	std::shared_ptr<subject>weather_data;
public:
	current_condition_display(std::shared_ptr<subject>w) :
		temperature(0.0d), humidity(0.0d), weather_data(std::move(w)) {

	}
	void register_observer() {
		weather_data->register_observer(this);
	}
	~current_condition() {
		weather_data->register_observer(this);
	}
	void update(double t, double h, double p) {
		temperature = t;
		humdity = h;
		pressure = p;
		display();
	}

	void display() {
		std::cout << "Current conditions : " << temperature << "F degrees and"
			<< humidity << "% humidity" << pressure << " kPa" << endl;
	}
};



#endif
