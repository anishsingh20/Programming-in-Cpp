#include<iostream>


using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};


//function to traverse a tree level wise in any order form left to right or right to left- Breadth first traversal
void printTree(struct BinaryTreeNode *root,int level, bool ltr)
{
	//base condition
	if(root==NULL) return;
	
	
	if(level==0) 
	{
		cout<<root->data<<" ";
	}
		
	else if(level  > 0 )
	{
		//if order is to traverse from left to right
		if(ltr)
		{
			printTree(root->left,level-1,ltr);
			printTree(root->right,level-1,ltr);	
		}
		
		//when order is to print from right to left
		else
		{
			printTree(root->right,level-1,ltr);
			printTree(root->left,level-1,ltr);
		}
	}
}

