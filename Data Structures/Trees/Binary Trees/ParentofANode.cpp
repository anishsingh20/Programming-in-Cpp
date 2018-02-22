#include<iostream>
#include<queue>
#include<cstdlib>

//program to find the parent root of a given node in a binary tree
using namespace std;
struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



struct BinaryTreeNode *findParentNode(struct BinaryTreeNode *root,int data)
{
	
	//checking if root is NULL
	if(root==NULL) 
		return NULL;
		
		
	//checking if root has left or right subtree	
//	if(root->left==NULL && root->right==NULL)
//		return NULL;
		

	if(root)
	
	{
	
		//checking for root's left and right subtree to avoid errors
		if( root->left && root->left->data == data || root->right &&  root->right->data==data)
		{
			return root;
		}
		
		//else recur down to the left and right subtrees
		
			 BinaryTreeNode *left = findParentNode(root->left,data);
			 if(left) return left;
			 
			 else return  findParentNode(root->right,data);
		
	}
	
	
}


//level order method to find the parent of a node
bool FindParentUsingLevelOrder(struct BinaryTreeNode *root,int data)
{
	if(!root)
		return false;
		
	queue<BinaryTreeNode *> q;
	BinaryTreeNode *temp;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		
		if(temp->left->data==data || temp->right->data==data)
		{
			cout<<temp->data;
			return true;
			
		}
		
		if(temp->left)	q.push(temp->left);
		
		if(temp->right)	q.push(temp->right);
	}
	
	return false;
}



//finding ancestors of a node
bool findAncestors(struct BinaryTreeNode *root,int data)
{
	if(root)
	{
	

		if(root->data == data)
		{
			return true;
		}
		
		//else recur down to the left and right subtrees
		else 
		{
			bool left = findAncestors(root->left,data);
			bool right = findAncestors(root->right,data);
			
			if(left || right) 
			{
				cout<<root->data<<" ";
				return true;
			}
			
			
			
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
	
	struct BinaryTreeNode *root1=NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	Insert(&root1,9);
	Insert(&root1,10);
	Insert(&root1,11);
	
	cout<<findParentNode(root1,11)->data;
	cout<<endl;
	
	FindParentUsingLevelOrder(root1,11);
	cout<<endl;
	findAncestors(root1,11);

return 0;	
}
