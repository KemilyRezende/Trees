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
		void Search(Node* root, float value);
		// Binary Search Tree functions
		void InsertBST(float value);
		void InsertAuxBST(Node* root, float value);
		void DeleteBST(Node* root, float value);
		// AVL functions
		void InsertAVL(float value);
		void InsertAuxAVL(Node* root, float value);
		void DeleteAVL(Node* root, Node* f, float value);
		int NodeWeight(Node* root);
		int Balancing(Node* root);
		void rebalanceTree(Node* root);
		int Maior(int a, int b);
		void Rotation_RR(Node* root);
		void Rotation_LL(Node* root);
		void Rotation_RL(Node* root);
		void Rotation_LR(Node* root);
		void Antecessor(Node* root, Node* aux);
		// RedBlack functions
		void InsertRB(float value);
		void InsertAuxRB(Node* root, float value);
		void DeleteRB(Node* aux);
		void FixInsert(Node* child);
		void FixDelete(Node* x);
		void rbTransplant(Node* u, Node* v);
		void Rotation_LL_RB(Node* child);
		void Rotation_RR_RB(Node* child);
		void EraseTree();
		void SearchRemove(Node* root, float value);
};

#endif
