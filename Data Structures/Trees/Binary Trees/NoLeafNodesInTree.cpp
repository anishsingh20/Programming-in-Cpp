#include<iostream>
#include<queue>

//finding number of leaf nodes in a Binary tree- 
//Leaf nodes are those whose left and right pointers store NULL or point to NULL

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


int LeafNodesUsingLevelOrder(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode*>q;
	int count = 0;
	BinaryTreeNode *temp;
	
	if(!root) return 0;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		//leaf node
		if(temp->right==NULL && temp->left==NULL)
		{
			count++;
		}
		
		else {
			if(temp->left) q.push(temp->left);
			
			if(temp->right) q.push(temp->right);
		}
	}
	
	return count;
	
	
}


int leafNodesRecursion(struct BinaryTreeNode *root)
{
/*	int lr=0,ll=0;
METHOD-1
	
		
	if(root)
	{
		ll = leafNodesRecursion(root->left);
		if(root->left==NULL && root->right==NULL)
		{
			lr++;
			ll++;
			
			
		}
		lr = leafNodesRecursion(root->right);
	
		
		
		
		
	}	
	
	return (ll+lr);	 leaf = total leaf nodes in left subtree  + leaf in right subtree
*/

//Method-2 (Using a static count variable)
	static int count = 0; 
	if(root)
	{
		if(root->right==NULL && root->left==NULL)
		{
			count++;
		}
	
		//otherwise simply traverse to the left and right subtrees
		leafNodesRecursion(root->left);
		leafNodesRecursion(root->right);
		
	}
	
	return count;
	
	
/*method 3
	if(root)
	{
		if(root->left==NULL && root->right==NULL)
		{
			return 1;
		}
		
		else
		{
			return leafNodesRecursion(root->left) + leafNodesRecursion(root->right);
				
		}
	}

	
*/	
	
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
	struct BinaryTreeNode *root = NULL;
	Insert(&root,1);
	Insert(&root,2);
	Insert(&root,3);
	Insert(&root,4);
	Insert(&root,5);
	Insert(&root,6);
	Insert(&root,7);
	
				
	cout<<LeafNodesUsingLevelOrder(root);
	cout<<endl;
	cout<<leafNodesRecursion(root);
	
}


