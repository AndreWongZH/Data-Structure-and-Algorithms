#include <iostream>
#include "Queue.h"
using namespace std;

ListNode::ListNode(int n) {
	item = n;
	next = NULL;
}

List::List() {
	size = 0;
	head = NULL;
}

List::~List() {

}

int List::peek() {
	return head->item;
}

void List::enqueue(int n) {
	ListNode* temp = head;

	for (; temp; temp = temp->next) {
		if (!temp->next) {
			temp->item = n;
		}
	}

	print();
}

int List::dequeue() {
	ListNode* temp = head;
	int val;

	head = head->next;
	val = temp->item;
	delete(temp);

	print();

	return val;
}

void List::print() {
	ListNode* temp = head;

	for (; temp; temp = temp->next) {
		cout << temp->item << " " << endl;
	}
}