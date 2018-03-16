#include<iostream>

using namespace std;

/*PROGRAM TO CONVERT A BINARY TREE TO A PRE-DECESSOR THREADED BINARY TREE.

A predecessor threaded binary tree is a type of threaded tree in which the left NULL pointers point to their inorder predecessors.
This type of threaded tree is used in reverse inorder traversal and postorder traversal too.

*/

struct Node {
	
	int data;
	Node *left,*right;
	bool isThreaded;
};


Node *newNode(int data){
	Node *temp = new Node;
	
	temp->data = data;
	temp->right=temp->left=NULL;
	
	return temp;
}

//method to conver a binary tree to predecessor threaded tree-using the fact that we link from inorder successors to the current node

Node *ConvertPredecessorThreaded(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
	
	//now finding the inorder successor of current root-left most in right subtree, or right child itself	
	if(root->right!=NULL)
	{
		Node *r = ConvertPredecessorThreaded(root->right);
		
		r->left = root;//making the left link of inorder successor of current point to current node i.e creating a predecessor thread
		r->isThreaded = true;
	}
	
	//if left is null return root
	if(root->left==NULL)
		return root;
		
	return ConvertPredecessorThreaded(root->left);
}


int main()
{
	
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(7);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	
	ConvertPredecessorThreaded(root);
	
	
	
	
}
