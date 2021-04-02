#ifndef display_element_h
#define display_element_h

class display_element {
public:
	virtual ~display_element() = default;
	virtual void display() = 0;
};

#endif

