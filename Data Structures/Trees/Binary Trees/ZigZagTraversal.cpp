#include<iostream>
#include<stack>
#include<queue>

//PROGRAM TO TRAVERSE A TREE IN ZIG ZAG FASHION-using 2 stacks to store current level nodes and next level nodes
using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};

void ZigZag(BinaryTreeNode *root)
{
	if(!root) return;
	
	stack<BinaryTreeNode *>currLevel;
	stack<BinaryTreeNode *>nextLevel;
	bool leftToright  = true;
	
	currLevel.push(root);
	
	while(!currLevel.empty())
	{
		BinaryTreeNode *temp = currLevel.top();
		currLevel.pop();
		
		if(temp)
		{
			cout<<temp->data<<" ";
			if(leftToright)
			{
				if(temp->left) nextLevel.push(temp->left);
				if(temp->right) nextLevel.push(temp->right);	
			}
			
			else 
			{
				if(temp->right) nextLevel.push(temp->right);
				if(temp->left) nextLevel.push(temp->left);
			}
		}
		
		if(currLevel.empty())
		{
			//whenever curr level stack gets empty, we reverse the lefttoright in order to preserver
			//the Zig-zag traversal order
			leftToright = false;
			swap(currLevel,nextLevel);
		}
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
//TIME COMPLEXITY = O(N) ,  SPACE COMPLEXITY = O(n)

int ZigZagRec(struct BinaryTreeNode *root,bool leftToright)
{

	
	if(!root) return 0;
	if(root)
	{
		
		if(leftToright)
		{
			
			cout<<root->data<<" ";
			ZigZagRec(root->left,leftToright);
			
			ZigZagRec(root->right,leftToright);
			
		}
		else 
		{
			cout<<root->data<<" ";
			ZigZagRec(root->right,!leftToright);
			ZigZagRec(root->left,!leftToright);
		}
	}
	
	return 1;
}

int main()
{

	struct BinaryTreeNode *root1 = NULL;
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	
	
	ZigZag(root1);
	
	cout<<endl;
	
	ZigZagRec(root1,true);	
	return 0;
}
