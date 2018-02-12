#include<iostream>
#include<queue>

using namespace std;

//Program to find diameter(width) of a Binary Tree- It is the number of nodes in the longest path between 2 leaves of the tree 

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


int heightTree(struct BinaryTreeNode *root)
{
	if(!root) return 0;
	
	return 1 + max( heightTree(root->left),heightTree(root->right));
}

//Recursive Implementation 


//Method-1
int Diameter(struct BinaryTreeNode *root)
{
	if(!root) return 0;
	
	int  hleft = heightTree(root->left);
	int hright = heightTree(root->right);
	
	int dleft = Diameter(root->left);
	int dright = Diameter(root->right);
	
	return max(hleft + 1 + hright , max(dleft,dright) ); 
	
}

//Method-2

int DiameterTree(struct BinaryTreeNode *root,int *ptr)
{
	if(!root) return 0;
	
	
	
	int left = DiameterTree(root->left,ptr);
	int right = DiameterTree(root->right,ptr);
	
	if( left + right > *ptr)
	{
		*ptr = left+right;
	}
	return max(left,right) + 1;
	
	
	
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
	struct BinaryTreeNode *root1=NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);	
	cout<<Diameter(root1)<<endl;
	

	
	return 0;
}
