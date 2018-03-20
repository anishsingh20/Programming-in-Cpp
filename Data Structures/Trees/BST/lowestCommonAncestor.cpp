#include<iostream>


using namespace std;


/* Program to find the LCA of 2 nodes in a BST.

if the root's data lies between n1 and n2  then that is the LCA of n1 and n2. If root->aata is less than n1, then LCA is in right subtree, otherwise LCA is in the

left subtree.

LCA(n1,n2) is useful in calculating the distance between 2 nodes in a BST.

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
	
	BSTnode *root  = newNode(7);

	insert(root,3);
	insert(root,10);
	
	insert(root,12);
	insert(root,2);
	insert(root,1);
}
