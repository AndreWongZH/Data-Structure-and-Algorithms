#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(void) {
	cout << "Linked List Implementation" << endl;

	List<int> studentList;

	studentList.insertAtHead(3);
	studentList.insertAtHead(6);
	studentList.insertAtTail(9);
	studentList.insertAtPos(1, 2);
	studentList.insertAtAfter(2, 30);

	studentList.removeAtHead();
	studentList.removeAtTail();
	studentList.removeAtPos(1);
	studentList.removeAtAfter(0);
	studentList.insertAtHead(69);

};
