#include <iostream>
#include "Tree.hpp"

using namespace std;

int main(){
	int op;
	float value;
	Tree T;
	do{
		cout << "\nMENU:\n1. Insert.\n2. Search.\n3. Delete.\n4. Preorder Traversal.\n5. Inorder Traversal.\n6. Postorder Traversal.\n7. Height.\n8. Exit.\n";
		cin >> op;
		switch(op){
			case 1:
				cout << "\nValue to insert: ";
				cin >> value;
				T.Insert(value);
				break;
			case 2:
				cout << "\nValue to search: ";
				cin >> value;
				T.Search(T.getRoot(), value);
				break;
			case 3:
				cout << "\nValue to delete: ";
				cin >> value;
				T.Delete(T.getRooth(), value);
				break;
			case 4:
				cout << "\nPreorder traversal:\n";
				T.Preorder(T.getRooth());
				break;
			case 5:
				cout << "\nInorder Traversal:\n";
				T.Inorder(T.getRooth());
				break;
			case 6:
				cout << "\nPostorder Traversal:\n";
				T.Postorder(T.getRooth());
				break;
			case 7:
				cout << "\nTree's height': " << T.Height(T.getRooth());
				break;
			case 8:
				cout << "\nShutting down...";
				break;
		}	
	}while(op!=8);
	return 0;
}