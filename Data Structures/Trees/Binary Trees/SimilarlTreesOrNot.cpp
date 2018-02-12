#include<iostream>
#include<queue>

using namespace std;

//algorithm to find if 2 binary trees are structurally similar or not

//recursive approach

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


bool similarTrees(struct BinaryTreeNode *rootA, struct BinaryTreeNode *rootB)
{
	

	//if both empty
	if(rootA==NULL && rootB==NULL)  return true;
	
	//if only one tree empty
	if(rootA==NULL || rootB==NULL) return false;
	
	//otherwise compare data and recur to left subtrees and right subtrees of both trees and check 
//	return (rootA->data==rootB->data && similarTrees(rootA->left,rootB->left) && similarTrees(rootA->right,rootB->right));	
	if(rootA->data == rootB->data)
	{
		bool left,right;
		//recur to left subtree and check
		left = similarTrees(rootA->left,rootB->left);
		
		//recur to right subtree and check
		right = similarTrees(rootA->right,rootB->right);
		
		if(left&&right)
		{
			return true;
		}
		
		
		
	}
	
       return false;		
		
		 
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
	struct BinaryTreeNode *root1=NULL,*root2=NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	
	
	Insert(&root2,1);
	Insert(&root2,2);
	Insert(&root2,3);
	Insert(&root2,4);
	Insert(&root2,5);		
	
	
	if(similarTrees(root1,root2)) cout<<"Similar trees"<<endl;
	else cout<<"Not similar"<<endl;
		
	
}
