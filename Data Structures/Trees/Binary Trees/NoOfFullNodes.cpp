#include<iostream>
#include<queue>

//Program to find number of FULL NODES in a BINARY TREE- Full nodes are those which have both left and right children

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

//1) RECURSIVE APPROACH-similar to finding number of leaf nodes

int FullNodesRec(struct BinaryTreeNode *root)
{
	
	int ll,lr;
	if(!root) return 0;
	
	
	else{
		
		//first recur to the left subtree and count full nodes
		ll = FullNodesRec(root->left);
		
		if(root->left && root->right)
		{
			ll++; //increment 
			lr++;
		}
		//go to the right subtree and find Full nodes
		lr = FullNodesRec(root->right);
	}
	
	return ll+lr;


	
	
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
	
	cout<<FullNodesRec(root);
	
	return 0;
}


