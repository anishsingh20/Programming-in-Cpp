#include<iostream>

using namespace std;

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


/*Program to find if 2 BST are same , i.e have same elements or not.

*/


int height(BSTnode *root)
{
	if(!root)
		return -1;
		
	return max(height(root->left),height(root->right)) + 1;
}

//Function to check if both BSTs have same structure as well
bool AreSameBST(BSTnode *root1,BSTnode *root2)
{
	//if the BST have different structures , but same data or produce same list on inorder traversal, then they are different in structures.
	int h1 = height(root1);
	int h2 = height(root2);
	
	if(h1!=h2)
		return false;
	
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
	BSTnode *root1  = newNode(10);
	
	insert(root1,5);
	insert(root1,20);
	insert(root1,15);
	insert(root1,30);
	
	
	BSTnode *root2 = newNode(10);
	
	insert(root2,15);
	insert(root2,30);
	insert(root2,20);
	insert(root2,5);
	
	//height of root1 =2, height of root2 = 3, both trees are different
	cout<<height(root1)<<" "<<height(root2)<<endl;
	
	//both of the above trees have different structures although have same data
	cout<<AreSameBST(root1,root2);
	
	return 0;
		
}
