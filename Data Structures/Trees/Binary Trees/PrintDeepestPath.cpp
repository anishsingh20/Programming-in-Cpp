#include<iostream>

//IMPLEMENTATION OF FINDING HEIGHT OF BINARY TREE - height is the longest path from the root of the tree to the deepest node(leaf)

using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



int height(struct BinaryTreeNode *root)
{
	if(root)
	{
		return (1 + max( height(root->right) , height(root->left) );
	}
	
	else {
		return 0;
	}
}



void TopView(struct BinaryTreeNode *root)
{
	if(!root) return;
	
	
	
	
	if(root)
	{
		//heights of left and right subtree
		int hl = height(root->left);
		
		int hr = height(root->right);
		cout<<root->data<<" ";
		
		if(hl >= hr) TopView(root->left);
		
		else TopView(root->right);
	}
	
}
