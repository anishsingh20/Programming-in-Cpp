#include<iostream>
#include<queue>


using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//function to traverse the tree in level order-BFS
void levelOrder(struct BinaryTreeNode *root)
{
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *>q;
	
	if(!root) return;
	
	q.push(root);//push the root into queue
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		cout<<temp->data<<" ";
		
		//pushing temp's left and right child if any to queue
		//we will keep (level+1) children in the queue
		if(temp->left)
		{
			q.push(temp->left);
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		}
	}
}     //TIME COMPLEXITY = O(n) , SPACE COMPLEXITY = O(n)
     
     


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


BinaryTreeNode *InsertRec(struct BinaryTreeNode *root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	
	if(root==NULL)
	{
		new_node->data = data;
		new_node->left	=  new_node->right = NULL;
		return new_node;
	}
	
	else 
	{
		if(root->data >= data)
			root->left = InsertRec(root->left,data);
		
		else
			root->right = InsertRec(root->right,data);	
	}
	
	return root;
}



int main()
{
	
	struct BinaryTreeNode *root=NULL;
//	Insert(&root,1);
//	Insert(&root,2);
//	Insert(&root,3);
//	Insert(&root,4);
//	Insert(&root,5);
//	Insert(&root,10);


	InsertRec(root,1);
	InsertRec(root,2);
	InsertRec(root,3);
	InsertRec(root,4);
			
	levelOrder(root);
	
	return 0;
}
