#include<iostream>
#include<queue>

using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};


struct BinaryTreeNode *DeepestLeftLeaf(struct BinaryTreeNode *root)
{
	//base condition
	if(root==NULL) return NULL;
	
	//if a leaf node
	if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	
	//otherwise simply recurse to the left subtree
	return DeepestLeftLeaf(root->left);
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
	Insert(&root1,8);
	
	
	cout<<DeepestLeftLeaf(root1)->data;
	return 0;
}
