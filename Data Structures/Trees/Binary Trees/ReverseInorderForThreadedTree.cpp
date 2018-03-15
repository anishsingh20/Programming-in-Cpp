#include<iostream>

using namespace std;


//Reverse Inorder traversal for a threaded binary tree


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


Node *rightMost(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	rightMost(root->right);
}


void ReverseInorder(Node *root)
{
	if(!root) return;
	
	//finding the right most node in tree-as it is the first one to be visited
	Node *curr = rightMost(root);
	
	while(curr != NULL)
	{
		cout<<curr->data<<" ";
		
		//if the left thread exists i.e curr has its left pointing to its inorder predecessor
		if(curr->leftThread)
			curr = curr->leftThread;
		
		//otherwise simply find the righrtmost in the left subtree	
		else
		{
			//move to the predecessor of current
			//predecessor is the right most child of left subtree
			curr  = rightMost(curr->left);
		}
		
		
	}
	
	
	
}


int main()
{
	
	Node *root = newNode(1);
	root->left = newNode(2);
	
	root->right= newNode(3);
	root->right->leftThread  = root;
	
	
	
	
	//the right thread points to the node's inorder successor
	root->left->left = newNode(4);
	
	
	root->left->right = newNode(5);
	root->left->right->leftThread = root->left;
	
	
	
		
	ReverseInorder(root);
	
}
