#include<iostream>
#include<queue>

using namespace std;

//PROGRAM TO CHECK IF 2 TREES ARE MIRROR OF EACH OTHER 

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//recursive program to find if 2 trees are Mirrors of each other or not
bool MirrorOrNot(struct BinaryTreeNode *root1, struct BinaryTreeNode *root2)
{
	if(!root1  && !root2) return true;
	
	if(!root1 || !root2) return false;
	

	if(root1->data != root2->data) return false;
	
	else return MirrorOrNot(root1->left,root2->right) && MirrorOrNot(root1->right,root2->left);
	
//	else 
//	{
//		bool left = MirrorOrNot(root1->left,root2->right);
//		
//		bool right = MirrorOrNot(root1->right,root2->left);
//		
//		if(left&&right) return true;
//	}
	

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
	struct BinaryTreeNode *root2 =NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	


	Insert(&root2,1);
	Insert(&root2,3);
	Insert(&root2,2);
	Insert(&root2,7);
	Insert(&root2,6);
	Insert(&root2,5);
	Insert(&root2,4);
		
	cout<<MirrorOrNot(root1,root2);
	
	
	return 0;
}
