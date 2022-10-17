#include <iostream>
#ifndef __NODE__HPP
#define __NODE__HPP

using namespace std;

class Node{
	private:
		float value;
		Node* Right;
		Node* Left;
	public:
		// Constructor
		Node(float value);
		// Functions that sets Node's items
		void setValue(float value);
		void setRight(Node* no);
		void setLeft(Node* no);
		// Functions that returns Node's items
		float getValue();
		Node* getRight();
		Node* getLeft();
};

#endif
