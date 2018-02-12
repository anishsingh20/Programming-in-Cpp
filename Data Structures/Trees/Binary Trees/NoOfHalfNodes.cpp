#include<iostream>
#include<queue>


//Program to find number of half nodes in a BinaryTRee-half nodes are nodes having only one subchild - either left or right
using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//Recursive appraoch
int HalfRec(struct BinaryTreeNode *root)
{
	if(!root) return 0;
	
	int hl=0,hr=0;
	
	hl = HalfRec(root->left);
	if( (root->left==NULL && root->right) || ( root->right==NULL && root->left ) )
	{
		hl++;
		hr++;
	}
	hr = HalfRec(root->right);
	
	return hl+hr;
	
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
	struct BinaryTreeNode *root = NULL;
	
	Insert(&root,1);
	Insert(&root,2);
	Insert(&root,3);
	Insert(&root,4);
	Insert(&root,5);
	Insert(&root,6);
	Insert(&root,7);
	
	cout<<HalfRec(root);
	
	return 0;
}
