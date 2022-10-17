#include <iostream>
#include <cstdlib>
#include "RedBlack.hpp"

using namespace std;

RedBlack::RedBlack(){ // Constructor that creates an empty tree.
	this->rooth = NULL;
}

RedBlack::RedBlack(float value){ // Constructor that creates a tree with a element inserted in.
	this->rooth = new Node(value, NULL);
}

Node* RedBlack::getRooth(){ // Function that returns the Tree's rooth.
	return this->rooth;
}

void RedBlack::Insert(float value){ // Inserts a value in the tree.
	if(rooth == NULL) // Just works at the first insertion, without it the rooth isn't seted.
		rooth = new Node(value, NULL);
	else // This function is called for all the later inserts.
		InsertAux(rooth, value);
}

void RedBlack::InsertAux(Node* rooth, float value){
	if (rooth->getValue() > value){ 
		if (rooth->getLeft() == NULL){
		// If Node's left child is NULL inserts value on it and set the Node as its parent.
			rooth->setLeft(new Node(value, rooth));
			Node* left = rooth->getLeft();
			if (left->getParent() != this->rooth) // If new Node's parent is the rooth it haven't an uncle.
				FixInsert(rooth->getLeft()); // Call the fixing function to maintain the balance.
		}
		else InsertAux(rooth->getLeft(), value);
	}
	else if (rooth->getValue() < value){
		if (rooth->getRight() == NULL){
		// If Node's right child is NULL inserts value on it and set the Node as its parent.
			rooth->setRight(new Node(value, rooth));
			Node* right = rooth->getRight();
			if (right->getParent() != this->rooth) // If new Node's parent is the rooth it haven't an uncle.
				FixInsert(rooth->getRight()); // Call the fixing function to maintain the balance.
		}
		else InsertAux(rooth->getRight(), value); 
	}
}

void RedBlack::FixInsert(Node* child){
// This function is called to maintain the balancing after a inserction 
	Node* uncle;
	while (child != rooth && child->getParent()->getColor() == false){ 
		if (child->getParent() == child->getParent()->getParent()->getLeft()){
		// If child Node is the left child
			uncle = child->getParent()->getParent()->getRight();
			// Case 1:
			if (uncle != NULL && uncle->getColor() == false){
				child->getParent()->setColor(true);
				uncle->setColor(true);
				child->getParent()->getParent()->setColor(false);
				child = child->getParent()->getParent();
			}
			else{
				// Case 2
				if (child == child->getParent()->getRight()){
					child = child->getParent();
					Rotation_LL(child);
				}
				// Case 3
				child->getParent()->setColor(true);
				child->getParent()->getParent()->setColor(false);
				Rotation_RR(child->getParent()->getParent());
			}	
		}
		else { // If child Node is the right child
			uncle = child->getParent()->getParent()->getLeft();
			// Case 1 
			if (uncle != NULL && uncle->getColor() == false){
				child->getParent()->setColor(true);
				uncle->setColor(true);
				child->getParent()->getParent()->setColor(false);
				child = child->getParent()->getParent();
			}
			else{
				// Case 2
				if (child == child->getParent()->getLeft()){
					child = child->getParent();
					Rotation_RR(child);
				}
				// Case 3
				child->getParent()->setColor(true);
				child->getParent()->getParent()->setColor(false);
				Rotation_LL(child);
			}
		}
	}
	rooth->setColor(true);
}

void RedBlack::Rotation_LL(Node* child){
// Rotates the nodes to the right
	Node* y = child->getRight();
	child->setRight(y->getLeft());
	if (y->getLeft() != NULL)
		y->getLeft()->setParent(child);
	y->setParent(child->getParent());
	if (child->getParent() == NULL)
		this->rooth = y;
	else if (child == child->getParent()->getLeft())
		child->getParent()->setLeft(y);
	else child->getParent()->setRight(y);
	y->setLeft(child);
	child->setParent(y);
}

void RedBlack::Rotation_RR(Node* child){
// Rotates the nodes to the left
	Node* y = child->getLeft();
	child->setLeft(y->getRight());
	if (y->getRight() != NULL)
		y->getRight()->setParent(child);
	y->setParent(child->getParent());
	if (child->getParent() == NULL)
		this->rooth = y;
	else if (child == child->getParent()->getRight())
		child->getParent()->setRight(y);
	else child->getParent()->setLeft(y);
	y->setRight(child);
	child->setParent(y);
}

void RedBlack::Delete(Node* rooth, float value){
	if (rooth == NULL) // If del equals NULL the searched value doesn't exist.
		cout << "[ERROR]: Value not found!\n";
	if (rooth->getValue() < value)
		Delete(rooth->getLeft(), value);
	else if (rooth->getValue() > value)
		Delete(rooth->getRight(), value);
	else {
		Node* x;
		Node* y;
		y = rooth;
		bool originalColor = y->getColor();
		// Leaf Node
		if (y->getLeft() == NULL && y->getRight() == NULL){
			if (y == y->getParent()->getLeft())
				y->getParent()->setLeft(NULL);
			else y->getParent()->setRight(NULL);
			free(rooth);
		}
		// Node with one child
		else if (rooth->getLeft() == NULL){ // Node with a Right child
			x = rooth->getRight();
			rbTransplant(rooth, rooth->getRight());
			free(rooth);
		}
		else if (rooth->getRight() == NULL){ // Node with a left child
			x = rooth->getLeft();
			rbTransplant(rooth, rooth->getLeft());
			free(rooth);
		}
		else { // Node with two children
			Node* aux = rooth->getRight(); 
			// Gets the lower value at right subtree.
			while (aux->getLeft() != NULL){ // The lowest value is the last left child on the sub-tree.
				aux = aux->getLeft();
			}
			y = aux;
			x = rooth;
			x->setValue(y->getValue()); // the deleted value will be replaced by the lower value of right subtree
			if (y->getParent() == rooth){ // The Node with the lowest value is child of the deleted Node. 
				if (y->getRight() != NULL){ // If this Node has a right child, del left child will be replaced by it.
					x->setRight(y->getRight());
					y->getRight()->setParent(x); // Sets Right child's parent as x.
				}
				else x->setRight(NULL); // If y has no child the left child of x will be NULL;
			}
			else { // Deleted value isn't parent of y.
				if (y->getRight() != NULL){ // If y has a right child: the left child of y's parent will be y's right child.
					y->getParent()->setLeft(y->getRight());
					y->getRight()->setParent(y->getParent());
				}
				else y->getParent()->setLeft(NULL); // If y has no child: the left child of y's parent will be NULL.
			}
			y = NULL;
			free(y);
		}
		if (originalColor == true)
			FixDelete(x); // Calls a function to maintain balancing after a deletion.
	}
}

void RedBlack::rbTransplant(Node* u, Node* v) { // Transplant two Nodes.
    if (u->getParent() == NULL) {
      rooth = v;
    } else if (u == u->getParent()->getLeft()) {
      u->getParent()->setLeft(v);
    } else {
      u->getParent()->setRight(v);
    }
    v->setParent(u->getParent());
  }

void RedBlack::FixDelete(Node* x){ // Function called to maintain tree's balancing after a deletion
	Node* brother;
	while (x != rooth && x->getParent()->getColor() == false){
		if (x == x->getParent()->getLeft()){
			brother = x->getParent()->getRight();
			if(brother->getColor() == false){
				brother->setColor(true);
				x->getParent()->setColor(false);
				Rotation_RR(x->getParent());
				brother = x->getParent()->getRight();
			}
			if (brother->getLeft()->getColor() == true && brother->getRight()->getColor() == true){
				brother->setColor(false);
				x = x->getParent();
			}
			else {
				if (brother->getRight()->getColor() == true){
					brother->getLeft()->setColor(true);
					brother->setColor(false);
					Rotation_LL(brother);
					brother = x->getParent()->getRight();
				}
				brother->setColor(x->getParent()->getColor());
				x->getParent()->setColor(true);
				brother->getRight()->setColor(true);
				Rotation_RR(x->getParent());
				x = rooth;
			}
		}
		else {
			brother = x->getParent()->getLeft();
			if (brother->getColor() == false){
				brother->setColor(true);
				x->getParent()->setColor(false);
				Rotation_LL(x->getParent());
				brother = x->getParent()->getLeft();
			}
			if (brother->getRight()->getColor() == true && brother->getLeft()->getColor() == true){
				brother->setColor(false);
				x = x->getParent();
			}
			else {
				if (brother->getLeft()->getColor() == true){
					brother->getRight()->setColor(true);
					brother->setColor(false);
					Rotation_RR(brother);
					brother = x->getParent()->getLeft();
				}
				brother->setColor(x->getParent()->getColor());
				x->getParent()->setColor(true);
				brother->getLeft()->setColor(true);
				Rotation_LL(x->getParent());
				x = rooth;
			}
			
		}
		
	}
	x->setColor(true);
}

void RedBlack::Search(Node* rooth, float value){ // Searches an item in the tree and returns it's Node.
	if (rooth == NULL){ // If rooth equals NULL the value wasn't found so the function returns NULL.
		cout << "[ERROR]: Value not found!" << endl;
	}
	else if (rooth->getValue() == value){ // If the searched value is equal the node value returns it.
		cout << "Valor encontrado: " << rooth->getValue() << endl;
	}
	else{
		if (rooth->getValue() > value){
		// If the searched value is lower than the node value call the function again with the left child as rooth.
			Search(rooth->getLeft(), value);
		}
		else if(rooth->getValue() < value){
		// If the searched value is higher than the node value call the function again with the right child as rooth.
			Search(rooth->getRight(), value);
		}
	}
} 

void RedBlack::Preorder(Node* rooth){ // Prints the elements of the tree in pre-order.
	if(rooth != NULL){
    	cout << rooth->getValue() << endl;
    	Preorder(rooth->getLeft()); 
    	Preorder(rooth->getRight()); 
  }
}

void RedBlack::Inorder(Node* rooth){ // Prints the elements of the tree in order, the lowest to the highest.
	if(rooth != NULL){
    	Inorder(rooth->getLeft()); 
    	cout << rooth->getValue() << endl;
    	Inorder(rooth->getRight()); 
  	}
}

void RedBlack::Postorder(Node* rooth){ // Prints the elements of the tree in post-order.
	if(rooth != NULL){
    	Postorder(rooth->getLeft()); 
    	Postorder(rooth->getRight()); 
    	cout << rooth->getValue() << endl;
  	}
}

int RedBlack::Height(Node* rooth){ // Calculates the height of the tree.
	if (rooth == NULL){
		return -1; //Empty tree's height.
	}
	else {
		// run to the deepest leaf on the tree and return its height.
		int Left_height = Height(rooth->getLeft());
		int Right_height = Height(rooth->getRight());
		if (Left_height < Right_height) return Right_height + 1;
		else return Left_height + 1;
	}
}

