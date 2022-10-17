#include <iostream>
#include "Node.hpp"
#ifndef __REDBLACK__HPP
#define __REDBLACK__HPP

using namespace std;

class RedBlack{
	private:
		Node* rooth;
	public:
	// Constructors
		RedBlack();
		RedBlack(float value);
	// Basic Functions
		Node* getRooth();
		void Insert(float value);
		void InsertAux(Node* rooth, float value);
		void Delete(Node* rooth, float value);
		void Search(Node* rooth, float value);
		int Height(Node* rooth);
	// Functions to maintain tree's balancing
		void FixInsert(Node* child);
		void FixDelete(Node* x);
		void rbTransplant(Node* u, Node* v);
		void Rotation_LL(Node* child);
		void Rotation_RR(Node* child);
	// Traversal functions
		void Preorder(Node* rooth);
		void Inorder(Node* rooth);
		void Postorder(Node* rooth);
};

#endif
