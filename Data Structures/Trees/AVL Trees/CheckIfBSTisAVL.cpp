#include<iostream>



//program to check is a BST is AVL tree or not

using namespace std;

struct BSTnode {
	
	int data,height;
	struct BSTnode *left,*right;	
};

