#include<iostream>
#include<set>
#include<vector>

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


//USing morris traverasl to check if 2 BST have same elements or not, Order does not matter

bool AreSameBST(BSTnode *root1,BSTnode *root2)
{

		
	
	BSTnode *curr1=root1,*curr2=root2;
	while(curr1 && curr2)
	{
		if(curr1->left==NULL && curr2->left == NULL)
		{
			if(curr1->data!=curr2->data)
			{
				return false;
			}
			
			curr1 = curr1->right;
			curr2 = curr2->right;
			
		}
		
		else
		{
			BSTnode *pre1,*pre2;
			pre1 = curr1->left;
			pre2 = curr2->left;
			
			while(pre1->right!=NULL &&pre2->right!=NULL && pre1->right!=curr1 && pre2->right!=curr2)
			{
				pre1 = pre1->right;
				pre2= pre2->right;
			}
			
			if(pre1->right==NULL && pre2->right==NULL)
			{
				pre1->right = curr1;
				pre2->right = curr2;
				
				curr1 = curr1->left;
				curr2 = curr2->left;
				
			}
			
			else
			{
				pre1->right=NULL;
				pre2->right=NULL;
				
				if(curr1->data!=curr2->data)
				{
					return false;
				}
				
				curr1 = curr1->right;
				curr2 = curr2->right;
				
			}
			
		}
	}	
	
	
	return true;
} //Time complexity  = O(max(m,n)) ,Space complexity = O(1) as no recursion or stack is used to do inorder traversal




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
	
	insert(root2,20);
	insert(root2,30);
	insert(root2,15);
	insert(root2,5);
	
	
	//height of root1 =2, height of root2 = 3, both trees are different
	cout<<height(root1)<<" "<<height(root2)<<endl;
	
	//both of the above trees have different structures although have same data
	if(AreSameBST(root1,root2))
	{
		cout<<"Yes"<<endl;
	}
	else
		cout<<"No"<<endl;
	cout<<endl;

	
	return 0;
		
}
