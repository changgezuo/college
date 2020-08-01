//CIS554 HW2
//Due: 11:59PM, Friday (Feb. 15)
//Implement In-place quick sort
//You are only allowed to modify pointers of nodes, but not values of nodes
//Do not modify main function
//Do not introduce new functions

#include <iostream>
using namespace std;

class node {
public:
	int value;
	node * next;
	node * previous;
	node(int i) { value = i; next = previous = nullptr; }
	node() { next = previous = nullptr; }
};

class doubly_linked_list {
public:
	node * head;
	node * tail;
	doubly_linked_list() { head = tail = nullptr; }
	void make_random_list(int m, int n); //create m nodes with value randomly in 0 ... n-1
	void print_forward();
	void print_backward();

	//inplement the following member functions:

	void sort(node * p1, node * p2);  
		      //Range of sort is from *p1 to *p2
		      //Use in-place quick sort algorithm to sort the linked list in ascending order.
		      //You are only allowed to modify the pointers of nodes, but not values of nodes

};


void doubly_linked_list::make_random_list(int m, int n) {

	for (int i = 0; i < m; i++) {
		node * p1 = new node(rand() % n);
		p1->previous = tail;
		if (tail != nullptr) tail->next = p1;
		tail = p1;
		if (head == nullptr) head = p1;
	}
}

void doubly_linked_list::print_forward() {
	cout << endl;
	node * p1 = head;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->next;
	}
}

void doubly_linked_list::print_backward() {
	cout << endl;
	node * p1 = tail;
	while (p1 != nullptr) {
		cout << p1->value << " ";
		p1 = p1->previous;
	}
}

int main() {
	doubly_linked_list d1;
	d1.make_random_list(50, 20);
	d1.print_forward();
	d1.print_backward();

	d1.sort(d1.head, d1.tail);
	d1.print_forward();
	d1.print_backward();
	
	
	getchar();
	getchar();
	return 0;
}
