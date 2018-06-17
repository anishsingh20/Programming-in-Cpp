#include<iostream>
#include<queue>

using namespace std;

struct node {
	int data;
	struct node *left,*right;
};

node* newNode(int item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}


int main()
{
	struct node *root = newNode(19);
	
	root->left = newNode(7);
	root->right = newNode(21);
	
	root->left->left = newNode(3);
	
	root->right->right = newNode(11);
	
	root->right->left = newNode(9);
	root->right->right = newNode(14);
	
}
