#include<iostream>
#include<queue>

//finding number of leaf nodes in a Binary tree- 
//Leaf nodes are those whose left and right pointers store NULL or point to NULL

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


int LeafNodesUsingLevelOrder(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode*>q;
	int count = 0;
	BinaryTreeNode *temp;
	
	if(!root) return 0;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		//leaf node
		if(temp->right==NULL && temp->left==NULL)
		{
			count++;
		}
		
		else {
			if(temp->left) q.push(temp->left);
			
			if(temp->right) q.push(temp->right);
		}
	}
	
	return count;
	
	
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
		
	cout<<LeafNodesUsingLevelOrder(root);
	
}


