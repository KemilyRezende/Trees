# Binary Search Tree

  As we already have seen, it's a Node-based data structure, which each node have a value stored and pointers to others two nodes, Left child and Right child.  It's used to optimize searches, having an average log(n) complexity.
  
# Insertion
  
 The insertion in a Binary Search Tree follow the mentioned rule, if the value to insert is lower than a Node's value the left child will be verified, else the right child until a NULL value be found, then, in this position a new node will be created storing the inserted value. The image 1 show how the sequence [10, 16, 13, 7, 5, 10, 9] would be inserted. The squares represents NULL children. If a value has already been inserted in the tree it will not be inserted twice.
 
<img src="https://github.com/KemilyRezende/Trees/blob/main/Binary%20Search%20Tree/img/Insert.jpg" width = "400px" height = "400px">
Image 1 - Insertions in a Tree.
 
 # Deletion
 
  There is three different cases when deleting a value on a tree:
      1. Value stored in a Node that has one child.
      2. Value stored in a Node that has two children.
      3. Value stored in a Leaf Node (Node with no children).
  To aproach which one the tree at the following image will be taken as example and then a sequence of deletions will be done.
  
  <img src="https://github.com/KemilyRezende/Trees/blob/main/Binary%20Search%20Tree/img/Tree.jpg" width = "400px" height = "400px">
      
   Case 1: To aproach this case the value deleted value will be 16. When the deleted Node has only one child it will just be replaced by it.
      
   <img src="https://github.com/KemilyRezende/Trees/blob/main/Binary%20Search%20Tree/img/One-child-delete.jpg" width = "400px" height = "400px">

   Case 2: It's the most complicated one, when a Node has two childrens it's impossible just replace it  by one of then because it could break the insertion rule (lowest values at left, higher at right). So, the lowest value will be searched in the right subtree and then the Node with a value to be deleted will store this new value and the Node that was storing it will be deleted. The value 7 will be deleted.
      
   <img src="https://github.com/KemilyRezende/Trees/blob/main/Binary%20Search%20Tree/img/Two-children-delete.jpg" width = "400px" height = "400px">

   Case 3: It's the simplest one, if a Node has no children it will just be equaled to NULL. The value 5 will be deleted.
   
   <img src="https://github.com/KemilyRezende/Trees/blob/main/Binary%20Search%20Tree/img/Leaf-delete.jpg" width = "400px" height = "400px">
     
# Search

  The search in trees works just like the insertion, but instead to keep calling the function again until finds a NULL value it will stops when find the searched value. If the function find a NULL value, that means that the searched value does not exists in the tree.
 
 # Height
 
  A Tree's height corresponds to the deepest Node inserted. In a Balanced Tree, height will e equal to log(n), with n being the number of insertions on it. The concept of Height in Trees is important because it's the same value of the worst case complexity in insertion, search and deletion functions.
  The Binary Search Tree has no functions to maintain the balancing, so, in the worst case, when values are inserted in ascending or descending order, tree will have height equals to n, behaving like a linked list.
 
 # Files:
  Node.hpp and Node.cpp:
    Items:
      value: Store the value inserted into the Node, in that case is a float value.
      Right: It's a pointer to the Node's Right child.
      Left: It's a pointer to the Node's Left child.
    Functions:
      Node:  It's the class constructor, initializes the items assingning a value to "value", and sets the children as NULL. (Parameter: a float type value).
      setValue: Sets the "value" variable. (Parameter: a float type value).
      getValue: Returns "value".
      setRight: Sets the value of Node's Right child. (Parameter: a Node* type value).
      getRight: Returns the Node's Right child.
      setLeft: Sets the value of Node's Left child. (Parameter: a Node* type value).
      getLeft: Returns the Node's Left child.
  Tree.hpp and Tree.cpp
    Item:
      root: It's a Node* type variable that stores the Tree's root
    Functions:
      Tree: It's a empty constructor that initializes root as NULL
      Tree: It's a constructor that initializes root with a value. (Parameter: a float type value).
      getRoot: Returns the root.
      Insert: It inserts a value on the tree, actually just sets the rooth if it equals to NULL, else calls InsertAux to the following insertions. (Parameter: a float type value).
      InsertAux: Is called to insert values after root has been inserted. It follows the method already approached. (Parameters: a Node* value as root and a float type value).
      Delete: Deletes items as the method already approached.
      Search: Searches items as the method already approached.
      Height: Returns Tree's height.
      Preorder: Prints Tree's values following preorder traversal.
      Inorder: Prints Tree's value from the lowest to the highest.
      Postorder: Prints Tree's Value following postorder traversal.
        Using the Tree (Image 2) as an example, the prints would be: Preorder: [10, 7, 5, 9, 16, 13]; Inorder: [5, 7, 9, 10, 13, 16] and Postorder: [5, 9, 7, 13, 16, 10].
