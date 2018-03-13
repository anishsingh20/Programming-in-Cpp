#include<iostream>
#include<queue>

using namespace std;

/*Program to find inorder successor of a node in a binary tree
Inorder sucessor-: inorder successor of a node n is the next node which is to be traversed after n in inorder fashion.
Inorder successor of last node in inorder traverasl is NULL, i.e the right most node in a tree in right subtree. 
*/



struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//function to find the lest most node in a tree
BinaryTreeNode* leftMost(BinaryTreeNode *root)
{
	
	//recursive solutuion
//	if(!root) return NULL;
//	
//	//when left most leaf is found
//	if(root->left==NULL && root->right==NULL)
//		return root;
//	
//	//otherwise simply recur to the left subtree of each node
//	leftMost(root->left);

//iterative solution
	while(root!=NULL && root->left!=NULL)
	{
		root = root->left;
	}
	
	return root;
	
		
	
}


BinaryTreeNode *rightMost(BinaryTreeNode *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	rightMost(root->right);
}



BinaryTreeNode *RecursiveInorderSuccessor(BinaryTreeNode *root,BinaryTreeNode *x)
{
	BinaryTreeNode *temp;
	if(!root) return NULL;
	
	if(root->data == x || (temp == RecursiveInorderSuccessor(root->left,x)) || 
		(temp == RecursiveInorderSuccessor(root->right,x)))
		{
			if(temp)
			{
				if(root->left==temp)
				{
					//root is the inorder successor of temp
					cout<<root->data<<endl;
					return NULL;
				}	
			}
			
			return root;
		}
		
		
		return NULL;	
		
		
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
	
	
	
//	cout<<leftMost(root1)->data;
//	cout<<endl;
//	cout<<rightMost(root1)->data;
	

	
	
}
