#include<iostream>
/*Program to do Single Left left rotation for converting an unbalaned AVL tree to a balanced AVL Tree when SOME OPERATION such as
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

AVLnode *SingleleftRotation(AVLnode *X)
{
	//we have to make the left child of X as root say(W is the left child of X) and move X as right of W
	//then the right child of W should be made the left child of X
	//then make X as right child of W
	AVLnode *W = X->left;
	X->left = W->right;
	W->right  = X;
	
	X->height = max(height(X->left),height(X->right)) + 1;
	W->height  = max(height(W->left), X->height) + 1;
	
	return W;//new root
	
}


