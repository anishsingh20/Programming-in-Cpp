#include<iostream>


/*PROGRAM TO FIND MAXIMUM ELEMENT IN A BINARY TREE-
1) Recursive implementation-find max in left subtree, find max in right subtree, compare them with the root_node val and return the max amongst them
2) Non-recursive -using level order traversal 
*/
using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



//recursive implementation
int FindMax(struct BinaryTreeNode *root)
{
	int right,left,root_val,max = INT_MIN;

	if(root!=NULL)
	{
		root_val = root->data;
		left  = FindMax(root->left);
		right = FindMax(root->right);
		
		if(left < right)
		{
			max = right;
			
		}
		else{
			max = left;
		}
		
		if(max < root_val)
		{
			max = root_val;
		}
	}
	
	return max;	
}

int FindMaxUsingLevelOrder(struct BinaryTreeNode *root)
{
	
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
	r4->data = 10;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	cout<<FindMax(root);
	
	return 0;
}
