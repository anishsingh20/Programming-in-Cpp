#include<iostream>

using namespace std;

/* FInding Kth largest element in a BST using MORRIS TRAVERAL to do reverse inorder traversal which uses constant extra memory of O(1).
Reverse inorder traversal implemented using Stack or Recursion both consumes extra memory of order O(n). Hence to improve the efficieny we do traversal
faster we use Morris traversal to do reverse inorder traversal which is based on THREAED TREES to do faster inorder traversal.

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
	BSTnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);

int main()
{
	return 0;
}
