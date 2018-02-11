#include<iostream>
#include<stack>
#include<queue>

//program to print reverse of levele order traversal using an AUX STACK

using namespace std;

struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};




void ReverseLevelOrder(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode *>q;
	stack<BinaryTreeNode *> s;
	struct BinaryTreeNode *temp;
	
	if(!root) return;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->left)
		{
			q.push(temp->left);
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		}
		
		
		s.push(temp);

	}
	
	//now stack has BinaryTreeNodes in reversed order
	while(!s.empty())
	{
		struct BinaryTreeNode *temp1 = s.top();
		s.pop();
		cout<<temp1->data<<" ";
		
		
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




int main()
{
//	struct BinaryTreeNode *root = new BinaryTreeNode();
//	struct BinaryTreeNode *r1 = new BinaryTreeNode();
//	struct BinaryTreeNode *r2 = new BinaryTreeNode();
//	struct BinaryTreeNode *r3 = new BinaryTreeNode();
//	struct BinaryTreeNode *r4 = new BinaryTreeNode();
//	struct BinaryTreeNode *r5 = new BinaryTreeNode();
//	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
//	
//	root->data = 1;
//	r1->data = 2;
//	r2->data = 3;
//	r3->data = 4;
//	r4->data = 5;
//	r5->data = 6;
//	r6->data = 7;
//	
//	root->left  = r1;
//	root->right = r2;
//	
//	r1->left = r3;
//	r1->right = r4;
//	
//	r2->left = r5;
//	r2->right = r6;
//	
//	r5->left  = r6->left  = NULL;
//	r5->right  = r6->right  = NULL;	
	
	
	struct BinaryTreeNode *root=NULL;
	Insert(&root,1);
	Insert(&root,2);
	Insert(&root,3);
	Insert(&root,4);
	Insert(&root,5);
	Insert(&root,6);
	Insert(&root,7);
	
	ReverseLevelOrder(root);

	
//	DeleteTree(root);
	
	
	return 0;
}

