#include<iostream>

using namespace std;

//program to delete a Binary tree-we have to take care that we first need to delete the child nodes, before deleting the parent nodes
//this can easily be dine using POSTORDER traversal - as in postorder we first traverse to the left and the right subtrees then visit the parent root


void DeleteTree(struct BinaryTreeNode *root)
{
	if(root==NULL) return;
	
	if(root)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		
		delete(root);
	}
}



int main()
{
	
}

