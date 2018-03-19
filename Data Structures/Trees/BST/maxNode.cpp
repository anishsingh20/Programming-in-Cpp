#include<iostream>


using namespace std;

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

//Recursive implementation-max node is the right most node in the BST which does not has any right child
BSTnode *maxNode(BSTnode *root)
{
	if(!root) return NULL;
	
	
	if(root->right==NULL)
		return root;
		
	else return maxNode(root->right);
}


BSTnode *insert(BSTnode *root,int data)
{
	
	
	
	
	
	//base condition-if root is NULL-allocate memory and make node
	if(root==NULL)
	{
		root = new BSTnode();
		root->data = data;
		return root;	
		
	}
	
	else
	{
		
		if(root->data >= data)
			root->left = insert(root->left,data);
		
		
		
		else
			root->right = insert(root->right,data);		
		
	}	
	
	return root;	
}

int main()
{
	
	BSTnode *root  =  newNode(7);
	
	insert(root,3);
	insert(root,10);
	
	insert(root,12);
	insert(root,2);
	insert(root,1);
	
	
	cout<<maxNode(root)->data;
	
	
	
	return 0;
	
}
