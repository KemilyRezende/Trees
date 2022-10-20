#include <iostream>
#include "Tree.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>  
#include <random>
#include <chrono>
#include <vector>

using namespace std;

int cmp(const void *one, const void *two){
	float a = *((float*)one);
	float b = *((float*)two);
	if (a > b) return -1;
	if (a == b) return 0;
	else return 1;
}

/*void createFiles(){ // Function that creates the files with random values.
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<> distr(1, 500);
	ofstream file1("File_500.txt");
	for (int i = 0; i < 500; i++){
		file1 << distr(eng);
	}
	file1.close();
	
	ofstream file2("File_5000.txt");
	for (int i = 0; i < 5000; i++){
		file2 << distr(eng);
	}
	file2.close();
	
	ofstream file3("File_50000.txt");
	for (int i = 0; i < 50000; i++){
		file3 << distr(eng);
	}
	file3.close();
	
	ofstream file4("File_500000.txt");
	for (int i = 0; i < 500000; i++){
		file4 << distr(eng);
	}
	file4.close();

	ofstream file5("Search.txt");
	for (int i = 0; i < 10000; i++){
		file5 << distr(eng);
	}
	file5.close();
}*/

int main(){
	Tree BST;  // Binary Search Tree
	Tree AVL; // AVL Tree
	Tree RB; // RedBlack Tree
	vector<float> Vet;
	//createFiles(); // Calls the function to creates the files.
	float value;
	ifstream File1;
	File1.open("File_500.txt");
	ifstream search;
	
	search.open("Search.txt");
	cout << "________________________________________________\n";
	cout << "File with 500:\n";
	// BST
	cout << "Binary Search Tree:" << endl;
	
	chrono::steady_clock::time_point start;
	chrono::steady_clock::time_point end;

	start = chrono::steady_clock::now();
	while(!(File1.eof())){
		File1 >> value;
		BST.InsertBST(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.Search(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.DeleteBST(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	BST.EraseTree();

	// AVL
	cout << "AVL Tree:" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File1.eof())){
		File1 >> value;
		AVL.InsertAVL(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.Search(AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.DeleteAVL(AVL.getRoot(), AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	AVL.EraseTree();
	
	// RedBlack
	cout << "RedBlack Tree" << endl;

	start = chrono::steady_clock::now();
	while(!(File1.eof())){
		File1 >> value;
		RB.InsertRB(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld nanooseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.Search(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.SearchRemove(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	RB.EraseTree();
	// Ordered Vector
	cout << "Ordered Vector: " << endl;
	
	start = chrono::steady_clock::now();
	while(!(File1.eof())){
		File1 >> value;
		Vet.push_back(value);
	}
	qsort(Vet.data(), Vet.size(), sizeof(float), cmp);
	end = chrono::steady_clock::now();
	printf("Insertions: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	
	File1.close();
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		if(binary_search(Vet.begin(), Vet.end(), value)){
			
		}
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		if(binary_search(Vet.begin(), Vet.end(), value)){
			for (long unsigned int k = 0; k < Vet.size(); k++){
				if (Vet[k] == value){
					Vet.erase((Vet.begin()+k), (Vet.begin())+k+1);
					break;
				}
			}
		}
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	Vet.clear();
	cout << "________________________________________________\n";
	cout << "File with 5000:\n";
	ifstream File2;
	File2.open("File_5000.txt");
	
	cout << "Binary Search Tree:" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File2.eof())){
		File2 >> value;
		BST.InsertBST(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.Search(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.DeleteBST(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	BST.EraseTree();
	
	// AVL
	cout << "AVL Tree:" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File2.eof())){
		File2 >> value;
		AVL.InsertAVL(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.Search(AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.DeleteAVL(AVL.getRoot(), AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanooseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	AVL.EraseTree();
	
	// RedBlack
	cout << "RedBlack Tree" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File2.eof())){
		File2 >> value;
		RB.InsertRB(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.Search(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.SearchRemove(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	RB.EraseTree();
	
	// Ordered Vector
	cout << "Ordered Vector: " << endl;
	
	start = chrono::steady_clock::now();
	while(!(File2.eof())){
		File2 >> value;
		Vet.push_back(value);
	}
	qsort(Vet.data(), Vet.size(), sizeof(float), cmp);
	end = chrono::steady_clock::now();
	printf("Insertions: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	File2.close();
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		if(binary_search(Vet.begin(), Vet.end(), value)){
			
		}
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		for (long unsigned int k = 0; k < Vet.size(); k++){
				if (Vet[k] == value){
					Vet.erase((Vet.begin()+k), (Vet.begin())+k+1);
					break;
				}
			}
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	Vet.clear();
	
	cout << "________________________________________________\n";
	cout << "File with 50000:\n";
	ifstream File3;
	File3.open("File_50000.txt");
	
	cout << "Binary Search Tree:" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File3.eof())){
		File3 >> value;
		BST.InsertBST(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.Search(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.DeleteBST(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	BST.EraseTree();
	
	// AVL
	cout << "AVL Tree:" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File3.eof())){
		File3 >> value;
		AVL.InsertAVL(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.Search(AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.DeleteAVL(AVL.getRoot(), AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	AVL.EraseTree();
	
	// RedBlack
	cout << "RedBlack Tree" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File3.eof())){
		File3 >> value;
		RB.InsertRB(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.Search(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.SearchRemove(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	RB.EraseTree();
	
	// Ordered Vector
	cout << "Ordered Vector: " << endl;
	
	start = chrono::steady_clock::now();
	while(!(File3.eof())){
		File3 >> value;
		Vet.push_back(value);
	}
	qsort(Vet.data(), Vet.size(), sizeof(float), cmp);
	end = chrono::steady_clock::now();
	printf("Insertions: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	File3.close();
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		if(binary_search(Vet.begin(), Vet.end(), value)){
			
		}
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		for (long unsigned int k = 0; k < Vet.size(); k++){
				if (Vet[k] == value){
					Vet.erase((Vet.begin()+k), (Vet.begin())+k+1);
					break;
				}
			}
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	Vet.clear();
	
	cout << "________________________________________________\n";
	cout << "File with 500000:\n";
	ifstream File4;
	File4.open("File_500000.txt");
	
	cout << "Binary Search Tree:" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File4.eof())){
		File4 >> value;
		BST.InsertBST(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.Search(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		BST.DeleteBST(BST.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	BST.EraseTree();
	// AVL
	cout << "AVL Tree:" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File4.eof())){
		File4 >> value;
		AVL.InsertAVL(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.Search(AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		AVL.DeleteAVL(AVL.getRoot(), AVL.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	AVL.EraseTree();
	
	ifstream File4;
	File4.open("File_500000.txt");
	// RedBlack
	cout << "RedBlack Tree" << endl;
	
	start = chrono::steady_clock::now();
	while(!(File4.eof())){
		File4 >> value;
		RB.InsertRB(value);
	}
	end = chrono::steady_clock::now();
	printf("Insertions: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.Search(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld milliseconds\n", chrono::duration_cast<chrono::milliseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		RB.SearchRemove(RB.getRoot(), value);
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	RB.EraseTree();
	
	// Ordered Vector
	cout << "Ordered Vector: " << endl;
	
	start = chrono::steady_clock::now();
	while(!(File4.eof())){
		File4 >> value;
		Vet.push_back(value);
	}
	qsort(Vet.data(), Vet.size(), sizeof(float), cmp);
	end = chrono::steady_clock::now();
	printf("Insertions: %ld microseconds\n", chrono::duration_cast<chrono::microseconds>(end - start).count());
	File4.close();
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		if(binary_search(Vet.begin(), Vet.end(), value)){
			
		}
	}
	end = chrono::steady_clock::now();
	printf("Searches: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	
	start = chrono::steady_clock::now();
	while(!(search.eof())){
		search >> value;
		for (long unsigned int k = 0; k < Vet.size(); k++){
				if (Vet[k] == value){
					Vet.erase((Vet.begin()+k), (Vet.begin())+k+1);
					break;
				}
			}
	}
	end = chrono::steady_clock::now();
	printf("Deletions: %ld nanoseconds\n", chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	cout << "------------------------------------------------\n";
	Vet.clear();
	search.close();
	
	return 0;
}
