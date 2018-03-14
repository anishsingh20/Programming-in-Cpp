#include<iostream>

using namespace std;

//PROGRAM TO DO INORDER TRAVERSAL WITHOUT USING A STACK AND WITHOUT RECURSION - using MORRIS TRAVERSAL-

//MORRIS traversal is based on threaded binary trees


struct Node {
	
	int data;
	Node *left,*right;
	Node *rightThread;//bool var to indicate that a node has a right pointer point to its inorder succssor
};

Node *newNode(int data){
	Node *temp = new Node;
	
	temp->data = data;
	temp->right=temp->left=NULL;
	temp->rightThread=NULL;
	
	return temp;
}
