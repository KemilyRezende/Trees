#include <iostream>
#ifndef __NODE__HPP
#define __NODE__HPP

using namespace std;

class Node{
	private:
		float value;
		Node* Right;
		Node* Left;
		// AVL
		int weight;
		// RedBlack
		Node* Parent; 
		bool color;
	public:
		Node(float value, Node* Parent);
		void setValue(float value);
		void setRight(Node* no);
		void setLeft(Node* no);
		float getValue();
		Node* getRight();
		Node* getLeft();
		// AVL functions
		void setWeight(int height);
		int getWeight();
		// RedBlack Functions
		void setParent(Node* no);
		void setColor(bool color);
		Node* getParent();
		bool getColor();
};

#endif
