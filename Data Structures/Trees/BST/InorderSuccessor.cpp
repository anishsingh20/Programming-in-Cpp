#include<iostream>

using namespace std;


//program to find inorder successor

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


BSTnode* FindMin(BSTnode *root)
{
	if(!root)
		return NULL;
		
	//if left most node has no left child, then it is mimimum node
	if(root->left!=NULL)
		return FindMin(root->left);
		
	return root;	
		
	
	
}

BSTnode *FindSuccessor(BSTnode *root,int key)
{
	//if right child exists,then inorder successor is the left most(MIN) node in right subtree
	
	//if key is found
	BSTnode *succ;
	if(root->data == key)
	{
		if(root->right)
		{
			return FindMin(root->right);
		}
	
		
	}
	
	
	//otherwise first search fo the key in the tree
	else
	{
		
	
		while(root)
		{
			//search in left subtree
			if(root->data > key)
			{
				//assign succ as root
				succ = root;
				root = root->left;
			}
			
			//search in right subtree
			else
			{
				root = root->right;
			}
			
		
		}
		
	}
	
	return succ;
	
}// Time Complexity: O(n) and space complexity = O(1) as constant extra memory is consumed.


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


void ReverseInorder(BSTnode *root)
{
	if(!root ) return ;
	
	ReverseInorder(root->right);
	
	cout<<root->data<<" ";
	
	ReverseInorder(root->left);
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
	
	ReverseInorder(root);
	
	cout<<endl;
	
	cout<<FindSuccessor(root,4)->data;	
	
}


