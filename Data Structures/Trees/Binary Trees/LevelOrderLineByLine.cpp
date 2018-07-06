#include<iostream>
#include<queue>

using namespace std;

struct node{
	
	int data;
	struct node *left,*right;
};

node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	
	temp->left = temp->right = NULL;
}

void PrintLevelLinebyLine(node *root)
{
	queue<node *>q;
	
	if(!root) return ;
	
	q.push(root);
	q.push(NULL); //marker for completion of a level
	while(!q.empty())
	{
		node *temp = q.front();
		q.pop();
	
		if(temp)
		{
			cout<<temp->data<<" ";
			
			if(temp->left)	q.push(temp->left);
		
			if(temp->right)	q.push(temp->right);
		}	
		
		//if a level is completed
		else if(temp==NULL)
		{
			if(!q.empty())	q.push(NULL);
			
			//end the line and go to the next line-once a level is finished 
			cout<<endl;
		}
		
		
		
		
	}
}

int main(){
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	PrintLevelLinebyLine(root);
	
}
