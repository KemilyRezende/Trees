#include <iostream>
#ifndef __NODE__HPP
#define __NODE__HPP

using namespace std;

class Node{
	private:
		float value;
		Node* Right;
		Node* Left;
		// These items are exclusive from RedBlack tree and are used to maintain tree's balancing
		Node* Parent; 
		bool color;
	public:
	// Constructor
		Node(float value, Node* Parent);
	// Functions that sets Node's items
		void setValue(float value);
		void setRight(Node* no);
		void setLeft(Node* no);
		void setParent(Node* no);
		void setColor(bool color);
	// Functions that returns Node's items
		float getValue();
		Node* getRight();
		Node* getLeft();
		Node* getParent();
		bool getColor();
};

#endif
