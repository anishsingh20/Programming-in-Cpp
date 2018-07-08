#include<iostream>
#include<queue>

using namespace std;

/*PROGRAM TO FIND THE LEVEL OF A NODE or DEPTH OF A NODE from root
1) Depth- depth of a node is the length of path from root to that node, or from that node to the root,
or simply the number of edges between that node and root of tree. This can also be used to find the 
LEVEL of a node in tree

*/

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};



//function to find the distance from a root to a node--
//this function can also be used to find level of node n1,or depth of a node
int DepthOrLevel(BinaryTreeNode *root,int n1,int d=0)
{
	if(root==NULL)
		return -1;
	
	if(root)
	{
		if(root->data==n1)
		{
			return d;
		}
		
		//recur to the left subtree and increment d, until the node n1 is found
		int l = DepthOrLevel(root->left,n1,d+1);
		
		//recur to the right subtree and increment d, until the node n1 is found
		if(!l) return DepthOrLevel(root->right,n1,d+1);
		
		else return l;
	}	
	
}


//height of tree
int height(BinaryTreeNode *root)
{
	if(root==NULL)
		return 0;
	
	return (1+max(height(root->left),height(root->right)));
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
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	Insert(&root1,9);
	
	cout<<deepestNode(root1)->data<<endl;
	
	cout<<DepthOrLevel(root1,9);
	
	return 0;
}

