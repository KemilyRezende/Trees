#include <iostream>
#include "Node.hpp"
#ifndef __AVL__HPP
#define __AVL__HPP

using namespace std;

class AVL{
	private:
		Node* rooth;
	public:
		// Constructors
		AVL();
		AVL(int value);
		// Basic Functions
		Node* getRooth();
		void Insert(int value);
		void InsertAux(Node* rooth, int value);
		int Delete(Node* rooth, int value);
		void Search(Node* rooth, int value);
		int Height(Node* rooth);
		// Traversal functions
		void Preorder(Node* rooth);
		void Inorder(Node* rooth);
		void Postorder(Node* rooth);
		// Balancing Functions
			// Weight calculation functions
		int NodeWeight(Node* rooth);
		int Balancing(Node* rooth);
		void rebalanceTree(Node* rooth);
		int Maior(int a, int b);
			// Rotation functions
		void Rotation_RR(Node* rooth);
		void Rotation_LL(Node* rooth);
		void Rotation_RL(Node* rooth);
		void Rotation_LR(Node* rooth);
};

#endif
