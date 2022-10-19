#include <iostream>
#include "Tree.hpp"

using namespace std;

Tree::Tree(){ // Constructor that creates an empty tree.
	this->root = NULL;
}

Tree::Tree(float value){ // Constructor that creates a tree with a element inserted in.
	this->root = new Node(value);
}

Node* Tree::getRoot(){ // Function that returns the Tree's root.
	return this->root;
}

void Tree::Insert(float value){ // Inserts a value in the tree.
	if(root == NULL){ // Just works at the first insertion, without it the root isn't seted.
		root = new Node(value);
	}
	else{ // This function is called for all the later inserts.
		InsertAux(root, value);
	}
}

void Tree::InsertAux(Node* root, float value){ // Function called to insert the elements except the first inserction.
	// It's a recursive function.
	if (root->getValue() > value){
		// Following the rule, if the new value is lower than root's value, the new value is inserted on the left side.
		if (root->getLeft() == NULL){ // If root's left child is empty the element is inserted on it.
			root->setLeft(new Node(value));
		}
		else { // Else the function is called again, now with the left child as root.
			InsertAux(root->getLeft(), value);
		}
	}
	else if(root->getValue() < value){
		// So also, if the new value is higher than root's value, the new value is inserted on the right side.
		if (root->getRight() == NULL){ // If root's right child is empty the element is inserted on it.
			root->setRight(new Node(value));
		}
		else { // Else the function is called again, now with the right child as root.
			InsertAux(root->getRight(), value);
		}	
	}
}

void Tree::Delete(Node* root, float value){
	if (root == NULL) // If del equals NULL the searched value doesn't exist.
		cout << "[ERROR]: Value not found!\n";
	if (root->getValue() < value)
		Delete(root->getLeft(), value);
	else if (root->getValue() > value)
		Delete(root->getRight(), value);
	else { // If the value exists in the tree it's node will be the root for the next steps.
		if (root->getRight() != NULL){
		// If the node have a right child the lowest value of the right sub-tree will be seached.
			Node* aux = root->getRight();
			while (aux->getLeft() != NULL){ // The lowest value is the last left child on the sub-tree.
				aux = aux->getLeft();
			}
			root->setValue(aux->getValue()); // The value to be deleted will be replaced by the lowest value.
			aux = NULL; // The lowest value will be deleted at this position.
		}
		else if (root->getLeft() != NULL){
		// If the node have a left child the highest value of the left sub-tree.
			Node* aux = root->getLeft();
			while (aux->getRight() != NULL){ // The highest value is the last right child on the sub-tree.
				aux = aux->getRight();
			}
			root->setValue(aux->getValue()); // The value to be deleted will be replaced by the highest value.
			aux = NULL;
		}
		else { // If the node is a leaf it will be deleted itself.
			root = NULL;
		}
		cout << "\nDeleted.\n";
	}
}

void Tree::Search(Node* root, float value){ // Searches an item in the tree and returns it's Node.
	if (root == NULL){ // If root equals NULL the value wasn't found so the function returns NULL.
		cout << "[ERROR]: Value not found!" << endl;
	}
	else if (root->getValue() == value){ // If the searched value is equal the node value returns it.
		cout << "Valor encontrado: " << root->getValue() << endl;
	}
	else{
		if (root->getValue() > value){
		// If the searched value is lower than the node value call the function again with the left child as root.
			Search(root->getLeft(), value);
		}
		else if(root->getValue() < value){
		// If the searched value is higher than the node value call the function again with the right child as root.
			Search(root->getRight(), value);
		}
	}
} 

void Tree::Preorder(Node* root){ // Prints the elements of the tree in pre-order.
	if(root != NULL){
    	cout << root->getValue() << endl;
    	Preorder(root->getLeft()); 
    	Preorder(root->getRight()); 
  }
}

void Tree::Inorder(Node* root){ // Prints the elements of the tree in order, the lowest to the highest.
	if(root != NULL){
    	Inorder(root->getLeft()); 
    	cout << root->getValue() << endl;
    	Inorder(root->getRight()); 
  	}
}

void Tree::Postorder(Node* root){ // Prints the elements of the tree in post-order.
	if(root != NULL){
    	Postorder(root->getLeft()); 
    	Postorder(root->getRight()); 
    	cout << root->getValue() << endl;
  	}
}

int Tree::Height(Node* root){ // Calculates the height of the tree.
	if (root == NULL){
		return -1; //Empty tree's height.
	}
	else {
		// run to the deepest leaf on the tree and return its height.
		int Left_height = Height(root->getLeft());
		int Right_height = Height(root->getRight());
		if (Left_height < Right_height) return Right_height + 1;
		else return Left_height + 1;
	}
}