#include<iostream>

using namespace std;

/*Program to find Kth largest item in the BST.

We know that Inorder traversal of the BST results in a Sorted list. Hence Reverse Inorder traversal will find the list in 
descending order i.e we first traverse the right subtree , then visit root and then traverse to the left subtree.

Hence while doing reverse inorder traversal we maintain a count of number of visited nodes.


*/

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



//function returns the pointer to the Kth largest node
BSTnode *KthLargestBST(BSTnode *root,int k)
{
	static int count=0; //static count variable which counts the number of nodes traversed starting from rightmost node(largest node)
	if(!root)	return NULL;
	
	//first traverse to the right subtree
	BSTnode *right = KthLargestBST(root->right,k);
	
	if(right)
		return right;


	
	if( ++count == k)
	{
//		cout<<root->data<<endl;
		return root;
	}
	
	return KthLargestBST(root->left,k);
	
}



BSTnode *insert(BSTnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		BSTnode *temp  = new BSTnode();
		temp->data = value;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
	}
	
	
	
	//returning root of the updated tree
	return root;
}


BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


int main()
{
	BSTnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);
	
	
	cout<<KthLargestBST(root,4)->data;
	
}
