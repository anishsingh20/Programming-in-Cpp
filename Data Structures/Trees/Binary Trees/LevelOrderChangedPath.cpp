#include<iostream>
#include<queue>
#include<stack>

using namespace std;


struct node{
	
	int data;
	node *left,*right;
};


void levelOrderChanged(node *root)
{
	stack<node*>s; //stack to store a level nodes
	
	queue<node*>q; //queue to store next level nodes
	node *temp;
	
	
	s.push(root);
	
	while(!s.empty())
	{
		
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
	root->right->right->left = newNode(8);

}
