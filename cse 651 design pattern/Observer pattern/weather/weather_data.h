#ifndef  weather_data_h
#define weather_data_h
#include"subject.h"
#include "observer.h"

#include<unordered_set>
class weather : public subject {
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
	void notify_observers() {
		for (auto o : observers) {
			o->update(temperature, humidity, pressure);
		}
	}
	void measurements_changed() {
		notify_observers();
	}
	void set_measurements(double t, double h, double p) {
		temperature = t;
		humidity = h;
		pressure = p;
		measurements_changed();
	}
};
#endif // ! weather_data_h

