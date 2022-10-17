#include <iostream>
#include "Node.hpp"
#ifndef __TREE__HPP
#define __TREE__HPP

using namespace std;

class Tree{
	private:
		Node* rooth;
	public:
		// Constructors
		Tree();
		Tree(float value);
		// Basic functions
		Node* getRooth();
		void Insert(float value);
		void InsertAux(Node* rooth, float value);
		void Delete(Node* rooth, float value);
		void Search(Node* rooth, float value);
		int Height(Node* rooth);
		// Traversal Functions
		void Preorder(Node* rooth);
		void Inorder(Node* rooth);
		void Postorder(Node* rooth);
};

#endif
