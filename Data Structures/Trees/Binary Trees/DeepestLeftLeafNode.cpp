#include<iostream>
#include<queue>

using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};

//finding height of tree
int heightTree(struct BinaryTreeNode *root)
{
	if(root==NULL) return 0;
	
	else
		return (1+max(heightTree(root->left),heightTree(root->right)) );
}

struct BinaryTreeNode *DeepestLeftLeaf(struct BinaryTreeNode *root)
{
	//base condition
	if(root==NULL) return NULL;
	
	//finding depths or heighs of left and right subtrees
	int hsl = heightTree(root->left);
	int hsr = heightTree(root->right);
	
	//if a leaf node
	if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	
	if(hsl > hsr)
		return DeepestLeftLeaf(root->left);
	else 
		return DeepestLeftLeaf(root->right);
		
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
//	struct BinaryTreeNode *root1 = NULL;
//	Insert(&root1,1);
//	Insert(&root1,2);
//	Insert(&root1,3);
//	Insert(&root1,4);
//	Insert(&root1,5);
//	Insert(&root1,6);
//	Insert(&root1,7);
//	Insert(&root1,8);

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
	r5->left = r6;
	
//	r5->left  = r6->left  = NULL;
//	r5->right  = r6->right  = NULL;		
	
	cout<<DeepestLeftLeaf(root)->data;
	return 0;
}
