# Trees
Behavior of binary search, AVL and redBlack trees and comparative analysis between them.

# 1. Abstract
   This work attemps to understand and compare the Binary Search Tree, AVL and RedBlack data structures. To achieve this objective, two steps will be taken: developing each structure separately to understand their behavior and then comparing their insertion, search and deletion functions.

# 2. Introduction
   A tree is a node-based data structure, which each node have a value stored and pointers to others two nodes, Left child  and Right child.
   There are some rules that must be followed when building this structure:
   1. The left child's value is always less than its parent node's value.
   2. The right child's value is always greater than its parent node's value.
   3. The left and the right subtree each must also be a tree.
   
   Tree's search behave like an divide-and-conquer algorithm, half items are discard in every interaction until find the searched item. When balanced, the tree's height will be equal log(n), with n being the number of items in the tree. The tree's height is also the max number of comparations until find an item, ie, a tree has O(log(n)) complexity. When more searchs will be done than insertions and deletions trees are great algorithms for dealing with the problem.
   
   Binary Search Tree: It's the most basic tree structure. It may become an unbalanced tree. The worst case is when items are inserted in ascending or descending order, in which case the tree will behave like a linked list having Ω(n) complexity. https://github.com/KemilyRezende/Trees/tree/main/Binary%20Search%20Tree
   
   AVL Tree: It's a self-balanced binary search tree. The balance factor is the difference between the heights of the left and right subtrees, if this difference is equal to or higher than 2 the tree will be balanced through simple(Right or Left) or complex(Left-Right or Right-Left) rotations. The complexity is always O(log(n)). https://github.com/KemilyRezende/Trees/tree/main/AVL
   
   RedBlack Tree: It's also a self-balancing binary search tree, but now each node has an extra bit, and that bit is interpreted as the color (red or black). These colors are used to ensure that the tree remains balanced during insertions and deletions. To balance the tree rotations will be done in some cases. Differente from AVL, RedBlack uses only simple rotations. The RedBlack Tree's max height is equal to 2log(n-1), so, the search, insert and delete average complexity is O(log(n)) and Ω(2log(n-1)). https://github.com/KemilyRezende/Trees/tree/main/RedBlack

# 3. Methods
  At first, the trees were developed in c++ as seen on links above, and then, were united in a program to compare the execution time difference between them.
  Each one was underwent insertions, searches and deletions. Four different files were read with respectively 500, 5000, 50000 and 500000 elements (float type values). In each procedure the values were inserted and then 10000 searches were done with values from another file. After the searches, this values will be deleted on the tree. All this procedures were also made in an Ordered Vector to compare with the trees.
  The vector was ordered using qsort function and the searches were done with binary_search function.
  
# 4. Results

<img src="https://github.com/KemilyRezende/Trees/blob/main/img/Arquivo%20500.png" width = "400px" height = "400px">
<img src="https://github.com/KemilyRezende/Trees/blob/main/img/Arquivo%205000.png" width = "400px" height = "400px">
<img src="https://github.com/KemilyRezende/Trees/blob/main/img/Arquivo%2050000.png" width = "400px" height = "400px">
<img src="https://github.com/KemilyRezende/Trees/blob/main/img/Arquivo%20500000.png" width = "400px" height = "400px">

# 5. Conclusion
After develop and compare the structures it's verified that AVL tree is the faster when searching, this is due to the fact of it has a strong balancing maintanace where a subtree is allowed to be in only one level lower that the other, so, the complexity is always close to log(n). 

There's no gain related to the memory cust using trees.

The maps structure is frequently used to simulate trees, so in a big data base it's faster than a vector.
In this analysis the vector execution time is close to AVL because the binary_search function was used, for being also a divide-and-conquer function, its complexity is close to AVL tree. The binary_search function was also used to validate the deletion and a big part of the searched values weren't insert at the tree, all of this colabores to this result.

For subsequentes works is important to deal with the uncertainties at RedBlack and Binary Search Tree. Must probably, their worst cases has been occured to generate higher execution time cust.
