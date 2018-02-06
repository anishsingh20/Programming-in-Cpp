#include<iostream>

//IMPLEMENTATION OF A BINARY TREE- a tree which can have atmost i.e <= 2 child nodes

using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

     
/*TRAVERSING A BT-
1)PREORDER - a) visit the root node b)traverse the left subtree in preorder c) visit the right subtree in preorder

2)INORDER - a) Traverse to the left subtree in Inorder  b) visit the root node c) traverse to the right subtree in inorder

3)POSTORDER-a) Traverse to the left subtree in postorder  b) traverse to the right subtree in postorder c) visit the root node 

4) Level order traversal - BFS -breadth first search
*/   
     
     
//RECURSIVE IMPLEMENTATION-

void PreOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		cout<<root->data<<"->";
		PreOrder(root->left);
		PreORder(root->right);
	}
	
	
}

void InOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		InOrder(root->left);
		cout<<root->data<<"->";
		InOrder(root->right);
	}	
}

void PostOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<"->";
	}
	
}
     
     
int main()
{
	
	return 0;
}


