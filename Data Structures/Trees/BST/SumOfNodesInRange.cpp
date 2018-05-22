#include<iostream>


//program to find sum of nodes within a range L and H , for a BST
using namespace std;


struct node {
	int data;
	struct node *left,*right;	
		
};


struct node *newNode(int data)
{
	struct node *temp = new node();
	temp->data = data;
	
	return temp;
}


truct node* insert(node *root,int data)
{
	if(root==NULL)
	{
		return newNode(data);
	}
	
	if(root->data > data)
	{
		root->left = insert(root->left,data);
		
	}
	
	if(root->data < data)
	{
		root->right = insert(root->right,data);
	}
		
	return root;
	
}


int main()
{
	return 0;
}
