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
		cout<<root->data<<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
	
	
}

void InOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		InOrder(root->left);
		cout<<root->data<<" ";
		InOrder(root->right);
	}	
}

void PostOrder(struct BinaryTreeNode *root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<" ";
	}
	
}
     
     
int main()
{
	
	//generating a full binary tree -  n(no of nodes) = 2^(h+1) -1 , h = height of tree
	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();
	struct BinaryTreeNode *r5 = new BinaryTreeNode();
	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 5;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	r5->left  = r6->left  = NULL;
	r5->right  = r6->right  = NULL;	
	
	
	cout<<"Pre order traversal outputs-"<<endl;
	PreOrder(root);
	
	cout<<endl;
	
	cout<<"In order traversal outputs-"<<endl;
	InOrder(root);
	
	cout<<endl;
	
	cout<<"Post order traversal outputs-"<<endl;
	PostOrder(root);

	
	return 0;
}


