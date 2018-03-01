#include<iostream>
#include<queue>

using namespace std;


//PROGRAM TO DO BOUNDARY TRAVERSAL-LEFT, RIGHT and LEAF nodes only
struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



void leftBoundary(BinaryTreeNode *root)
{
	
	cout<<root->data<<" ";
	if(root->left)
		leftBoundary(root->left);	
}


void rightBoundary(BinaryTreeNode *root)
{

	if(root->right)
		leftBoundary(root->right);
	cout<<root->data<<" ";
}

void visitleaf(BinaryTreeNode *root)
{
	
	
}


void BoundaryTraversal(BinaryTreeNode *root)
{
	cout<<root->data<<" ";
	
	leftBoundary(root->left);
	
	rightBoundary(root->right);
	
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
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
//	Insert(&root1,8);
//	Insert(&root1,9);
	
	BoundaryTraversal(root1);
	
}


