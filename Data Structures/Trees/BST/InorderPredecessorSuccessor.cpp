#include<iostream>


using namespace std;


/* Program to find inorder predecessor and successor of a key in a BST-

1)Inorder successor is the left most node in right subtree i.e minimum node in right subtree or right child itelf.
2)Inorder predecessor is the right most node in the left subtree ie maximum node in the left subtree or left child itself.

*/


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


BSTnode *insert(BSTnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		BSTnode *temp  = new BSTnode();
		temp->data = value;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
	}
	
	
	
	//returning root of the updated tree
	return root;
}

BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}

int main()
{
	
	return 0;	
}
