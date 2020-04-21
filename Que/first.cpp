#include <iostream>
#include "Que.h"
using namespace std;

int main(void) {
	List l;

	l.enqueue(1);
	l.peek();
	l.enqueue(2);
	l.enqueue(3);
	l.enqueue(4);
	l.peek();
	l.enqueue(5);
	l.dequeue();
	l.dequeue();
	l.dequeue();
	l.peek();
}