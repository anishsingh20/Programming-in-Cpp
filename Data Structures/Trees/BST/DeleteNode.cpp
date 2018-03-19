#include<iostream>

using namespace std;

//PROGRAM TO DELETE A NODE IN A BST-complicated



struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
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



void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	cout<<root->data<<" ";
	
	Inorder(root->right);
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
