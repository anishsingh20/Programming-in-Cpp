#include<iostream>
#include<stack>
#include<queue>

//program to print reverse of levele order traversal using an AUX STACK

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

void ReverseLevelOrder(struct Node *root)
{
	queue<Node *>q;
	stack<Node *> s;
	Node *temp;
	
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
	
	//now stack has nodes in reversed order
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}


int main()
{
	struct Node *root = new Node();
	struct Node *r1 = new Node();
	struct Node *r2 = new Node();
	struct Node *r3 = new Node();
	struct Node *r4 = new Node();
	struct Node *r5 = new Node();
	struct Node *r6 = new Node();	
	
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
	
	
	return 0;
}

