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
	BinaryTreeNode *temp;
	
	if(!root) return;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(root->left)
		{
			q.push(root->left);
		}
		
		if(root->right)
		{
			q.push(root->right);
		}
		
		s.push(temp); //pushing the dequed item to stack

	}
	
	//now stack has BinaryTreeNodes in reversed order
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}


int main()
{
	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();
	struct BinaryTreeNode *r5 = new BinaryTreeNode();
	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 5;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	r5->left  = r6->left  = NULL;
	r5->right  = r6->right  = NULL;	
	
	ReverseLevelOrder(root);
	
	DeleteTree(root);
	
	
	return 0;
}

