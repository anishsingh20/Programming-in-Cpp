#include<iostream>

/*BINARY SEARCH TREES-program to find an element in a BST

1)All basic ops in BST take time proportional to the height if the tree.
2)So for every insertion,deletion and search ops the height of the tree varies as so does the time complexity.
3)For searching a node in a BST, it usually takes O(logn) worst case time for a complete binary tree and for a Skew-tree it takes 
O(n) worst case time.


*/

using namespace std;



struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


BSTnode *searchNode(BSTnode *root,int data)
{
	if(!root) return NULL;
	
	if(root->data==data)
	{
	
		cout<<"Found"<<endl;
		return root;
		
	}
		
		
	if(root->data > data)
		return searchNode(root->left,data);
	
	if(root->data < data)
		return searchNode(root->right,data);
		
		
} //TIME COMPLEXITY  = O(n) worst case for a skew-tree, SPACE COMPLEXITY = O(n)-function call stack


//non recursive implementation-T(n) = O(n), but space complexity = O(1)
BSTnode *searchIterative(BSTnode *root,int data)
{
	if(!root) return NULL;
	
	while(root)
	{
		if(root->data == data)
			return root;
		
		if(root->data > data)
			root = root->left;
		
		if(root->data < data)
			root = root->right;
	}
	
	return NULL;
}


//largest node is the right most node in tree with no right child.
BSTnode *maxNode(BSTnode*root)
{
	if(!root)	return NULL;
	
	if(root->right==NULL)
		return root;
		
	//otherwise simply recur in right subtree
	else return maxNode(root->right);
}


BSTnode *insert(BSTnode *root,int data)
{
	BSTnode *temp  = new BSTnode();
	temp->data = data;

	
	//base condition-if root is NULL
	if(root==NULL)
	{
		
		root = temp;
		return temp;	
		
	}
	
	else
	{
		
		if(root->data >= temp->data)
			root->left = insert(root->left,data);
		
		
		
		else
			root->right = insert(root->right,data);		
		
	}		
}


void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	cout<<root->data<<" ";
	
	Inorder(root->right);
}

int main()
{
	BSTnode *root=newNode(7);

//	root->left = newNode(5);
//	root->right = newNode(9);
//	root->right->left = newNode(8);
//	root->left->left = newNode(2);
//	root->left->right = newNode(6);
//	root->right->right = newNode(11);

	insert(root,3);
	insert(root,10);
	
	insert(root,12);
	insert(root,2);
	insert(root,1);
	
//	searchNode(root,12);
//	cout<<endl;
//	
//	cout<<searchIterative(root,3)->data;
//	cout<<endl;
//	
//	
	cout<<maxNode(root)->data;
	
	cout<<endl;
	
	//inorder traversal gives us a sorted list for BST
	Inorder(root);
	
}


