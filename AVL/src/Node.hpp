#include <iostream>
#ifndef __NODE__HPP
#define __NODE__HPP

using namespace std;

class Node{
	private:
		float value;
		int weight; // AVL tree have a extra item, every node has a weight and that is use to maintain tree's balance
		Node* Right;
		Node* Left;
	public:
		// Constructor
		Node(float value);
		// Functions that sets a Node's item
		void setValue(float value);
		void setRight(Node* no);
		void setLeft(Node* no);
		void setWeight(int height);
		// Functions that return the Node's items
		float getValue();
		Node* getRight();
		Node* getLeft();
		int getWeight();
};

#endif
