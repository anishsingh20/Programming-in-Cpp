#include<iostream>

using namespace std;

/*PROGRAM TO CHECK IF A GIVEN BINARY TREE IS BST OR NOT-
	
Idea is to do something similar to inorder traversal-
Methdod-1
1)We check if the current node's key is larger than it's inorder predecessor i.e the maximum in left subtree.
2)We check if the current node's key is smaller than its inorder successor- i.e minimum in right subtree.
3)We check the above 2 conditions recursively for the left and right subtrees and true , then it is a BST
	
*/


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


int FindMax(BSTnode *root)
{
	
}

int FindMin(BSTnode *root)
{
	
}

int isBST(BSTnode *root)
{
	if(!root)
		return 1;
		
	//if current node's data is larger than its inorder predecessor- i.e maximum(right most) in left subtree.
	if(root->left && root->data > FindMax(root->left))
		return 1;
	
	//if current node's data is smaller than its inorder successor- i.e minimum(left most) in right subtree.	
	if(root->right && root->data < FindMin(root->right))
		return 1;
		
	//now recursively check in left and right subtree
	if(isBST(root->left)&& isBST(root->right))
		return 1;
	
	
	//otherwise not a BST
	return 0;
		
	
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
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->right = newNode(11);
	
}
