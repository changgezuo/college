#ifndef subject_h
#define subject_h
class observer {
	virtual ~observer() = default;
	virtual void update(double temperature, double humidity, double pressure) = 0;
};
#endif
