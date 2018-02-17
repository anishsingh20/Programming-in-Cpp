#include<iostream>
#include<stack>
#include<queue>

//PROGRAM TO TRAVERSE A TREE IN SPIRAL FASHION-using 2 stacks. One to print from left to right order, and other to print from right to left order
using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};



///We will use 2 stacks, One stack to print data from left to right, another satck to print data from right to left order
void SpiralTraversal(BinaryTreeNode *root)
{
	if(!root) return;
	BinaryTreeNode  *temp;
	stack<BinaryTreeNode *>s1; //stack to print from right to left
	stack<BinaryTreeNode *>s2;//satck to print from left to right
	
	s1.push(root);
	
	while(!s1.empty() || !s2.empty() )
	{
		while(!s1.empty())
		{
			temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			
			if(temp->right) s2.push(temp->right);
			if(temp->left)  s2.push(temp->left);
		}
	
		while(!s2.empty())	
		{
			temp = s2.top();
			s2.pop();
			
			cout<<temp->data<<" ";
			
			if(temp->left) s1.push(temp->left);
			
			if(temp->right) s1.push(temp->right);
		}
	}
	
	
}

	
void Insert( struct BinaryTreeNode **root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	new_node->data = data;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(*root==NULL)
	{
		*root = new_node;
		return;
	}
	
	q.push(*root);
	
	while(!q.empty())
	{
		temp  = q.front();
		q.pop();
		
		if(temp->left==NULL)
		{
			temp->left = new_node;
			return;
			
			
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
}
//TIME COMPLEXITY = O(N) ,  SPACE COMPLEXITY = O(n)


int main()
{

	struct BinaryTreeNode *root1 = NULL;
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);

	
	SpiralTraversal(root1);
	
	
	return 0;
}
