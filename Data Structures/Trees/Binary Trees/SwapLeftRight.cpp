#include<iostream>
#include<queue>

using namespace std;


//Program to swap the left and right nodes in a tree using level order traversal

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



//level order method
void SwapLeftRight(BinaryTreeNode *root)
{
	if(!root) return;
	
	queue<BinaryTreeNode *> q;
	
	BinaryTreeNode *temp;
	
	q.push(root);
//	q.push(NULL); //marker for completion of level0
	
	while(!q.empty())
	{
		temp = q.front();
		
		cout<<temp->data<<" ";
		q.pop();
		
		//first simply swap the left and right children of current root-temp
		swap(temp->left, temp->right);
	
			if(temp->left) q.push(temp->left);
			if(temp->right)	q.push(temp->right);
			
		
		
		
		
		
	}
}



void Insert( struct BinaryTreeNode **root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	new_node->data = data;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(*root==NULL)
	{
		*root = new_node;
		return;
	}
	
	q.push(*root);
	
	while(!q.empty())
	{
		temp  = q.front();
		q.pop();
		
		if(temp->left==NULL)
		{
			temp->left = new_node;
			return;
			
			
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
}


int main()
{
	struct BinaryTreeNode *root1 = NULL;
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	
	SwapLeftRight(root1);	
	
return 0;
}

