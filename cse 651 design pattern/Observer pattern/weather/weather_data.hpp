#ifndef  weather_data_h
#define weather_data_h
#include"subject.hpp"
#include "observer.hpp"

#include<unordered_set>
class weather_data : public subject {
private:
	std::unordered_set<observer*>observers;
	double temperature;
	double humidity;
	double pressure;
public:
	void register_observer(observer* o) {
		observers.insert(o);
	}

	void remove_observer(observer* o) {
		observers.erase(o);
	}
	void notify_observer() {
		for (auto o : observers) {
			o->update(temperature, humidity, pressure);
		}
	}
	void measurements_changed() {
		notify_observer();
	}
	void set_measurement(double t, double h, double p) {
		temperature = t;
		humidity = h;
		pressure = p;
		measurements_changed();
	}
};
#endif // ! weather_data_h

