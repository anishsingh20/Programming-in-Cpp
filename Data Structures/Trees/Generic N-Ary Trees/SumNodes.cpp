#include<iostream>

//PROGRAM TO FIND SUM OF NODES IN A GENERIC TREE

using namespace std;

struct TreeNode{
	int data;
	struct TreeNode *firstChild;
	struct TreeNode *nextSibling;
};

