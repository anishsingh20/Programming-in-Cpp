#include<iostream>


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


//Program ro find the smallest node in BST-ie the left most node in the tree which has no left child

BSTnode* Min(BSTnode*root)
{
	if(!root)	return NULL;
	
	if(root->left==NULL)
		return root;
		
	else return Min(root->left);
}
//TIME COMPLEXITY =O(n)-worst case -(left skew tree) , S(n) = O(n) -recursion call stack


BSTnode *MinIterative(BSTnode *root)
{
	if(!root) return NULL;
	
	while(root->left)
	{
		root=root->left;
		
		
		
	}


	return root;	
	
}//The space complexity  = O(1)

BSTnode *insert(BSTnode *root,int data)
{
	BSTnode *new_node = new BSTnode();
	
	//base condition-if root is NULL-allocate memory and make node
	if(root==NULL)
	{
		new_node->data = data;
		new_node->left = new_node->right  = NULL;
		
		return new_node;
		
	}
	
	else
	{
		
		if(root->data >= data)
			root->left = insert(root->left,data);
		
		
		
		else
			root->right = insert(root->right,data);		
		
	}	
	
	
	//returning root of the updated binary tree
	return root;	
}

int main()
{
	
	BSTnode *root  = newNode(7);

	insert(root,3);
	insert(root,10);
	
	insert(root,12);
	insert(root,2);
	insert(root,1);
	
	cout<<Min(root)->data;
	
	cout<<endl;
	
	cout<<MinIterative(root)->data;

}
	
	
	
