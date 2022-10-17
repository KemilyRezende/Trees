#include <iostream>
#include "Node.hpp"

using namespace std;

Node::Node(float value){ // Constructor: creates a Node with a value stored in and null childrens.
	this->value = value;
	this->Left = NULL;
	this->Right = NULL;
}

void Node::setValue(float value){ // Sets Node's value.
	this->value = value;
} 

float Node::getValue(){ // Returns Node's value.
	return this->value;
}

void Node::setLeft(Node* no){ // Sets Node's left child.
	this->Left = no;
}

Node* Node::getLeft(){ // Returns Node's left child.
	return this->Left;
}

void Node::setRight(Node* no){ // Sets Node's right child.
	this->Right = no;
}

Node* Node::getRight(){ // Returns Node's right child.
	return this->Right;
}
