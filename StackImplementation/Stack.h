#pragma once

class ListNode {
private:
	int item;
	ListNode* next;
public:
	ListNode(int);
	friend class List;
};

class List {
private:
	int size;
	ListNode* head;
public:
	List();
	~List();

	int peek();
	void push(int);
	int pop();
	void print();
};