#include<iostream>

using namespace std;

/*PROGRAM TO DO INORDER TRAVERSAL OF A SINGLE THREADED BINARY TREE

A single threader binary tree is one in which right NULL pointers of a node point to the inorder successors of that particular node
whose right child is NULL.

*/


struct Node {
	
	int data;
	Node *left,*right;
	Node *rightThread;//bool var to indicate that a node has a right pointer point to its inorder succssor
};




Node *rightMost(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	rightMost(root->right);
}

//function to find left most node in a tree
Node *leftMost(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	leftMost(root->left);
}



Node *newNode(int data){
	Node *temp = new Node;
	
	temp->data = data;
	temp->right=temp->left=NULL;
	temp->rightThread=NULL;
	
	return temp;
}





void InorderThreadedTree(Node *root)
{
	
	Node *curr = leftMost(root);
	
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		
		//if curr has a right thread pointing to its inorder successor-then go to its inorder successor
		if(curr->rightThread)
		{
			curr = curr->rightThread;
		}
		
		//if curr right child is not null-then go to its leftmost node in right subtree
		else
		{
			curr = leftMost(curr->right);
		}
	}
	
}


int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	
	root->right= newNode(3);
	
	
	//the right thread points to the node's inorder successor
	root->left->left = newNode(4);
	root->left->left->rightThread = root->left;
	
	root->left->right = newNode(5);
	root->left->right->rightThread = root;
	
	root->right->left = newNode(6);
	root->right->left->rightThread = root->right;
	
	root->right->right = newNode(7);
	
	
	root->right->right->left = newNode(8);
	root->right->right->left->rightThread = root->right->right;
	
	root->right->right->right = newNode(9);
	
		
	InorderThreadedTree(root);
	
}
