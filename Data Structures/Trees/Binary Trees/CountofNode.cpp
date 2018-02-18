#include<iostream>
#include<queue>

using namespace std;


struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};


//function to return the SIZE of tree - number of descendants of root including itself
int countRec(struct Node *root)
{
	//need to declare static variable
	static int size=0;
	
	if(root)
	{
		size++;
		countRec(root->left)  ;
		countRec(root->right) ;
	}
	
	return size;
	
	
	/*method -2
	
	if(root)
		return (1 + countRec(root->left)  + countRec(root->right));
	*/
	
}

//non-recursive solution to find size of a binary tree using level-order traversal
int SizeofTree(struct Node *root)
{
	queue<Node *> q;
	Node *temp;
	int count=0;
	
	if(!root) return 0;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		count++;
		
		if(root->left) q.push(root->left);
		
		if(root->right) q.push(root->right);
	}
	
	return count;
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
	Insert(&root,43);
		
	cout<<countRec(root);
	
	cout<<endl;
	
	PreOrderRec(root);	
}
