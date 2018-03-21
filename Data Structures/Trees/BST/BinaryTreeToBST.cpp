#include<iostream>


using namespace std;


/* Program to convert a Binary tree to a BST-
Algorithm-
1)While doing inorder traversal of the tree copy items in an temporary container-say array,set or vector.
2)Now sort the container.
3)Now again do inorder traversal of the tree and copy each item one by one from sorted container to the tree.

We do inorder traversal becasue we know INORDER TRAVERSAL OF A BST GIVES US A SORTED LIST

The final resulting tree would be a BST. 


*/

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


int main()
{
	BSTnode *root=newNode(7);

	root->left = newNode(5);
	root->right = newNode(9);
	root->right->left = newNode(8);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(11);
	
	
	
	
}
