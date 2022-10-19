#include <iostream>
#include "AVL.hpp"
#include <cstdlib> 

using namespace std;

AVL::AVL(){ // Creates an empty tree.
	this->root = NULL;
}

AVL::AVL( vafloatlue){ // Creates a tree with a value inserted.
	this->root = new Node(value);
}

Node* AVL::getRoot(){ // Returns tree's root.
	return this->root;
}

void AVL::Insert(float value){ // Inserts a value in the tree.
	if(root == NULL){ // Just works at the first insertion, without it the root isn't seted.
		root = new Node(value);
	}
	else{ // This function is called for all the later inserts.
		InsertAux(root, value);
	}
}

void AVL::InsertAux(Node* root, float value){ // Function called to insert the elements except the first inserction.
	if (root->getValue() > value){ 
	// If the new value is lower than the Node's value the left child will be visited.
		if (root->getLeft() == NULL){ // If the left child is NULL a new Node with the value will be stored in.
	 		root->setLeft(new Node(value));
	 		rebalanceTree(root); // After every insertion this function is called to maintain tree's balance.
		}
		// If the child isn't NULL the insertion functions is called again now with this Node as root.
		else InsertAux(root->getLeft(), value);
	}
	else if(root->getValue() < value){ 
	// If the new value is higher than the Node's value the right child will be visited.
		if (root->getRight() == NULL){ // If the right child is NULL a new Node with the value will be stored in.
			root->setRight(new Node(value));
	 		rebalanceTree(root);	// After every insertion this function is called to maintain tree's balance.
		}
		// If the child isn't NULL the insertion functions is called again now with this Node as root.
		else InsertAux(root->getRight(), value);
	}
	// Sets the new height of the root.
	root->setWeight(Maior(NodeWeight(root->getLeft()), NodeWeight(root->getRight()))+1);
}

void AVL::Search(Node* root, int value){ // Searches an item in the tree and returns it's Node.
	if (root == NULL){ // If root equals NULL the value wasn't found the function spans an advice and returns NULL.
		cout << "\n[ERROR]: Value not found\n";
	}
	else if(root->getValue() == value){ // If Node's value is equal the seached value return this Node.
		cout << "Valor encontrado: " << root->getValue() << endl;
	}
	else{
		if (root->getValue() > value){ 
		// If Node's value is higher than searched value the function is called again, now with the Left child as root.
			Search(root->getLeft(), value);
		}
		else if(root->getValue() < value){
		// If Node's value is lower than searched value the function is called again, now with the Right child as root.
			Search(root->getRight(), value);
		}
	}
}

int AVL::Delete(Node* root, int value){
	if (root == NULL){ 
	// When Serch returns a NULL value that means that the searched value wasn't inserted in the tree.
		cout << "\n[ERROR]: Value not found" << endl;
		return 0;
	}
	else if (root->getLeft()->getValue() == value && root->getLeft()->getLeft() == NULL && root->getLeft()->getRight() == NULL){
	// Deletion if the node that store the value is a leaf (a Node's left child).
		Node* aux = root->getLeft();
		root->setLeft(NULL);
		free(aux);
		return 1;
	}
	else if (root->getRight()->getValue() == value && root->getRight()->getLeft() == NULL && root->getRight()->getRight() == NULL){
	// Deletion if the node that store the value is a leaf (a Node's right child).
		Node* aux = root->getRight();
		root->setRight(NULL);
		free(aux);
		return 1;
	}
	else if(value < root->getValue()){
	// If the searched value is lower than atual Node's value the function is called again, now with Node's Left child as root.
		if (Delete(root->getLeft(), value) == 1) // If Deletion works, calls the function to maintain tree's balance.
			rebalanceTree(root->getLeft());
	}
	else if (value > root->getValue()){
	// If the searched value is higher than atual Node's value the function is called again, now with Node's Right child as root.
		if (Delete(root->getRight(), value) == 1) // If Deletion works, calls the function to maintain tree's balance.
			rebalanceTree(root->getRight());
	}
	else if (value == root->getValue()){ 
		if(root->getRight() != NULL && root->getLeft() != NULL){ // Node with two children.
			Node* aux = root->getRight();
			while (aux->getLeft()!= NULL){ // The lowest value is the last left child on the sub-tree.
				aux = aux->getLeft();
			}
			root->setValue(aux->getValue()); // The value to be deleted will be replaced by the lowest value.
			aux = NULL; // The lowest value will be deleted at this position.
			rebalanceTree(root->getLeft());
		}
		else { // Node with one child. 
		// The deleted node will be replaced by its child.
			if (root->getLeft() != NULL){ // Node with Left child.
				root->setValue(root->getLeft()->getValue()); 
				root->setLeft(NULL);
				free(root->getLeft());
			}
			else if (root->getRight() != NULL){ // Node with Right child.
				root->setValue(root->getRight()->getValue());
				root->setRight(NULL);
				free(root->getRight());	
			}
		}
		return 1;
	}
	return 1;
}

int AVL::Height(Node* root){ // Function that returns tree's height.
	if (root == NULL){
		return -1; //Empty tree's height
	}
	else {
		int Left_height = Height(root->getLeft());
		int Right_height = Height(root->getRight());
		if (Left_height < Right_height) return Right_height + 1;
		else return Left_height + 1;
	}
}

int AVL::NodeWeight(Node* root){ // Function that returns a weight.
	if (root == NULL) return -1;
	else return root->getWeight();
}

int AVL::Balancing(Node* root){ 
// Function that returns a Node's "weight", if it's lower than -2 or higher tha 2 the Node is unbalanced.
	return (NodeWeight(root->getLeft()) - NodeWeight(root->getRight()));
}

void AVL::rebalanceTree(Node* root){ // Function that rebalance tree
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

int AVL::Maior(int a, int b){ // Function to find the highest value between two weights.
	if (a > b) return a;
	else return b;
}

void AVL::Rotation_RR(Node* root){ 
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

void AVL::Rotation_LL(Node* root){
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

void AVL::Rotation_RL(Node* root){ 
// Complex rotation for when the unbalancing is caused by a Node that is parent of a right child and grandparent of a left child.
	Rotation_RR(root->getLeft()); // A simply rotation to the left is called.
	Rotation_LL(root); // A simply rotation to the right is called.
}
void AVL::Rotation_LR(Node* root){
// Complex rotation for when the unbalancing is caused by a Node that is parent of a left child and grandparent of a right child.
	Rotation_LL(root->getRight()); // A simply rotation to the right is called.
	Rotation_RR(root); // A simply rotation to the left is called.
}

void AVL::Preorder(Node* root){ // Prints the elements of the tree in pre-order.
	if(root != NULL){
    	cout << root->getValue() << endl;
    	Preorder(root->getLeft()); 
    	Preorder(root->getRight()); 
  }
}

void AVL::Inorder(Node* root){ // Prints the elements of the tree in order, the lowest to the highest.
	if(root != NULL){
    	Inorder(root->getLeft()); 
    	cout << root->getValue() << endl;
    	Inorder(root->getRight()); 
  	}
}

void AVL::Postorder(Node* root){ // Prints the elements of the tree in post-order.
	if(root != NULL){
    	Postorder(root->getLeft()); 
    	Postorder(root->getRight()); 
    	cout << root->getValue() << endl;
  	}
}