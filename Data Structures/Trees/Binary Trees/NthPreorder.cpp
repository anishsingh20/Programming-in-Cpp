#include<iostream>

using namespace std;


void nthPreorder(node *root,int n)
{
	if(!root) return;
	static int k = 0;
	node *kthnode;
	
	if( ++k == n)
	{
		cout<<root->data;
		return;
	}
	
	if(root->left)
		nthPreorder(root->left,n);
	
	if(root->right)
		nthPreorder(root->right,n);
		
	
	
}

void Preorder(node *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		
		Preorder(root->left);
		
		Preorder(root->right);
	}
}


int main()
{
	
	return 0;
}
