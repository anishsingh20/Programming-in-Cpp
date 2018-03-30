#include<iostream>

using namespace std;

/*Program to do Single right right rotation for converting an unbalaned AVL tree to a balanced AVL Tree when SOME OPERATION such as
INSERTION OR DELETION happens.
*/


struct AVLnode {
	
	int data,height;
	struct AVLnode *left,*right;	
};

int height(AVLnode *root)
{
	if(!root)
		return -1;
		
	else
		return max(height(root->left),height(root->right)) + 1;
}

AVLnode *SingleRightRotation(AVLnode *X)
{
	//we have to make the right child of X as root say(W is the right child of X) and move X to left of W
	//then the left child of W should be made the right child of X
	//then make X as left child of W
	AVLnode *W = X->right;
	X->right = W->left;
	W->left  = X;
	
	X->height = max(height(X->left),height(X->right)) + 1;
	W->height  = max(height(W->right), X->height) + 1;
	
	return W;//new root
	
}
