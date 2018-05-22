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


struct node* insert(node *root,int data)
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


//recursive implementation

int getSum(node *root,int l,int h)
{
	if(!root)
		return 0;
		
	if(root->data >= l)
		return getSum(root->right,l,h);
			
	if(root->data <= h)
		return getSum(root->left,l,h);
		
	if(root->data >= l && root->data <= h)
	{
		return ( getSum(root->left,l,h) + root->data + getSum(root->left,l,h) ); 
		}	
		
	
}

int main()
{
	node *root  = newNode(20);
   	insert(root,4);
	insert(root,8);
	insert(root,12);
	insert(root,22);
    
    cout<<getSum(root,4,22);
	
	return 0;
}
