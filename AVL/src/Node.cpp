#include <iostream>
#include "Node.hpp"

using namespace std;

Node::Node(float value){ // Constructor that creates a Node with a seted value, weight equals 0 and null childrens
	this->value = value;
	this->weight = 0;
	this->Left = NULL;
	this->Right = NULL;
}

void Node::setValue(float value){ // Sets Node's value
	this->value = value;
} 

float Node::getValue(){ // Returns Node's value
	return this->value;
}

void Node::setLeft(Node* no){ // Sets Node's Left child
	this->Left = no;
}

Node* Node::getLeft(){ // Returns Node's Left child
	return this->Left;
}

void Node::setRight(Node* no){ // Sets Node's Right child
	this->Right = no;
}

Node* Node::getRight(){ // Returns Node's Right child
	return this->Right;
}

void Node::setWeight(int weight){ // Sets Node's weight
	this->weight = weight;
}

int Node::getWeight(){ // Returns Node's weight
	return this->weight;
}