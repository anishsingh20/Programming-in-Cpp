#include<iostream>
#include<queue>


using namespace std;

//right view is the view of the binary tree where we can only see the right most nodes at each level.

struct node{
	
	int data;
	node *left,*right;
};


void RightView(node *root)
{
	node *temp;
	if(!root)
		return;
	
	queue<node*>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		cout<<temp->data<<" ";
		
		if(temp->right)
			q.push(temp->right);
			
			
	}
}


node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	
	return temp;
}

int main()
{
	node *root = newNode(1);
	
	root->left = newNode(2);
	
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->right = newNode(8);
	
	
	RightView(root);
	
	
}

