#include<iostream>


//program to find sum of nodes within a range L and H , for a BST
using namespace std;


struct node {
	int data;
	struct node *left,*right;	
		
};


struct node *newNode(int data)
{
	struct node *temp = new node();
	temp->data = data;
	
	return temp;
}


struct node* insert(node *root,int data)
{
	if(root==NULL)
	{
		return newNode(data);
	}
	
	if(root->data > data)
	{
		root->left = insert(root->left,data);
		
	}
	
	if(root->data < data)
	{
		root->right = insert(root->right,data);
	}
		
	return root;
	
}


//recursive implementation

int getSum(node *root,int low,int high)
{
		if(!root) return 0;
	
	node *curr = root;
	
	static int sum = 0;
	
////	if( low <= root->data <= high )
//		cout<<root->data<<" ";
	
	while(curr)
	{
		
	

		if(curr->left==NULL)
		{
			if(curr->data <= high && curr->data >= low)
			{
				
				sum += curr->data;
				return sum;
				
			}
				
				
			curr = curr->right;
		}
		
		else
		{
			node *pre = curr->left;
			//finding the inorder predecessor-
			//inorder predecessor is the right most in left subtree or the left child, i.e in BST
			//it is the maximum(right most) in left subtree. 
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;
				
			if(pre->right==NULL)
			{
				pre->right = curr;
				
			
				curr = curr->left;
			}
			
			else
			{
				pre->right  = NULL;
				
				if(curr->data <= high && curr->data >= low)
				{
					
						sum += curr->data;
						return sum;
						
				}
				
				curr = curr->right;						
					
			}
		}

	}	
			
	
	
	
		
	
}

int main()
{
	node *root  = newNode(20);
   	insert(root,4);
	insert(root,8);
	insert(root,12);
	insert(root,22);
    
    cout<<getSum(root,4,22);
	
	return 0;
}
