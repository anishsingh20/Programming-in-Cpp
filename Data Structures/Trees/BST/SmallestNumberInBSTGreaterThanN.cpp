#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

/*program to find smallest number in BST greater than equal to N
1)Method-1 Using level order traversal.
2)Using Morris traversal.
3)using Recurion and inorder traversal
*/

struct node {
	int data;
	struct node *left,*right;
};


node *SmallestNumGreaterThanN(struct node *root,int n)
{
	int diff = INT_MAX;
	queue<node *>q;
	if(!root) return 0;
	
	struct node *small ;
	
	q.push(root);
	struct node *temp;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->data >= n)
		{
			if(diff > abs(n-temp->data) )
			{
				diff = abs(n-temp->data);
				small = temp;
			}
			
		}
		
		if(temp->left)	q.push(temp->left);
		
		if(temp->right)	q.push(temp->right);	
			
		
	}	
	
	return small;
}


node* newNode(int item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}


//method-2
node *SmallestNumGreaterThanNUsing Morris(node *root,int n)
{
	
}

int main()
{
	struct node *root = newNode(19);
	
	root->left = newNode(7);
	root->right = newNode(21);
	
	root->left->left = newNode(3);
	
	root->right->right = newNode(11);
	
	root->right->left = newNode(9);
	root->right->right = newNode(14);
	
	
	cout<<SmallestNumGreaterThanN(root,0)->data;
	
	
	return 0;
}
