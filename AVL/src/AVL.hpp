#include <iostream>
#include "Node.hpp"
#ifndef __AVL__HPP
#define __AVL__HPP

using namespace std;

class AVL{
	private:
		Node* root;
	public:
		// Constructors
		AVL();
		AVL(int value);
		// Basic Functions
		Node* getRoot();
		void Insert(float value);
		void InsertAux(Node* root, int value);
		int Delete(Node* root, int value);
		void Search(Node* root, int value);
		int Height(Node* root);
		// Traversal functions
		void Preorder(Node* root);
		void Inorder(Node* root);
		void Postorder(Node* root);
		// Balancing Functions
			// Weight calculation functions
		int NodeWeight(Node* root);
		int Balancing(Node* root);
		void rebalanceTree(Node* root);
		int Maior(int a, int b);
			// Rotation functions
		void Rotation_RR(Node* root);
		void Rotation_LL(Node* root);
		void Rotation_RL(Node* root);
		void Rotation_LR(Node* root);
};

#endif