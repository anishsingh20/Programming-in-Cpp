#include<iostream>
#include<queue>
using namespace std;


//PROGRAM TO GENERATE A MIRROT TREE- i.e exchange the left and the right child nodes 

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

//function to find the mirror of a binary tree
BinaryTreeNode* MirrorTree(struct BinaryTreeNode *root)
{
	struct BinaryTreeNode *temp;
	if(root)
	{
		
		MirrorTree(root->left);
		MirrorTree(root->right);
		
		//swapping the left and the right nodes
		temp = root->left;
		root->left = root->right;
		
		root->right = temp;	
	}
	
	return root;
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


void PreOrderRec(struct BinaryTreeNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		PreOrderRec(root->left);
		PreOrderRec(root->right);
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
	
	PreOrderRec(root1);
	
	cout<<endl;

	MirrorTree(root1);	

	PreOrderRec(root1);
	return 0;
}
