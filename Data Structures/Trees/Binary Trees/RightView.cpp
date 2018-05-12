#include<iostream>
#include<queue>


using namespace std;

struct node{
	
	int data;
	node *left,*right;
};


void RightView(node *root)
{
	node *temp;
	if(!root)
		return;
	
	queue<node*>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		
	}
}


node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	
	return temp;
}

int main()
{
	
}

