#include <iostream>
#include "Que.h"
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
	cout << "peek at " << head->item << endl;
	return head->item;
}

void List::enqueue(int n) {
	ListNode* temp = head;
	ListNode* aNewNode = new ListNode(n);
	
	if (head) {
		for (; temp; temp = temp->next) {
			if (temp->next == NULL) {
				temp->next = aNewNode;
				break;
			}
		}
	}
	else {
		head = aNewNode;
	}


	print();
}

int List::dequeue() {
	ListNode* temp = head;
	int val;

	head = head->next;
	val = temp->item;
	delete(temp);

	cout << "dequeued " << val << endl;
	print();

	return val;
}

void List::print() {
	ListNode* temp = head;

	for (; temp; temp = temp->next) {
		cout << temp->item << " ";
	}
	cout << endl;
}