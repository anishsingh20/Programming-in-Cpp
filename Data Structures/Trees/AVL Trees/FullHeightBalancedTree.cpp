#include<iostream>

using namespace std;

#define n 100 

//Program to generate a full height balanced binary tree where balance factor is atmost 0 for all nodes.
//balance factor(k) = height(left subtree)  - height(right subtree)


struct Node {
	
	int data;
	struct Node *left,*right;
};



//nodes will be from 1 to 2^(h+1) - 1. As in a full binary tree max number of nodes can be 2^(h+1) - 1, if we assume height of a tree with
//single node = 0  

//the function takes parameter as height of tree- we will traverse in inorder so as to satisfy the BST property
Node *FullBalancedBST(int h)
{
	
	static int count=1;
	Node *temp = new Node();
	
	if(h==-1)
		return NULL;
	
	//recursively fill the left subtree first
	temp->left = FullBalancedBST(h-1);
	
	temp->data = count++;
	
	//then go to the right subtree
	temp->right = FullBalancedBST(h-1);
	
	return temp;
	
}//time complexity = O(n) and Space complexity = O(logn) as stack space consumed is proportional to the height of a recursion tree.
//and in this case it is a FUll binary search tree where height h = logn

void Inorder(Node *root)
{
	if(!root)
		return;
		
	Inorder(root->left);
	
	cout<<root->data<<" ";
	
	Inorder(root->right);
}

int main()
{
	
	struct Node *root = FullBalancedBST(3);
	
	Inorder(root);
	
}
