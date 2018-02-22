#include<iostream>
#include<queue>

using namespace std;
//finding deepest left leaf node in a binary tree using simple level order taversal

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



//Using level order taversal technique
struct BinaryTreeNode *DeepestLeftLeafLevelOrder(struct BinaryTreeNode *root)
{
	struct BinaryTreeNode *temp;
	BinaryTreeNode *leftLeaf=NULL;
	queue<BinaryTreeNode *>q;
	
	if(!root) return NULL;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		// Since we go level by level, the last 
        	// stored left leaf node is deepest one,
		if(temp->left)
		{
			q.push(temp->left);
			leftLeaf = temp->left; //the deepest left leaf node
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		}
		
	}
	
	return leftLeaf;
	
}




//finding height of tree
int heightTree(struct BinaryTreeNode *root)
{
	if(root==NULL) return 0;
	
	else
		return (1+max(heightTree(root->left),heightTree(root->right)) );
}

BinaryTreeNode *DeepestLeftLeaf(struct BinaryTreeNode *root)
{
	//base condition
	if(root==NULL) return NULL;
	
	
	//finding depths or heights of left and right subtrees
	int hsl = heightTree(root->left);
	int hsr = heightTree(root->right);
	
	//if a leaf node
	if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	
	if(hsl > hsr)
		return DeepestLeftLeaf(root->left);
	
	//if height of right subtree is more, then go and search in right subtree
	else if(hsr > hsl)
	{
		return DeepestLeftLeaf(root->right->left);
		
	}
			
	//if heights of left an right subtrees are same then
	else return DeepestLeftLeaf(root->left);
		
}



BinaryTreeNode *printleafTree(struct BinaryTreeNode *root,int level)
{
	//base condition
	if(!root) return NULL;
	
	int htl = heightTree(root->left);
	int htr = heightTree(root->right);
	if(level==0) 
	{
		if(root->left==NULL && root->right==NULL)
		{
			return root;
		}
		
		
	}
		
	else if(level  > 0 )
	{
		//if order is to traverse from left to right
		
		if(htl > htr)
			return printleafTree(root->left,level-1);
		else
			return printleafTree(root->right->left,level-1);	
	
		
		//when order is to print from right to left
	}
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
	struct BinaryTreeNode *r7 = new BinaryTreeNode();
	struct BinaryTreeNode *r8 = new BinaryTreeNode();
	struct BinaryTreeNode *r9 = new BinaryTreeNode();
	struct BinaryTreeNode *r10 = new BinaryTreeNode();
		
	
			
	

	
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 5;
	r5->data = 6;
	r6->data = 7;
	r7->data = 8;
	r8->data = 9;
	r9->data = 10;
	r10->data = 11;
	
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right=NULL;

	r3->left = NULL;
	r3->right=NULL;
	
	r2->left = r4;
	r2->right = r5;
	
	r4->right = r6;
	r4->left = NULL;
	
	r6->left = NULL;
	r6->right  = r8;
	
	r5->right = r7;
	r5->left = NULL;
	r7->right = r9;
	r7->left = NULL;
	r9->right = r10;
	r9->left = NULL;
	
//	r5->left  = r6->left  = NULL;
//	r5->right  = r6->right  = NULL;		
	
//	cout<<DeepestLeftLeaf(root)->data;
	
	cout<<endl;
	
	BinaryTreeNode *result = DeepestLeftLeafLevelOrder(root);
	
	if(result) cout<<result->data;
	else cout<<"Not found";
	cout<<endl;
	

	
	return 0;
}
