#include<iostream>
#include<queue>


//Program to find number of half nodes in a BinaryTRee-half nodes are nodes having only one subchild - either left or right
using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//Recursive appraoch
int HalfRec(struct BinaryTreeNode *root)
{
	static int count = 0 ;
	if(!root) return 0;
	
	else
	{
		if(!root->left && root->right || !root->right && root->left)
		{
			count++; //count of half nodes
		}
		
		//recur down to left and right subtrees and check for the above condition
		HalfRec(root->left);
		HalfRec(root->right);
		
	
	}
	
	return count;
	
	
	
	
	
		
//Approach 2 -The idea is to traverse the tree in postorder. If current node is half, we increment result by 1 and add returned values of left and right subtrees.
//if (root == NULL)
//       return 0;
// 
//    int res = 0;
//    if  ((root->left == NULL && root->right != NULL) ||
//         (root->left != NULL && root->right == NULL))
//       res++;
// 
//    res += (gethalfCount(root->left) + gethalfCount(root->right));
//    return res;
//	
//	
}



int HalfNodesUsingLevelOrder(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	int count = 0;
	
	if(!root) return 0;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if( !temp->left && temp->right || !temp->right && temp->left)
		{
			count++;
		}
		
		if(temp->left) q.push(temp->left);
		
		if(temp->right) q.push(temp->right);
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


//BinaryTreeNode *InsertBST(struct BinaryTreeNode *root , int data)
//{
//	BinaryTreeNode *new_node = new BinaryTreeNode();
//	new_node->data = data;
//	new_node->left = new_node->right = NULL;
//	
//	if(root==NULL) 
//	{
//		root = new_node;
//		return new_node;	
//	}
//	
//	if(root)
//	{
//	
//
//		if(root->data < data)
//		{
//			root->right = InsertBST(root->right,data);
//		}
//		else root->left = InsertBST(root->left,data);
//	}
//	
//	
//	
//}
//

int main()
{
	struct BinaryTreeNode *root = NULL;
	
	Insert(&root,1);
	Insert(&root,2);
	Insert(&root,3);
	Insert(&root,4);
	
	
	
	
	
	
	cout<<HalfRec(root);
	cout<<endl;
	cout<<HalfNodesUsingLevelOrder(root);
	
	return 0;
}
