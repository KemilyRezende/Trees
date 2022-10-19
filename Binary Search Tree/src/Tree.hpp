#include <iostream>
#include "Node.hpp"
#ifndef __TREE__HPP
#define __TREE__HPP

using namespace std;

class Tree{
	private:
		Node* root;
	public:
		// Constructors
		Tree();
		Tree(float value);
		// Basic functions
		Node* getRoot();
		void Insert(float value);
		void InsertAux(Node* root, float value);
		void Delete(Node* root, float value);
		void Search(Node* root, float value);
		int Height(Node* root);
		// Traversal Functions
		void Preorder(Node* root);
		void Inorder(Node* root);
		void Postorder(Node* root);
};

#endif