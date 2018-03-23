#include<iostream>

using namespace std;

/*Program to find Floor and Ceiling if a key in BST

*/


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



BSTnode *FindFloor(BSTnode *root,int key)
{
	//base case
	if(root==NULL) 
		return root;
	
	//if key is equal to root's key
	if(root->data==key)
		return root;
		
	//if key is less than root's key , the the floor is definitely in left subtree,sor we search in left subtree
	if( key < root->data)
		return FindFloor(root->left,key);
		
		
	//otherwise floor is in right subtree, so we search in right subtree
	BSTnode *floor = FindFloor(root->right,key);
	
	//if floor in right subtree found, return it, otherwise floor is root
	return (floor) ? floor : root;
}



//similar method to find the floor
int Floor(BSTnode *root,int key)
{
	
}


BSTnode *newNode(int data)
{


	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	
	cout<<root->data<<" ";
	
	Inorder(root->right);
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
	
	cout<<FindFloor(root,100)->data;
	

}

