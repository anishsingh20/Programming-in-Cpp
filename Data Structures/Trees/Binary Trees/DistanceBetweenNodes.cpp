#include<iostream>
#include<queue>

using namespace std;

//program to find distance between 2 nodes in a Binary tree

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};



//function to find the distance from a root to a node
int dist(BinaryTreeNode *root,int n1,int d=0)
{
	
	if(root)
	{
		if(root->data==n1)
		{
			return d;
		}
		
		int l = dist(root->left,n1,d+1);
		int r = dist(root->right,n1,d+1);
		
		if(l) return l;
		else return r;		
		
		
		
	}	
	
}


//function to find distance between 2 nodes-i.e the number of edges between them, or length of path
int DistNode(BinaryTreeNode *root,int n1,int n2)
{
	int d1 = dist(root,n1);
	
	int d2 = dist(root,n2);
	
	return d1+d2;
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
	Insert(&root1,8);
	Insert(&root1,9);

	cout<<DistNode(root1,9,7);
	return 0;
}
