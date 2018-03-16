#include<iostream>
#include<queue>

/*PROGRAM TO CONVERT A BINARY TREE to THREADED BINARY TREE

We simply have to link the right NULL pointers to their inorder successors and make the tree threaded. Logic is to use a queue to store the inorder traversal nodes.
Then again do inorder traversal pop the node and check if its right is NULL, then simply connect its right pointer to the front of queue which has its inorder successor.

*/
struct Node {
	
	int data;
	Node *left,*right;
	Node *leftThread;
};


Node *newNode(int data){
	Node *temp = new Node;
	
	temp->data = data;
	temp->right=temp->left=NULL;
	temp->leftThread=NULL;
	
	return temp;
}


Node *LeftMost(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	LeftMost(root->left);
}

