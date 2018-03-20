#include<iostream>
#include<iomanip>

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


BSTnode *FindMax(BSTnode *root)
{
	if(!root)
		return NULL;
		
	//until we don't reach right most node which has no right child we recur
	if(root->right!=NULL)
		return FindMax(root->right);
		
	return root;
	
		
}

BSTnode* FindMin(BSTnode *root)
{
	if(!root)
		return NULL;
		
	//if left most node has no left child, then it is mimimum node
	if(root->left!=NULL)
		return FindMin(root->left);
		
	return root;	
		
	
	
}

int isBST(BSTnode *root)
{
	if(!root)
		return 1;
		
	//if current node's data is larger than its inorder predecessor- i.e maximum(right most) in left subtree.
	if(root->left && root->data < FindMax(root->left)->data)
		return 0;
	
	//if current node's data is smaller than its inorder successor- i.e minimum(left most) in right subtree.	
	if(root->right && root->data > FindMin(root->right)->data)
		return 0;
		
	//now recursively check in left and right subtree
	if(! isBST(root->left) || !isBST(root->right))
		return 0;
	
	
	//otherwise not a BST
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
	
	
	
	cout<<FindMin(root)->data;
	cout<<endl;
	cout<<isBST(root);	
}
