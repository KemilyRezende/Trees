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
   
   Binary Search Tree: It's the most basic tree structure. It may become an unbalanced tree. The worst case is when items are inserted in ascending or descending order, in which case the tree will behave like a linked list having Ω(n) complexity. (https://github.com/KemilyRezende/Trees/tree/main/Binary%20Search%20Tree)
   
   AVL Tree: It's a self-balanced binary search tree. The balance factor is the difference between the heights of the left and right subtrees, if this difference is equal to or higher than 2 the tree will be balanced through simple(Right or Left) or complex(Left-Right or Right-Left) rotations. The complexity is always O(log(n)). (https://github.com/KemilyRezende/Trees/tree/main/AVL)
   
   RedBlack Tree: It's also a self-balancing binary search tree, but now each node has an extra bit, and that bit is interpreted as the color (red or black). These colors are used to ensure that the tree remains balanced during insertions and deletions. To balance the tree rotations will be done in some cases. Differente from AVL, RedBlack uses only simple rotations. The RedBlack Tree's max height is equal to 2log(n-1), so, the search, insert and delete average complexity is O(log(n)) and Ω(2log(n-1)). (https://github.com/KemilyRezende/Trees/tree/main/RedBlack)

# 3. Methods
  
  
# 4. Results

# 5. Conclusion
