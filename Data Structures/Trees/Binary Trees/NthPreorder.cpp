#include<iostream>

using namespace std;

struct node {
	int data;
	struct node *left,*right;
};


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

node* newNode(int item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
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

	struct node *root = newNode(19);
	
	root->left = newNode(7);
	root->right = newNode(21);
	
	root->left->left = newNode(3);
	
	root->right->right = newNode(24);
	
	cout<<"preorder traversal is "<<endl;
	Preorder(root);
	cout<<endl;
	nthPreorder(root,2);
	
	
	return 0;
}
