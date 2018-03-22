#include<iostream>


using namespace std;


//Program to find kth smallest element from a BST- The idea is to do inorder traverasl of BST as we know
//inorder traversal outputs a sorted list and while traversing keep trach of number of elements visited


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


void KthSmallestNode(BSTnode *root,int k)
{
	
	static int count=0; 
	
	
	if(root && count <= k)
	{
		//left most node is the smallest in tree
		KthSmallestNode(root->left,k);
		//keeping count of visited items in inorder traversal
	
		if( ++count==k )
		{
			cout<<root->data<<endl;
			return;
			
		}
	

		KthSmallestNode(root->right,k);
		
	}
		
	
}

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
	insert(root,12);
	insert(root,20);
	

	
	KthSmallestNode(root,2);
	
		
}
