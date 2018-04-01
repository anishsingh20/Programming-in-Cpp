#include<iostream>



//program to check is a BST is AVL tree or not
//we simply have to check for the balance condition recursively while traversing the tree

using namespace std;

struct BSTnode {
	
	int data,height;
	struct BSTnode *left,*right;	
};



int Height(AVLnode *root)
{
	if(!root)
		return -1;
		
	else
		return max(Height(root->left),Height(root->right)) + 1;
}


int isBSTAVL(BSTnode *root)
{
	if(!root)
		return 1;
	
	if(Height(root->right)-Height(root->left)==2)
		return 0;
		
	if(root->left)
		return isBSTAVL(root->left);
		
	if(root->right)
		return isBSTAVL(root->right);
		
		
	return 1;
}


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
