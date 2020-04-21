#include <iostream>
#include "Stack.h"
using namespace std;

int main(void) {
	cout << "Welcome to stack implementation" << endl;

	List stack;

	stack.push(22);

	cout << stack.peek() << endl;

	stack.push(5);
	stack.push(30);

	cout << stack.peek() << endl; 

	stack.push(69);
	stack.push(20);
	stack.push(15);

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
}
