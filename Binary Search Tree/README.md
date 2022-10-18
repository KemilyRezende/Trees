# Binary Search Tree

  As we already have seen, it's a Node-based data structure, which each node have a value stored and pointers to others two nodes, Left child and Right child.  It's used to optimize searches, having an average log(n) complexity.
  
# Insertion
  
 The insertion in a Binary Search Tree follow the mentioned rule, if the value to insert is lower than a Node's value the left child will be verified, else the right child until a NULL value be found, then, in this position a new node will be created storing the inserted value. The image 1 show how the sequence [10, 16, 13, 7, 5, 10, 9] would be inserted. The squares represents NULL children. If a value has already been inserted in the tree it will not be inserted twice. 
