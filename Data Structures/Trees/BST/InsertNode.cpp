#include<iostream>


using namespace std;

//function to insert data in a binary tree

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


//iterative method to insert a node-SPACE COMPLEXITY = O(1) is the only advantage of iterative operations
BSTnode*  insertIterative(BSTnode *root,int value)
{
	BSTnode *new_node  = new BSTnode();
	
	new_node->data = value;
	
	if(root==NULL)
	{
		root = new_node;
		return root;
		
		
	}
	
	while(root)
	{
		if(root->data < value)
		{
			//if right is NULL insert it
			if(root->right==NULL)
			{
					root->right =  new_node;
					break;
				
			}
			
			//otherwise simply traverse to right and check for right NULL
			root= root->right;
			
			
		}
		
		if(root->data > value)
		{
			//if left is NULL insert it
			if(root->left==NULL)
			{
				root->left = new_node;
				break;
				
			}
				
			//otherwise simply traverse to the left child
				
			root = root->left;
		}
		
		
	}
	
	return root;
	
}

void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	cout<<root->data<<" ";
	
	Inorder(root->right);
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
	
	BSTnode *root = newNode(7);
	
//	insert(root,7);
//	insert(root,3);
//	insert(root,10);
//	
//	insert(root,12);
//	insert(root,2);
//	insert(root,1);
//	
	
	
	insertIterative(root,3);
	insertIterative(root,10);
	
	insertIterative(root,12);
	insertIterative(root,2);
	insertIterative(root,5);
	
	
	Inorder(root);
	
	
	return 0;
	
}
