#include<iostream>


using namespace std;

//Program to find parent of a node in BST.


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



//function to find parent of a node
BSTnode* findParent(BSTnode *root,int n1)
{
	if(!root) return NULL;
	
	if(root)
	{
		if( root->left && root->left->data == n1 || root->right && root->right->data==n1 )
		{
			return root;
		}
	
	//search for the node with key n1 if left or right subtree
		if(root->data < n1)
			return findParent(root->right,n1);
		
		if(root->data > n1)
			return findParent(root->left,n1);
	}
	

	
} //TIME COMPLEXITY = O(n), Space complexity = O(n) for recursion call stack


//Iterative method to find parent node
BSTnode *findParentIterative(BSTnode *root,int value)
{
	if(!root) return NULL;
	
	while(root)
	{
		
		//first searching for the node in left of right subtree
		
		if(root->data < value)
		{
			if(root->left->data == value || root->right->data==value)
			{
				return root;
			}
			
			//otherwise go to the right subtree only
			root = root->right;
		}
		
		if(root->data > value)
		{
			//if parent is found
			if(root->left->data == value || root->right->data==value)
			{
				return root;
			}
			
			//otherwise go to the left subtree only
			root = root->left;
		}
	}
	
}//SPACE COMPLEXITY = O(1)

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


int main()
{
	
	
	BSTnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	
	cout<<findParent(root,2)->data;
	
	cout<<endl;
	
	cout<<findParentIterative(root,3)->data;
	
	
}
