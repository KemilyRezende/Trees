#include <iostream>
#include "Node.hpp"

using namespace std;

Node::Node(float value, Node* Parent){ // Constructor: creates a Node with a value stored, null childrens and sets its parent
	this->value = value;
	this->Left = NULL;
	this->Right = NULL;
	this->Parent = Parent;
	this->color = false; // False = red; True = black.
}

void Node::setValue(float value){ // Sets Node's value
	this->value = value;
} 

float Node::getValue(){ // Returns Node's value
	return this->value;
}

void Node::setLeft(Node* no){ // Sets Node's left child
	this->Left = no;
}

Node* Node::getLeft(){ // Returns Node's left child
	return this->Left;
}

void Node::setRight(Node* no){ // Sets Node's right child
	this->Right = no;
}

Node* Node::getRight(){ // Returns Node's right child
	return this->Right;
}

void Node::setParent(Node* no){ // Sets Node's Parent
	this->Parent = no;
}

Node* Node::getParent(){ // Returns Node's Parent
	return this->Parent;
}

void Node::setColor(bool color){ // Sets Node's color
	this->color = color;
}

bool Node::getColor(){ // Returns Node's color
	return this->color;
}
