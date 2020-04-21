#pragma once

#ifndef LINKEDLISTTEMPLATEHPP
#define LINKEDLISTTEMPLATEHPP

#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
ListNode<T>::ListNode(T n)
{
	item = n;
	next = NULL;
}

template <class T>
List<T>::List()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

template <class T>
List<T>::~List()
{
	cout << "Destructor happening now" << endl;
	while (size != 0) {
		removeAtHead();
	}
}

template <class T>
void List<T>::insertAtHead(T n)
{
	ListNode<T>* aNewNode = new ListNode<T>(n);
	aNewNode->next = head;
	head = aNewNode;
	size++;

	//implementing tail
	ListNode<T>* temp = head;
	for (; temp; temp = temp->next) {
		tail = temp;
	}

	print();
}

template <class T>
void List<T>::insertAtTail(T n)
{
	ListNode<T>* aNewNode = new ListNode<T>(n);
	aNewNode->next = NULL;
	tail->next = aNewNode;
	tail = aNewNode;
	size++;

	print();
}

template <class T>
void List<T>::insertAtPos(int pos, T n)
{
	ListNode<T>* aNewNode = new ListNode<T>(n);
	ListNode<T>* pre = head;
	ListNode<T>* aft;

	for (int k = 0; k < pos-1; k++) {
		pre = pre->next;
	}

	aft = pre->next;

	aNewNode->next = aft;
	pre->next = aNewNode;

	size++;

	print();
}

template <class T>
void List<T>::insertAtAfter(int pos, T n)
{
	ListNode<T>* aNewNode = new ListNode<T>(n);
	ListNode<T>* pre = head;
	ListNode<T>* aft;

	for (int k = 0; k < pos; k++) {
		pre = pre->next;
	}

	aft = pre->next;
	aNewNode->next = aft;
	pre->next = aNewNode;

	size++;

	print();
}

template <class T>
void List<T>::removeAtHead()
{
	if (size > 0) {
		ListNode<T>* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	else {

	}

	print();
}

template <class T>
void List<T>::removeAtTail()
{
	if (size > 0) {
		ListNode<T>* pre = head;
		ListNode<T>* temp = head->next;

		while (temp->next != NULL) {
			pre = pre->next;
			temp = pre->next;
		}

		pre->next = NULL;
		delete temp;
		tail = pre;
		size--;
	}

	print();
}

template <class T>
void List<T>::removeAtPos(int pos)
{
	if (pos < size - 1) {
		ListNode<T>* pre = head;
		ListNode<T>* temp = head->next;

		for (int k = 0; k < pos - 1; k++) {
			pre = pre->next;
			temp = pre->next;
		}

		pre->next = temp->next;
		delete temp;
		size--;
	}

	print();
}

template <class T>
void List<T>::removeAtAfter(int pos)
{
	if (pos < size - 1) {
		ListNode<T>* pre = head;
		ListNode<T>* temp = head->next;

		for (int k = 0; k < pos; k++) {
			pre = pre->next;
			temp = pre->next;
		}

		pre->next = temp->next;
		delete temp;
		size--;
	}

	print();
}

template <class T>
void List<T>::print()
{
	ListNode<T>* temp = head;
	cout << "Size now is: " << size << endl;

	for (; temp; temp = temp->next) {
		cout << temp->item << " ";
	}
	cout << endl;
}

#endif