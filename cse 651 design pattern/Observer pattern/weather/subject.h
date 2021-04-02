#ifndef subject_h
#define subject_h

class observer;

class subject {
public:
	virtual ~subject() = default;
	virtual void register_observer(observer*) = 0;
	virtual void remove_observer(observer*) = 0;
	virtual void notify_observer() = 0;
};
#endif // !subject_h
