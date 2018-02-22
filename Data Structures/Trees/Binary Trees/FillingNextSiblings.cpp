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


//function to find the next sibling of node
                                          

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


//Level order traversal-need to maintain a marker for completion of current level by pusing NULL in queue
int FillNextSiblingLevelOrder(BinaryTreeNode* root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	
	if(root==NULL) return 0;
	
	q.push(root);
	q.push(NULL); //marker for completion for level 0 of tree by pushing NULL
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp==NULL)
		{
			//another marker for completion of current level
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		
		else
		{
			//making the connection
			temp->nextSibling = q.front();
			
			if(temp->left) q.push(temp->left);
			
			if(temp->right) q.push(temp->right);
		}
	}
	return 1;
}



//Recursive function to find the next sibling of node in a tree
BinaryTreeNode *findNextSiblingNode(BinaryTreeNode *root,int data)
{
	if(root==NULL) return NULL;
	
	//if data found at current root, then return root's next sibling
	if(root->data==data)
	{
		return root->nextSibling;
	}
	
	//otherwise simply traverse to left and right subtrees to find next sibling
	else
	{
		BinaryTreeNode *leftsibling = findNextSiblingNode(root->left,data);
		if(leftsibling) return leftsibling;
		
		else return findNextSiblingNode(root->right,data);
	}
}



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



	cout<<findNextSiblingNode(root,r4->data)->data;
	
	return 0;
	
	
	
}

