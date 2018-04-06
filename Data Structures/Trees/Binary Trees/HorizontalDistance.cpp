#include<iostream>
#include<queue>

using namespace std;

//program to find Horizontal distance of a node from root of the tree
struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};


//function to find the Horizontal distance of a node from root node
void HD(BinaryTreeNode *root,int data,int hd=0)
{
	
	if(root==NULL)
	{
		return; 
	}
	
	//if data at current root, then print hd
	if(root->data==data)
	{
		cout<<hd;
		
	}

	
	//recur to left subtree and check for the node to be found and also substract hd-1 for left subtree
	HD(root->left,data,hd-1);
	
	
	
	//recur to right subtree and check for the node to be found and also add hd+1 for right subtree
	HD(root->right,data,hd+1);
	
	
	
	
	
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
	
	HD(root1,6);
	return 0;
	
}
