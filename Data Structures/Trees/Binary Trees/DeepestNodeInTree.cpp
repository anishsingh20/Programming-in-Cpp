#include<iostream>
#include<queue>

using namespace std;

//program to find deepest node in the tree using level order traversal
struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



int heightTree(BinaryTreeNode *root)
{
	if(root==NULL) return 0;
	
	else
		return (1 + max(heightTree(root->left),heightTree(root->right)));
}

//recursive program to find the deepst node in the tree
struct BinaryTreeNode *DeepestNodeRec(struct BinaryTreeNode *root)
{
	//base condition
	if(root==NULL)	return NULL;
	
	//finding depths or height of left and right subtrees and moving in the direction of max depth
	int ht_ls = heightTree(root->left);
	int ht_rs = heightTree(root->right);
	
	//if a deepest leaf node condition
	if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	
	if(ht_rs > ht_ls) return DeepestNodeRec(root->right);
	
	else return DeepestNodeRec(root->left);
	
	
	
}

struct BinaryTreeNode * DeepestNode(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	if(!root) return NULL;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->left) 
		{
			q.push(temp->left);
		
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		
		}
	}
	
	return temp;
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
}     

int main()
{
//	struct BinaryTreeNode *root=NULL;
//	Insert(&root,1);
//	Insert(&root,2);
//	Insert(&root,3);
//	Insert(&root,4);
//	Insert(&root,5);
//	Insert(&root,10);
//	Insert(&root,11);
//	Insert(&root,12);
//	Insert(&root,13);
//	Insert(&root,15);

	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();
	struct BinaryTreeNode *r5 = new BinaryTreeNode();
	struct BinaryTreeNode *r6 = new BinaryTreeNode();
	struct BinaryTreeNode *r7 = new BinaryTreeNode();	
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 5;
	r5->data = 6;
	r6->data = 7;
	r7->data = 8;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	r3->left  = r7;
	
	r7->left  = r6->left = NULL ;
	r7->right  = NULL;
	r5->right  = r6->right  = NULL;
		
	
	levelOrder(root);
	
	cout<<endl;
	
	cout<<heightTree(root->right)<<endl;
	
	cout<<"The deepest Node us->"<<endl;
	cout<<DeepestNode(root)->data;
	cout<<endl;
	
	
	cout<<DeepestNodeRec(root)->data;
	
	
	return 0;
}
