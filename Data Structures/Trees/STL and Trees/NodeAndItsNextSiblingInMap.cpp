#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *nextSibling;
};


//function to fill and connect the nextSibling pointer
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

void InsertNextSibling(BinaryTreeNode *root,map<int,int>&Map)
{
	if(root==NULL) return;
	//filling the nextSiblings
	FillNextSiblings(root);	
	
	//simply inserting each node and its nextSibling in Map
	
	//inserting in In-order fashion	
	InsertNextSibling(root->left);
	
	Map[root->data]  = root->nextSibling->data;
	
	InsertNextSibling(root->right);
	
}


void TraverseMap(BinaryTreeNode *root)
{
		
}
}



int main()
{
	return 0;
}
