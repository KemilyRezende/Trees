#include <iostream>
#include "Tree.hpp"

using namespace std;

Tree::Tree(){ // Constructor that creates an empty tree.
	this->root = NULL;
}

Tree::Tree(float value){ // Constructor that creates a tree with a element inserted in.
	this->root = new Node(value, NULL);
}

Node* Tree::getRoot(){ // Function that returns the Tree's root.
	return this->root;
}

void Tree::EraseTree(){
	this->root->setLeft(NULL);
	this->root->setRight(NULL);
	this->root = NULL;
}

void Tree::InsertBST(float value){ // Inserts a value in the tree.
	if(root == NULL){ // Just works at the first insertion, without it the root isn't seted.
		root = new Node(value, NULL);
	}
	else{ // This function is called for all the later inserts.
		InsertAuxBST(root, value);
	}
}

void Tree::InsertAuxBST(Node* root, float value){ // Function called to insert the elements except the first inserction.
	// It's a recursive function.
	if (root->getValue() > value){
		// Following the rule, if the new value is lower than root's value, the new value is inserted on the left side.
		if (root->getLeft() == NULL){ // If root's left child is empty the element is inserted on it.
			root->setLeft(new Node(value, NULL));
		}
		else { // Else the function is called again, now with the left child as root.
			InsertAuxBST(root->getLeft(), value);
		}
	}
	else if(root->getValue() < value){
		// So also, if the new value is higher than root's value, the new value is inserted on the right side.
		if (root->getRight() == NULL){ // If root's right child is empty the element is inserted on it.
			root->setRight(new Node(value, NULL));
		}
		else { // Else the function is called again, now with the right child as root.
			InsertAuxBST(root->getRight(), value);
		}	
	}
}

void Tree::DeleteBST(Node* root, float value){
	Node* aux;
	if (root == NULL){
		return;
	}
	if (root->getValue() > value){
		DeleteBST(root->getLeft(), value); 
		return;
	}
	else {
		DeleteBST(root->getRight(), value);
		return;
	}
	if (root->getRight() == NULL){
		aux = root;
		root = root->getLeft();
		free(aux);
		return;
	}
	if (root->getLeft() != NULL){
		Antecessor(root->getLeft(), root);
		return;
	}
	aux = root;
	root = root->getRight();
	free(aux);
}

void Tree::Search(Node* root, float value){ // Searches an item in the tree and returns it's Node.
	if (root == NULL){ // If root equals NULL the value wasn't found so the function returns NULL.
		return;
	}
	else if (root->getValue() == value){ // If the searched value is equal the node value returns it.
		return;
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

// AVL FUNCTIONS

void Tree::InsertAVL(float value){ // Inserts a value in the tree.
	if(root == NULL){ // Just works at the first insertion, without it the root isn't seted.
		root = new Node(value, NULL);
	}
	else{ // This function is called for all the later inserts.
		InsertAuxAVL(root, value);
	}
}

void Tree::InsertAuxAVL(Node* root, float value){ // Function called to insert the elements except the first inserction.
	if (root->getValue() > value){ 
	// If the new value is lower than the Node's value the left child will be visited.
		if (root->getLeft() == NULL){ // If the left child is NULL a new Node with the value will be stored in.
	 		root->setLeft(new Node(value, NULL));
	 		rebalanceTree(root); // After every insertion this function is called to maintain tree's balance.
		}
		// If the child isn't NULL the insertion functions is called again now with this Node as root.
		else InsertAuxAVL(root->getLeft(), value);
	}
	else if(root->getValue() < value){ 
	// If the new value is higher than the Node's value the right child will be visited.
		if (root->getRight() == NULL){ // If the right child is NULL a new Node with the value will be stored in.
			root->setRight(new Node(value, NULL));
	 		rebalanceTree(root);	// After every insertion this function is called to maintain tree's balance.
		}
		// If the child isn't NULL the insertion functions is called again now with this Node as root.
		else InsertAuxAVL(root->getRight(), value);
	}
	// Sets the new height of the root.
	root->setWeight(Maior(NodeWeight(root->getLeft()), NodeWeight(root->getRight()))+1);
}

void Tree::DeleteAVL(Node* root, Node* f, float value){
	Node* aux;
	if (root == NULL){
		return;
	}
	if (root->getValue() > value){
		DeleteAVL(root->getLeft(), f, value);
		return;
	}
	else if (root->getValue() < value){
		DeleteAVL(root->getRight(), f, value);
		return;
	}
	if (root->getRight() == NULL){
		aux = root;
		root = root->getLeft();
		free(aux);
		rebalanceTree(f);
		return;
	}
	if (root->getLeft() != NULL){
		Antecessor(root->getLeft(), root);
		rebalanceTree(root);
		rebalanceTree(f);
		return;
	}
	aux = root;
	root = root->getRight();
	free(aux);
	rebalanceTree(root);
	rebalanceTree(f);
}

void Tree::Antecessor(Node* root, Node* aux){
	if (root->getRight() != NULL){
		Antecessor(root->getRight(), aux);
	}
	aux->setValue(root->getValue());
	aux = root;
	root = root->getLeft();
	free(aux);
}

int Tree::NodeWeight(Node* root){ // Function that returns a weight.
	if (root == NULL) return -1;
	else return root->getWeight();
}

int Tree::Balancing(Node* root){ 
// Function that returns a Node's "weight", if it's lower than -2 or higher tha 2 the Node is unbalanced.
	return (NodeWeight(root->getLeft()) - NodeWeight(root->getRight()));
}

void Tree::rebalanceTree(Node* root){ // Function that rebalance tree
	int balance;
  	int left = 0;
  	int right = 0;
	
	// Calls the Balancing function to find the value of the Nodes
	balance = Balancing(root);
	if(root->getLeft())
		left = Balancing(root->getLeft());
	if(root->getRight())
		right = Balancing(root->getRight());
	
	// If the tree is unbalanced at right a rotation will be done to the left.
	if(balance == 2 && left >= 0) // If both numbers are positive a simple rotation will be done.
		Rotation_RR(root);
	if(balance == 2 && left < 0) // If left value is a negative number a complex rotation will be done.
		Rotation_RL(root);
	// If the tree is unbalanced at left a rotation will be done to the right.
	if(balance == -2 && right <= 0) // If both numbers are negative a simply rotation will be done.
		Rotation_LL(root);
	if(balance == -2 && right > 0) // If right value is a positive number a complex rotation will be done.
		Rotation_LR(root); 	
}

int Tree::Maior(int a, int b){ // Function to find the highest value between two weights.
	if (a > b) return a;
	else return b;
}

void Tree::Rotation_RR(Node* root){ 
// Simply Rotation to the left (RR because the unbalancig is caused by two Nodes alingned at right).
	Node* node;
	node = root->getLeft();
	// The root will become the left child and its right child now will be its parent and the weights will be reset.
	root->setLeft(node->getRight());
	node->setRight(root);
	root->setWeight(Maior(NodeWeight(root->getLeft()), NodeWeight(root->getRight()))+1);
	node->setWeight(Maior(NodeWeight(node->getLeft()), root->getWeight())+1);
	root = node;
}

void Tree::Rotation_LL(Node* root){
// Simply Rotation to the right (LL because the unbalancig is caused by two Nodes alingned at left).
	Node* node;
	node = root->getRight();
	// The root will become the right child and its left child now will be its parent and the weights will be reset.
	root->setRight(node->getLeft());
	node->setLeft(root);
	root->setWeight(Maior(NodeWeight(root->getLeft()), NodeWeight(root->getRight()))+1);
	node->setWeight(Maior(NodeWeight(node->getRight()), root->getWeight())+1);
	root = node;
}

void Tree::Rotation_RL(Node* root){ 
// Complex rotation for when the unbalancing is caused by a Node that is parent of a right child and grandparent of a left child.
	Rotation_RR(root->getLeft()); // A simply rotation to the left is called.
	Rotation_LL(root); // A simply rotation to the right is called.
}

void Tree::Rotation_LR(Node* root){
// Complex rotation for when the unbalancing is caused by a Node that is parent of a left child and grandparent of a right child.
	Rotation_LL(root->getRight()); // A simply rotation to the right is called.
	Rotation_RR(root); // A simply rotation to the left is called.
}

// REDBLACK FUNCTIONS

void Tree::InsertRB(float value){ // Inserts a value in the tree.
	if(root == NULL) // Just works at the first insertion, without it the root isn't seted.
		root = new Node(value, NULL);
	else // This function is called for all the later inserts.
		InsertAuxRB(root, value);
}

void Tree::InsertAuxRB(Node* root, float value){
	if (root->getValue() > value){ 
		if (root->getLeft() == NULL){
		// If Node's left child is NULL inserts value on it and set the Node as its parent.
			root->setLeft(new Node(value, root));
			Node* left = root->getLeft();
			if (left->getParent() != this->root) // If new Node's parent is the root it haven't an uncle.
				FixInsert(root->getLeft()); // Call the fixing function to maintain the balance.
		}
		else InsertAuxRB(root->getLeft(), value);
	}
	else if (root->getValue() < value){
		if (root->getRight() == NULL){
		// If Node's right child is NULL inserts value on it and set the Node as its parent.
			root->setRight(new Node(value, root));
			Node* right = root->getRight();
			if (right->getParent() != this->root) // If new Node's parent is the root it haven't an uncle.
				FixInsert(root->getRight()); // Call the fixing function to maintain the balance.
		}
		else InsertAuxRB(root->getRight(), value); 
	}
}

void Tree::FixInsert(Node* child){
// This function is called to maintain the balancing after a inserction 
	Node* uncle;
	while (child != root && child->getParent()->getColor() == false){ 
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
					Rotation_LL_RB(child);
				}
				// Case 3
				child->getParent()->setColor(true);
				child->getParent()->getParent()->setColor(false);
				Rotation_RR_RB(child->getParent()->getParent());
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
					Rotation_RR_RB(child);
				}
				// Case 3
				child->getParent()->setColor(true);
				child->getParent()->getParent()->setColor(false);
				Rotation_LL_RB(child);
			}
		}
	}
	root->setColor(true);
}

void Tree::Rotation_LL_RB(Node* child){
// Rotates the nodes to the right
	Node* x = child;
	Node* y = child->getRight();
	x->setRight(y->getLeft());
	if (y->getLeft() != NULL){
		y->getLeft()->setParent(x);
		y->setParent(x->getParent());
	}
	if (x->getParent() == NULL){
		root = y;
	}
	else{
		if (x == x->getParent()->getLeft()){
			x->getParent()->setLeft(y);
		}
		else if(x == x->getParent()->getRight()){
			x->getParent()->setRight(y);
		}
	}
	y->setLeft(x);
	x->setParent(y);
}

void Tree::Rotation_RR_RB(Node* child){
// Rotates the nodes to the left
	Node* x = child;
	Node* y = child->getLeft();
	x->setLeft(y->getRight());
	if (y->getRight() != NULL){
		y->getRight()->setParent(x);
		y->setParent(x->getParent());
	}
	if (x->getParent() == NULL){
		root = y;
	}
	else{
		if (x == x->getParent()->getRight()){
			x->getParent()->setRight(y);
		}
		else if (x == x->getParent()->getLeft()){
			x->getParent()->setLeft(y);
		}
	}
	y->setRight(x);
	x->setParent(y);
}

void Tree::DeleteRB(Node* aux){
	Node* y = aux;
	Node* x;
	bool original = y->getColor();
	if (aux->getLeft() == NULL){
		x = aux->getRight();
		rbTransplant(aux, aux->getRight());
	}
	else if(aux->getRight() == NULL){
		x = aux->getLeft();
		rbTransplant(aux, aux->getLeft());
	}
	else{
		y = aux->getRight();
		while (y->getLeft() != NULL){
			y = y->getLeft();
		}
		original = y->getColor();
		x = y->getRight();
		if (y->getParent() == aux){
			x->setParent(y);
		}
		else{
			rbTransplant(y, y->getRight());
			y->setRight(aux->getRight());
			y->getRight()->setParent(y);
		}
		rbTransplant(aux, y);
		y->setLeft(aux->getRight());
		y->getLeft()->setParent(y);
		y->setColor(aux->getColor());
	}
	if (original == true){
		FixDelete(x);
	}
	free(aux);
}

void Tree::rbTransplant(Node* u, Node* v) { // Transplant two Nodes.
    if (u->getParent() == NULL) {
      root = v;
    } else if (u == u->getParent()->getLeft()) {
      u->getParent()->setLeft(v);
    } else {
      u->getParent()->setRight(v);
    }
    v->setParent(u->getParent());
  }

void Tree::FixDelete(Node* x){ // Function called to maintain tree's balancing after a deletion
	Node* brother;
	while (x != root && x->getParent()->getColor() == false){
		if (x == x->getParent()->getLeft()){
			brother = x->getParent()->getRight();
			if(brother->getColor() == false){
				brother->setColor(true);
				x->getParent()->setColor(false);
				Rotation_RR_RB(x->getParent());
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
					Rotation_LL_RB(brother);
					brother = x->getParent()->getRight();
				}
				brother->setColor(x->getParent()->getColor());
				x->getParent()->setColor(true);
				brother->getRight()->setColor(true);
				Rotation_RR_RB(x->getParent());
				x = root;
			}
		}
		else {
			brother = x->getParent()->getLeft();
			if (brother->getColor() == false){
				brother->setColor(true);
				x->getParent()->setColor(false);
				Rotation_LL_RB(x->getParent());
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
					Rotation_RR_RB(brother);
					brother = x->getParent()->getLeft();
				}
				brother->setColor(x->getParent()->getColor());
				x->getParent()->setColor(true);
				brother->getLeft()->setColor(true);
				Rotation_LL_RB(x->getParent());
				x = root;
			}
			
		}
		
	}
	x->setColor(true);
}

void Tree::SearchRemove(Node* root, float value){
	Node* aux = root;
	while (aux != NULL && value != aux->getValue()){
		if (aux->getValue() > value){
			aux = aux->getLeft();
		}
		else aux = aux->getRight();
	}
	if (aux->getValue() == value){
		DeleteRB(aux);
	}
}
