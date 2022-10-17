#include <iostream>
#include "Tree.hpp"

using namespace std;

Tree::Tree(){ // Constructor that creates an empty tree.
	this->rooth = NULL;
}

Tree::Tree(float value){ // Constructor that creates a tree with a element inserted in.
	this->rooth = new Node(value);
}

Node* Tree::getRooth(){ // Function that returns the Tree's rooth.
	return this->rooth;
}

void Tree::Insert(float value){ // Inserts a value in the tree.
	if(rooth == NULL){ // Just works at the first insertion, without it the rooth isn't seted.
		rooth = new Node(value);
	}
	else{ // This function is called for all the later inserts.
		InsertAux(rooth, value);
	}
}

void Tree::InsertAux(Node* rooth, float value){ // Function called to insert the elements except the first inserction.
	// It's a recursive function.
	if (rooth->getValue() > value){
		// Following the rule, if the new value is lower than rooth's value, the new value is inserted on the left side.
		if (rooth->getLeft() == NULL){ // If rooth's left child is empty the element is inserted on it.
			rooth->setLeft(new Node(value));
		}
		else { // Else the function is called again, now with the left child as rooth.
			InsertAux(rooth->getLeft(), value);
		}
	}
	else if(rooth->getValue() < value){
		// So also, if the new value is higher than rooth's value, the new value is inserted on the right side.
		if (rooth->getRight() == NULL){ // If rooth's right child is empty the element is inserted on it.
			rooth->setRight(new Node(value));
		}
		else { // Else the function is called again, now with the right child as rooth.
			InsertAux(rooth->getRight(), value);
		}	
	}
}

void Tree::Delete(Node* rooth, float value){
	if (rooth == NULL) // If del equals NULL the searched value doesn't exist.
		cout << "[ERROR]: Value not found!\n";
	if (rooth->getValue() < value)
		Delete(rooth->getLeft(), value);
	else if (rooth->getValue() > value)
		Delete(rooth->getRight(), value);
	else { // If the value exists in the tree it's node will be the rooth for the next steps.
		if (rooth->getRight() != NULL){
		// If the node have a right child the lowest value of the right sub-tree will be seached.
			Node* aux = rooth->getRight();
			while (aux->getLeft() != NULL){ // The lowest value is the last left child on the sub-tree.
				aux = aux->getLeft();
			}
			rooth->setValue(aux->getValue()); // The value to be deleted will be replaced by the lowest value.
			aux = NULL; // The lowest value will be deleted at this position.
		}
		else if (rooth->getLeft() != NULL){
		// If the node have a left child the highest value of the left sub-tree.
			Node* aux = rooth->getLeft();
			while (aux->getRight() != NULL){ // The highest value is the last right child on the sub-tree.
				aux = aux->getRight();
			}
			rooth->setValue(aux->getValue()); // The value to be deleted will be replaced by the highest value.
			aux = NULL;
		}
		else { // If the node is a leaf it will be deleted itself.
			rooth = NULL;
		}
		cout << "\nDeleted.\n";
	}
}

void Tree::Search(Node* rooth, float value){ // Searches an item in the tree and returns it's Node.
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

void Tree::Preorder(Node* rooth){ // Prints the elements of the tree in pre-order.
	if(rooth != NULL){
    	cout << rooth->getValue() << endl;
    	Preorder(rooth->getLeft()); 
    	Preorder(rooth->getRight()); 
  }
}

void Tree::Inorder(Node* rooth){ // Prints the elements of the tree in order, the lowest to the highest.
	if(rooth != NULL){
    	Inorder(rooth->getLeft()); 
    	cout << rooth->getValue() << endl;
    	Inorder(rooth->getRight()); 
  	}
}

void Tree::Postorder(Node* rooth){ // Prints the elements of the tree in post-order.
	if(rooth != NULL){
    	Postorder(rooth->getLeft()); 
    	Postorder(rooth->getRight()); 
    	cout << rooth->getValue() << endl;
  	}
}

int Tree::Height(Node* rooth){ // Calculates the height of the tree.
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
