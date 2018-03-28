#include<iostream>

using namespace std;

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


/*Program to find if 2 BST are same , i.e have same elements or not.

*/

//Function to check if both BSTs have same structure as well
bool AreSameBST(BSTnode *root1,BSTnode *root2)
{
	if(!root1 || !root2)
		return false;
	
	AreSameBST(root1->left,root2->left);
	
	if(root1->data==root2->data)
		return true;
	else
		return false;	
	
	AreSameBST(root1->right,root2->right);


}//TIME COMPLEXITY = O(n), Space  = O(n) stack space


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
	BSTnode *root1  = newNode(20);
	
	insert(root1,4);
	insert(root1,8);
	insert(root1,12);
	insert(root1,22);
	
	
	BSTnode *root2 = newNode(20);
	
	insert(root1,4);
	insert(root1,8);
	insert(root1,12);
	insert(root1,22);
	
	cout<<AreSameBST(root1,root2);
	
	return 0;
		
}
