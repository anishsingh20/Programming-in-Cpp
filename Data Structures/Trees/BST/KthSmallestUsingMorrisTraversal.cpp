#include<iostream>

//Program to find Kth smallest element in a BST using morris traversal to do efficient and faster Inorder traversal which consumes O(1) extra space.

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


BSTnode *KthSmallestUsingMorrisTraversal(BSTnode *root,int k)
{
	
	BSTnode *curr=root;
	int count = 0;
	BSTnode *ksmall;
	BSTnode *pre;
	
	while(curr)
	{
		//case-1 if current node has no left child
		if(curr->left==NULL)
		{
			if(++count==k)
				ksmall  = curr;
			
			curr = curr->right;
				
		}
		
		else
		{
			//find the inorder predecessor of current node
			//inorder predecessor is the right most in left subtree i.e
			//maximum element in left subtree or left child itself
			pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
			{
				pre = pre->right;	
			}	
			
			//create threads
			if(pre->right==NULL)
			{
				pre->right = curr;
				
				curr = curr->left;
				
			}
			
			//if the thread between current and its predecessor already exists.
			else
			{
				pre->right = NULL;
				
				if(++count==k)
					ksmall  = curr;
					
				curr = curr->right;	
					
			}
		}
	}
	
	return ksmall;
	
	
}//TIME COMPLEXITY = O(n) and Space complexity = O(1)


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
	
	cout<<KthSmallestUsingMorrisTraversal(root,1)->data;
	
	
	return 0;
}
