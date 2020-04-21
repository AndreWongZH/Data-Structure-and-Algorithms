#include "Stack.h"
#include <iostream>
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

void List::push(int n) {
	ListNode* aNewNode = new ListNode(n);
	if (head) {
		aNewNode->next = head;
	}
	head = aNewNode;

	print();
}

void List::print() {
	ListNode* temp = head;

	cout << "top of stack ";
	for (; temp; temp = temp->next) {
		cout << temp->item << " ";
	}
	cout << " end of stack" << endl;
}

int List::pop() {
	ListNode* temp = head;
	int val;

	head = head->next;
	val = temp->item;
	delete temp;

	print();

	return val;
}