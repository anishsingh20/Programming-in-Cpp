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


AVLnode *insert(AVLnode *root,int value)
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


AVLnode *newNode(int data)
{
	AVLnode *temp = new AVLnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}

void InorderTraverse(AVLnode *root)
{
	InorderTraverse(root->left);
	
	cout<<root->data<<" ";
	
	InorderTraverse(root->right);
}


int main()
{
	AVLnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);
	
	
	
	
}

