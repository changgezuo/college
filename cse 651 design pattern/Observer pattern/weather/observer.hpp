#ifndef observer_h
#define observer_h
class observer {
public:
    virtual ~observer() = default;
    virtual void update(double temp, double humidity, double pressure) = 0;
};
#endif
