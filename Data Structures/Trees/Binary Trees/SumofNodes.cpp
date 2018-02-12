#include<iostream>
#include<queue>

using namespace std;


struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//Recursive implementation
int SumRecursive(struct BinaryTreeNode *root)
{
	if(!root) return 0;
	
	
	else {
//		int leftsum  = SumRecursive(root->left);
//		int rightsum = SumRecursive(root->right);
//		return root->data + leftsum + rightsum;
		
		//or simply
		
		return (root->data + SumRecursive(root->left) +  SumRecursive(root->right));
	}
	
	
		
	
}

//level order
int SumNodes(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	int sum=0;
	
	if(!root) return 0;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		sum += temp->data;
		
		if(temp->left) q.push(temp->left);
		
		if(temp->right) q.push(temp->right);
	}
	
	return sum;
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
	struct BinaryTreeNode *root1=NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	
	
	cout<<SumNodes(root1);
	cout<<endl;
	cout<<SumRecursive(root1);	


	return 0;
}
