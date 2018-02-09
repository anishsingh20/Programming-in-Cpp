#include<iostream>
#include<queue>

using namespace std;


struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};


//function to return the SIZE of tree - number of descendants of root including itself
int count(struct Node *root)
{
	
	if(root)
	{
		return (1 + count(root->left) + count(root->right) );
	}
	
}


void PreOrderRec(struct Node *root)
{
	
	if(root)
	{
		cout<<root->data<<" ";
		PreOrderRec(root->left);
		PreOrderRec(root->right);
	}
	
	
}


void Insert( struct Node **root,int data)
{
	struct Node *new_node = new Node();
	struct Node *temp;
	queue<Node *> q;
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
	
	struct Node *root = NULL;
	
	Insert(&root,1);
	Insert(&root,2);
	Insert(&root,3);
	Insert(&root,4);
	Insert(&root,5);
	Insert(&root,10);
	Insert(&root,23);
		
	cout<<count(root);
	
	cout<<endl;
	
	PreOrderRec(root);	
}
