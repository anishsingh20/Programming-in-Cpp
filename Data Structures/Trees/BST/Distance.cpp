#include<iostream>


using namespace std;

/*Program to find distance between 2 nodes in BST
*/


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



//program to find distance between root node and key
int findLevel(BSTnode *root,int key,int d=0)
{
	if(!root)
		return -1;
		
	if(root->data==key)
		return d;
	
	if(root->data < key)
	{
		return findLevel(root->right,key,d+1);
	}
	
	if(root->data > key)
	{
		return findLevel(root->left,key,d+1);
	}	
}

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
	
	cout<<findLevel(root,12);
}
