#include<iostream>
#include<cstdlib>

using namespace std;

//program to delete a Binary tree-we have to take care that we first need to delete the child nodes, before deleting the parent nodes
//this can easily be dine using POSTORDER traversal - as in postorder we first traverse to the left and the right subtrees then visit the parent root

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

void DeleteTree(struct BinaryTreeNode *root)
{
	if(root==NULL) 
	{
		
		 return;
	}
	
	if(root)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		
		free(root);
	}
}


void PreOrderRec(struct BinaryTreeNode *root)
{
	if(!root)
	{
		
		return;
	}
	
	if(root)
	{
		cout<<root->data<<" ";
		PreOrderRec(root->left);
		PreOrderRec(root->right);
	}
	
	
}



int main()
{
	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();	
	
	root->data = 10;
	r1->data = 2;
	r2->data = 15;
	r3->data =4;
	r4->data = 5;
	
	root->left = r1;
	root->right = NULL;
	
	r1->left = r2;
	r2->right = r3;
	
	r3->right = r4;
	r3->left = NULL;
	
	r4->left = r4->right = NULL;
	
	PreOrderRec(root);
	
	DeleteTree(root);

	
}

