
//Do not modify main function.
//Do not introduce new functions.
//In-place implementation is required.  External structures are not allowed.
//For example, you are not allowed to copy linked list values to outside, and then process the data and copy them
//back to linked list.


#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node* previous;
	Node(int i) { value = i; next = previous = nullptr; }
	Node() { next = previous = nullptr; }
};

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	DoublyLinkedList() { head = tail = nullptr; }
	void makeRandomList(int m, int n);
	void printForward();
	void printBackward();

	//implement the following member function:
	void MergeSortIte(Node* p1, Node* p2);//Implement MergeSort iteratively. Sort a portion of a DoublyLinkedList, from the node pointed by p1 to the node pointed by p2.
	void MergeSortRec(Node* p1, Node* p2); //Implement MergeSort recursively. Sort a portion of DoublyLinkedList, from the node pointed by p1 to the node pointed by p2.
	void Merge(Node* p1, Node* p2, Node* p3, Node* p4); //Merge two portions of a DoublyLinkedList, one from the node pointed by p1 to the node pointed by p2 and
															  //the other from the node pointed by p3 to the node pointed by p4.
	void InsertionSort(Node* p1, Node* p2); //Implement InsertionSort.  Sort a portion of a DoublyLinkedList, from the node pointed by p1 to the node pointed by p2.

	//The function Merge can be called by functions MergeSortIte and MergeSortRec;

};

/*
In-place sorting. Values have not been changed. Only nodes have been moved around.
*/
DoublyLinkedList::makeRandomList(int a, int b) {
     
}

int main() {
	int a{ 50 }, b{ 30 };
	DoublyLinkedList d1, d2, d3;
	d1.makeRandomList(a, b);
	d1.printForward();
	d1.printBackward();

	d1.MergeSortIte(d1.head, d1.tail);
	d1.printForward();
	d1.printBackward();


	d2.makeRandomList(a, b);
	d2.printForward();
	d2.printBackward();

	d2.MergeSortRec(d2.head, d2.tail);
	d2.printForward();
	d2.printBackward();


	d3.makeRandomList(a, b);
	d3.printForward();
	d3.printBackward();

	d3.InsertionSort(d3.head, d3.tail);
	d3.printForward();
	d3.printBackward();

	return 0;
}