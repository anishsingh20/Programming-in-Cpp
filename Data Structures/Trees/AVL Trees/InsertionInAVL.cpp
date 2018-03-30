#include<iostream>
#include "SingleLLRotation.cpp"
#include "SIngleRRrotation.cpp"
#include "DoubleLeftRightRotation.cpp"
#include "DoubleRightLeftRotation.cpp"


//program to do insertion in an AVL tree. Similar to BST insertion with onlu caution that we check after every insertion
// for the appropiate rotation to be applied for balancing the tree.

using namespace std;

struct AVLnode {
	
	int data,height;
	struct AVLnode *left,*right;	
};


