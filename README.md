# Trees
Behavior of binary search, AVL and redBlack trees and comparative analysis between them.

# What is a tree?
Is a node-based data structure, which each node have a value stored and pointers to others two nodes, Left child  and Right child.
There are some rules that must be followed when building this structure:
  1. The left child's value is always less than its parent node's value.
  2. The right child's value is always greater than its parent node's value.
  3. The left and the right subtree each must also be a tree.
# Why use Trees?
Tree's search behave like an divide-and-conquer algorithm, half items are discard in every interaction until find the searched item. When balanced, the tree's height will be equal log(n), with n being the number of items in the tree. The tree's height is also the max number of comparations until find an item, ie, a tree has complexity O(log(n)).
When more searchs will be done than insertions and remotions trees are great algorithms for dealing with the problem.
# Binary Search Tree
