#include<iostream>
#include<stack>

/*if we want to construct a tree from given traversals-

then any one of the postorder or pre-order traversals are enough.

Method1)
1)Using a stack
*/

struct node {
	int data;
	struct node *left,*right;
};


node *PreorderToBSTStack(node *root,int pre[])
{
	
}


void Inorder(node *root)
{
	Inorder(root->left);
	
	cout<<root->data;
	
	Inorder(root->right);
}


int main()
{
	return 0;
}
