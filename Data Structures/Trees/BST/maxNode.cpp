#include<iostream>


using namespace std;

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



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

int main()
{
	
	insert(root,3);
	insert(root,10);
	
	insert(root,12);
	insert(root,2);
	insert(root,1);
	
	
	
	return 0;
	
}
