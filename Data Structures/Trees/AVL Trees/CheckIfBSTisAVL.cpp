#include<iostream>
#include<math.h>


//program to check is a BST is AVL tree or not
//we simply have to check for the balance condition recursively while traversing the tree

using namespace std;

struct BSTnode {
	
	int data,height;
	struct BSTnode *left,*right;	
};



int Height(BSTnode *root)
{
	if(!root)
		return -1;
		
	else
		return max(Height(root->left),Height(root->right)) + 1;
}


int isBSTAVL(BSTnode *root)
{
	if(!root)
		return -1;
	
	//check a root
	if(Height(root->right)-Height(root->left)==2 || abs(Height(root->left)-Height(root->right)) > 1 )  
		return 0;
	
	//then recursively check for left subtree for the balanced conidtion	
	if(root->left)
		return isBSTAVL(root->left);
		
	//then recursively check for right subtree for balanced condition
	if(root->right)
		return isBSTAVL(root->right);
		
	return 1;	
	
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
	BSTnode *root=newNode(8);

	root->left = newNode(6);
	root->left->right = newNode(7);
//	root->right->left = newNode(8);
//	root->left->left = newNode(2);
//	root->left->right = newNode(5);
//	root->right->right = newNode(11);
//	root->right->right->right = newNode(12);
	
	if(!isBSTAVL(root))
		cout<<"BST is not an AVL tree"<<endl;
	
	else
		cout<<"BST is an AVL tree"<<endl;
}
