#pragma once

template <class T>
class List;

template <class T>
class ListNode {
private:
	T item;
	ListNode<T>* next;
public:
	ListNode(T);
	friend class List<T>;
};

template <class T>
class List {
private:
	int size;
	ListNode<T>* head;
	ListNode<T>* tail;
public:
	List();
	~List();

	void insertAtHead(T);
	void insertAtTail(T);
	void insertAtPos(int, T);
	void insertAtAfter(int, T);

	void removeAtHead();
	void removeAtTail();
	void removeAtPos(int);
	void removeAtAfter(int);

	void print();
};

#include "LinkedList.hpp"