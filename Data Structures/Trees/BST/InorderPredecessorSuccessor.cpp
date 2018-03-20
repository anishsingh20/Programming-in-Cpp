#include<iostream>


using namespace std;


/* Program to find inorder predecessor and successor of a key in a BST-

1)Inorder successor is the left most node in right subtree i.e minimum node in right subtree or right child itelf.
2)Inorder predecessor is the right most node in the left subtree ie maximum node in the left subtree or left child itself.

*/


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};

BSTnode *FindMax(BSTnode *root)
{
	if(!root)
		return NULL;
		
	//until we don't reach right most node which has no right child we recur
	if(root->right!=NULL)
		return FindMax(root->right);
		
	return root;
	
		
}

BSTnode* FindMin(BSTnode *root)
{
	if(!root)
		return NULL;
		
	//if left most node has no left child, then it is mimimum node
	if(root->left!=NULL)
		return FindMin(root->left);
		
	return root;	
		
	
	
}


void InorderPreSucc(BSTnode *root,BSTnode *& succ, BSTnode *& pre,int key)
{
	if(!root) return ;
	
	//if key is found
	if(root->data==key)
	{
		
		//inorder predecessor is the right most in left subtree i.e max in left subtree.
		if(root->left)
		{
//			BSTnode *temp = root->left;
//			
//			while(temp->right)
//				temp  = temp->right;
//			
//			pre  = temp;
			pre = FindMax(root->left);
			
		}
		
		//inorder successor is left most in right subtree i.e MIN in right subtree
		if(root->right)
		{
//			BSTnode *temp = root->right;
//			while(temp->left)	
//				temp = temp->left;
//			
//			succ = temp;
			succ = FindMin(root->right);			
		
		}
		
		return ;
	}
	
	//otherwise simply serach for the key
	if(root->data > key)
	{
		succ = root;
		//recur in left subtree
		InorderPreSucc(root->left,succ,pre,key);
		
	}
	
	else {
		pre = root;
		InorderPreSucc(root->right,succ,pre,key);
	}
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
	
	BSTnode *succ=NULL,*pre=NULL;
	
	InorderPreSucc(root,succ,pre,7);
	
	cout<<"Inorder Successor is- "<<succ->data<<endl;
	cout<<"Inorder PRedecessor is- "<<pre->data<<endl;
	
	
	return 0;	
}
