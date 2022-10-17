#include <iostream>
#include "AVL.hpp"
#include <cstdlib> 

using namespace std;

AVL::AVL(){ // Creates an empty tree.
	this->rooth = NULL;
}

AVL::AVL(int value){ // Creates a tree with a value inserted.
	this->rooth = new Node(value);
}

Node* AVL::getRooth(){ // Returns tree's rooth.
	return this->rooth;
}

void AVL::Insert(int value){ // Inserts a value in the tree.
	if(rooth == NULL){ // Just works at the first insertion, without it the rooth isn't seted.
		rooth = new Node(value);
	}
	else{ // This function is called for all the later inserts.
		InsertAux(rooth, value);
	}
}

void AVL::InsertAux(Node* rooth, int value){ // Function called to insert the elements except the first inserction.
	if (rooth->getValue() > value){ 
	// If the new value is lower than the Node's value the left child will be visited.
		if (rooth->getLeft() == NULL){ // If the left child is NULL a new Node with the value will be stored in.
	 		rooth->setLeft(new Node(value));
	 		rebalanceTree(rooth); // After every insertion this function is called to maintain tree's balance.
		}
		// If the child isn't NULL the insertion functions is called again now with this Node as rooth.
		else InsertAux(rooth->getLeft(), value);
	}
	else if(rooth->getValue() < value){ 
	// If the new value is higher than the Node's value the right child will be visited.
		if (rooth->getRight() == NULL){ // If the right child is NULL a new Node with the value will be stored in.
			rooth->setRight(new Node(value));
	 		rebalanceTree(rooth);	// After every insertion this function is called to maintain tree's balance.
		}
		// If the child isn't NULL the insertion functions is called again now with this Node as rooth.
		else InsertAux(rooth->getRight(), value);
	}
	// Sets the new height of the rooth.
	rooth->setWeight(Maior(NodeWeight(rooth->getLeft()), NodeWeight(rooth->getRight()))+1);
}

void AVL::Search(Node* rooth, int value){ // Searches an item in the tree and returns it's Node.
	if (rooth == NULL){ // If rooth equals NULL the value wasn't found the function spans an advice and returns NULL.
		cout << "\n[ERROR]: Value not found\n";
	}
	else if(rooth->getValue() == value){ // If Node's value is equal the seached value return this Node.
		cout << "Valor encontrado: " << rooth->getValue() << endl;
	}
	else{
		if (rooth->getValue() > value){ 
		// If Node's value is higher than searched value the function is called again, now with the Left child as rooth.
			Search(rooth->getLeft(), value);
		}
		else if(rooth->getValue() < value){
		// If Node's value is lower than searched value the function is called again, now with the Right child as rooth.
			Search(rooth->getRight(), value);
		}
	}
}

int AVL::Delete(Node* rooth, int value){
	if (rooth == NULL){ 
	// When Serch returns a NULL value that means that the searched value wasn't inserted in the tree.
		cout << "\n[ERROR]: Value not found" << endl;
		return 0;
	}
	else if (rooth->getLeft()->getValue() == value && rooth->getLeft()->getLeft() == NULL && rooth->getLeft()->getRight() == NULL){
	// Deletion if the node that store the value is a leaf (a Node's left child).
		Node* aux = rooth->getLeft();
		rooth->setLeft(NULL);
		free(aux);
		return 1;
	}
	else if (rooth->getRight()->getValue() == value && rooth->getRight()->getLeft() == NULL && rooth->getRight()->getRight() == NULL){
	// Deletion if the node that store the value is a leaf (a Node's right child).
		Node* aux = rooth->getRight();
		rooth->setRight(NULL);
		free(aux);
		return 1;
	}
	else if(value < rooth->getValue()){
	// If the searched value is lower than atual Node's value the function is called again, now with Node's Left child as rooth.
		if (Delete(rooth->getLeft(), value) == 1) // If Deletion works, calls the function to maintain tree's balance.
			rebalanceTree(rooth->getLeft());
	}
	else if (value > rooth->getValue()){
	// If the searched value is higher than atual Node's value the function is called again, now with Node's Right child as rooth.
		if (Delete(rooth->getRight(), value) == 1) // If Deletion works, calls the function to maintain tree's balance.
			rebalanceTree(rooth->getRight());
	}
	else if (value == rooth->getValue()){ 
		if(rooth->getRight() != NULL && rooth->getLeft() != NULL){ // Node with two children.
			Node* aux = rooth->getRight();
			while (aux->getLeft()!= NULL){ // The lowest value is the last left child on the sub-tree.
				aux = aux->getLeft();
			}
			rooth->setValue(aux->getValue()); // The value to be deleted will be replaced by the lowest value.
			aux = NULL; // The lowest value will be deleted at this position.
			rebalanceTree(rooth->getLeft());
		}
		else { // Node with one child. 
		// The deleted node will be replaced by its child.
			if (rooth->getLeft() != NULL){ // Node with Left child.
				rooth->setValue(rooth->getLeft()->getValue()); 
				rooth->setLeft(NULL);
				free(rooth->getLeft());
			}
			else if (rooth->getRight() != NULL){ // Node with Right child.
				rooth->setValue(rooth->getRight()->getValue());
				rooth->setRight(NULL);
				free(rooth->getRight());	
			}
		}
		return 1;
	}
	return 1;
}

int AVL::Height(Node* rooth){ // Function that returns tree's height.
	if (rooth == NULL){
		return -1; //Empty tree's height
	}
	else {
		int Left_height = Height(rooth->getLeft());
		int Right_height = Height(rooth->getRight());
		if (Left_height < Right_height) return Right_height + 1;
		else return Left_height + 1;
	}
}

int AVL::NodeWeight(Node* rooth){ // Function that returns a weight.
	if (rooth == NULL) return -1;
	else return rooth->getWeight();
}

int AVL::Balancing(Node* rooth){ 
// Function that returns a Node's "weight", if it's lower than -2 or higher tha 2 the Node is unbalanced.
	return (NodeWeight(rooth->getLeft()) - NodeWeight(rooth->getRight()));
}

void AVL::rebalanceTree(Node* rooth){ // Function that rebalance tree
	int balance;
  	int left = 0;
  	int right = 0;
	
	// Calls the Balancing function to find the value of the Nodes
	balance = Balancing(rooth);
	if(rooth->getLeft())
		left = Balancing(rooth->getLeft());
	if(rooth->getRight())
		right = Balancing(rooth->getRight());
	
	// If the tree is unbalanced at right a rotation will be done to the left.
	if(balance == 2 && left >= 0) // If both numbers are positive a simple rotation will be done.
		Rotation_RR(rooth);
	if(balance == 2 && left < 0) // If left value is a negative number a complex rotation will be done.
		Rotation_RL(rooth);
	// If the tree is unbalanced at left a rotation will be done to the right.
	if(balance == -2 && right <= 0) // If both numbers are negative a simply rotation will be done.
		Rotation_LL(rooth);
	if(balance == -2 && right > 0) // If right value is a positive number a complex rotation will be done.
		Rotation_LR(rooth); 	
}

int AVL::Maior(int a, int b){ // Function to find the highest value between two weights.
	if (a > b) return a;
	else return b;
}

void AVL::Rotation_RR(Node* rooth){ 
// Simply Rotation to the left (RR because the unbalancig is caused by two Nodes alingned at right).
	Node* node;
	node = rooth->getLeft();
	// The rooth will become the left child and its right child now will be its parent and the weights will be reset.
	rooth->setLeft(node->getRight());
	node->setRight(rooth);
	rooth->setWeight(Maior(NodeWeight(rooth->getLeft()), NodeWeight(rooth->getRight()))+1);
	node->setWeight(Maior(NodeWeight(node->getLeft()), rooth->getWeight())+1);
	rooth = node;
}

void AVL::Rotation_LL(Node* rooth){
// Simply Rotation to the right (LL because the unbalancig is caused by two Nodes alingned at left).
	Node* node;
	node = rooth->getRight();
	// The rooth will become the right child and its left child now will be its parent and the weights will be reset.
	rooth->setRight(node->getLeft());
	node->setLeft(rooth);
	rooth->setWeight(Maior(NodeWeight(rooth->getLeft()), NodeWeight(rooth->getRight()))+1);
	node->setWeight(Maior(NodeWeight(node->getRight()), rooth->getWeight())+1);
	rooth = node;
}

void AVL::Rotation_RL(Node* rooth){ 
// Complex rotation for when the unbalancing is caused by a Node that is parent of a right child and grandparent of a left child.
	Rotation_RR(rooth->getLeft()); // A simply rotation to the left is called.
	Rotation_LL(rooth); // A simply rotation to the right is called.
}
void AVL::Rotation_LR(Node* rooth){
// Complex rotation for when the unbalancing is caused by a Node that is parent of a left child and grandparent of a right child.
	Rotation_LL(rooth->getRight()); // A simply rotation to the right is called.
	Rotation_RR(rooth); // A simply rotation to the left is called.
}

void AVL::Preorder(Node* rooth){ // Prints the elements of the tree in pre-order.
	if(rooth != NULL){
    	cout << rooth->getValue() << endl;
    	Preorder(rooth->getLeft()); 
    	Preorder(rooth->getRight()); 
  }
}

void AVL::Inorder(Node* rooth){ // Prints the elements of the tree in order, the lowest to the highest.
	if(rooth != NULL){
    	Inorder(rooth->getLeft()); 
    	cout << rooth->getValue() << endl;
    	Inorder(rooth->getRight()); 
  	}
}

void AVL::Postorder(Node* rooth){ // Prints the elements of the tree in post-order.
	if(rooth != NULL){
    	Postorder(rooth->getLeft()); 
    	Postorder(rooth->getRight()); 
    	cout << rooth->getValue() << endl;
  	}
}
