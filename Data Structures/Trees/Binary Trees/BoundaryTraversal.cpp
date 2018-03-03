
#include<iostream>
#include<queue>

using namespace std;


//PROGRAM TO DO BOUNDARY TRAVERSAL-LEFT, RIGHT and LEAF nodes only
struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



int height(BinaryTreeNode *root)
{
	if(root==NULL) return 0;
	
	return 1 + max(height(root->left),height(root->right));
}


//visiting only height of left subtree-1 left child nodes
void leftBoundary(BinaryTreeNode *root)
{
//this approach only valid for full binar trees-otherwise will show same values
//	int ht_l = height(root->left);
//	
//
//	for(int i=0; i < ht_l-1 ; i++)
//	{
//		cout<<root->left->data<<" ";
//		
//		root = root->left;
//		
//	}

	if(!root) return;
	
	if (root->left)
        {
            // to ensure top down order, print the node
            // before calling itself for left subtree
            cout<<root->data<<" ";
            leftBoundary(root->left);
        }
        else if( root->right )
        {
            cout<<root->data<<" ";
            leftBoundary(root->right);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output		
	
	
}

//visiting only height of right subtree-1 right child nodes
void rightBoundary(BinaryTreeNode *root)
{

//	int ht_r = height(root->right);
//	
//	for(int i=0; i < ht_r-1 ; i++)
//	{
//		cout<<root->right->data<<" ";
//		
//		root = root->right;
//		
//	}

	if(!root) return;
	
	
	if (root->right)
        {
            // to ensure bottom-up order, print the node
            // after calling itself for right subtree
            
            rightBoundary(root->right);
            cout<<root->data<<" ";
        }
        else if( root->left )
        {
            
            rightBoundary(root->left);
            cout<<root->data<<" ";
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output

	
}


//recursive function to visit all the leaf nodes in a binary tree
void visitleaf(BinaryTreeNode *root)
{
	if(!root) return;
	
	if(root->left==NULL && root->right==NULL)
		cout<<root->data<<" ";
	
	visitleaf(root->left);
	visitleaf(root->right);		
}



//main method to do boundary traversal
void BoundaryTraversal(BinaryTreeNode *root)
{
	//first print root
	cout<<root->data<<" ";
	
	//visit the left subtree before left leaf is encountered
	//left subtree is visited in top-down manner
	leftBoundary(root->left);
	
	//now visit all the leaf nodes with left and right pointers as NULL
	visitleaf(root);
	
	//now visit the right subtree before any right leaf is enocuntered
	//right subtree is visted bottom-up manner
	rightBoundary(root->right);
	
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
	struct BinaryTreeNode *root1= NULL;
//	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	Insert(&root1,9);
	Insert(&root1,10);
	
	



//	struct BinaryTreeNode *root = new BinaryTreeNode();
//	struct BinaryTreeNode *r1 = new BinaryTreeNode();
//	struct BinaryTreeNode *r2 = new BinaryTreeNode();
//	struct BinaryTreeNode *r3 = new BinaryTreeNode();
//	struct BinaryTreeNode *r4 = new BinaryTreeNode();
//	struct BinaryTreeNode *r5 = new BinaryTreeNode();
//	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
//	struct BinaryTreeNode *r7 = new BinaryTreeNode();
//	
//	root->data = 20;
//	r1->data = 8;
//	r2->data = 22;
//	r3->data = 4;
//	r4->data = 12;
//	r5->data = 10;
//	r6->data = 14;
//	r7->data = 25;
//		
//	root->left  = r1;
//	root->right = r2;
//	
//	r1->left = r3;
//	r1->right = r4;
//	
//	
//	r4->left = r5;
//	r4->right = r6;
//	
//	
//	r2->right = r7;
	
	
//	r5->left  = r6->left  = NULL;
//	r5->right  = r6->right  = NULL;	
	


	BoundaryTraversal(root1);
	
}


