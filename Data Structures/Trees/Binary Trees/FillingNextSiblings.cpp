#include<iostream>
#include<queue>

/*ALgorithm to Filling the nextiblings pointer of a node in a binary tree
1)Approach-1 : Level order traversal appraoch, with keeping a merker for completion of current level by pusing NULL in queue, whenever front og
queue is NULL.

2)Recursive approach
*/
using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *nextSibling;
};



//recursive implementation
void FillNextSiblings(BinaryTreeNode *root)
{
	//base condition
	if(root==NULL) return ;
	
	if(root->left)
		root->left->nextSibling = root->right;
		
	//imp
	if(root->right)
	{
		root->right->nextSibling = (root->nextSibling)  ? (root->nextSibling->left) : NULL;	
	}
	
	//simply recur down to left and right subtree and making connections
	FillNextSiblings(root->left);
	FillNextSiblings(root->right);
}
//TIME COMPLEXITY = O(n)


int main()
{
	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();
	struct BinaryTreeNode *r5 = new BinaryTreeNode();
	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 5;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	r5->left  = r6->left  = NULL;
	r5->right  = r6->right  = NULL;	
	
	//filling nextSibling pointers
	FillNextSiblings(root);
	
	cout<<r1->nextSibling->data;
	
	return 0;
	
	
	
}

