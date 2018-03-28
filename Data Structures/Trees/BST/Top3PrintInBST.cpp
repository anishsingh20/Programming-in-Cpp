#include<iostream>

using namespace std;


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};

//Function to find top3 nodes in BST-similar to finding Kth largest in BST
//as reverse inorder traverasl of BST will give us a sorted list in descending order
void Top3Nodes(BSTnode *root)
{
	static int count=0; //counter var to keep count of visited nodes
	if(!root)	return;
	
	Top3Nodes(root->right);
		
	//till count is less than or equal to 3, print
	if(++count<=3)
		cout<<root->data<<" ";
		
	Top3Nodes(root->left);	
	
}


BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
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
	
	Top3Nodes(root);
}
