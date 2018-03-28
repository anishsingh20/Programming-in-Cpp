#include<iostream>

using namespace std;

struct BSTnode
{
	
	int data;	
	struct BSTnode *left,*right;
};



bool PrintAncestors(BSTnode *root, int key)
{
	if(!root)	return false;
		
	//when key is found , return true
	if(root->data==key)
		return true;
	
	//otherwise, simply find the data in left or right subtree	
	
	if(key <= root->data)	
		bool left = PrintAncestors(root->left,key);
		
	if(key >= root->data)	
		bool right = PrintAncestors(root->right,key);
	
	if(left || right)
	{
		cout<<root->data<<" ";
		return true;	
	}
	
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
	

	
	PrintAncestors(root,1);
	
	
	return 0;
}

