#include<iostream>

using namespace std;

/* FInding Kth largest element in a BST using MORRIS TRAVERAL to do reverse inorder traversal which uses constant extra memory of O(1).
Reverse inorder traversal implemented using Stack or Recursion both consumes extra memory of order O(n). Hence to improve the efficieny we do traversal
faster we use Morris traversal to do reverse inorder traversal which is based on THREAED TREES to do faster inorder traversal.

We know that reverse inorder trversal for a BST will result in a sorted descending order list.

*/
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
	if(!root) return NULL;
	
	BSTnode *succ;
	
	if(root->data == key)
	{
		//successor is the minimum element in right subtree
		if(root->right)
			return FindMin(root->right);
			
	}
	
	//first search for the key
	else
	{
		while(root)
		{
		//search in left subtree
			if(root->data > key)
			{
				succ = root;
				
				root = root->left;
				
			}
			
			//otherwise search in the right subtree
			else
				root = root->right;
		
		}
	
	}
	
	return succ;
	
	
}

BSTnode *KthLargestUsingMorrisTraversal(BSTnode *root,int k)
{

	
	BSTnode *curr  = root;
	BSTnode *Klargest= NULL;
	int count = 0;
	
	while(curr!=NULL)
	{
		//Case-1 if curr has no right child-them simply increment count and check for largest and move to its left child
		if(curr->right==NULL)
		{
			
			if(++count==k)
				Klargest  = curr;
			
			
			curr = curr->left;
				
		}
		
		
		//Case-2 here we first find the inorder successor of current node which is the left most in right subtree or minimum
		//in right subtree of current
		else
		{
			//find inorder successor of current node
			BSTnode *succ  = curr->right;
			
			while(succ->left != NULL && succ->left != curr)
				succ=succ->left;

			
	
			
			if(succ->left==NULL)
			{
				//set left child of successor to the current node
				succ->left = curr;
				
				//move current to its right
				curr = curr->right;
			}
			
			//case when we already have a threaded link between current node and its successor's left pointer 
			else
			{
				
				succ->left = NULL;
				
				
				
			
				if(++count==k)
					Klargest = curr;
					
				//move current to its left child
				curr = curr->left;
			}
			
		}
	}
	
	return Klargest;
}
//TIME COMPLEXITY = O(n) and SPACE COMPLEXITY = O(1)


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
	
	
	
	
	cout<<KthLargestUsingMorrisTraversal(root,2)->data;	
		
}
