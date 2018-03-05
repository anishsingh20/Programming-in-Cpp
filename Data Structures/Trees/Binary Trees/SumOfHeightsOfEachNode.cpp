#include<iostream>
#include<queue>
#include<vector>
#include<numeric>

using namespace std;

//program to find sum of heights of each node in a binary tree

/* 2 Methods-to do this
1) Efficient 
2) Inefficient 

*/


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


int height(BinaryTreeNode *root)
{
	if(!root) return 0;
	
	else
		return 1+max(height(root->left),height(root->right));
}

int SumHeights(BinaryTreeNode *root)
{
	//base condition
	if(!root) return 0;
	
	return height(root) + SumHeights(root->left)  + SumHeights(root->right);
	
	
	
} //time complexity = O(nh)



//SOLUTION-2 Efficient solution-The idea is to compute height and Sum in same recursive call

int getTotalHeightUtil(BinaryTreeNode *root,int &sum)
{
	if(root == NULL)
        	return 0;
 
    int lh = getTotalHeightUtil(root->left, sum);
    int rh = getTotalHeightUtil(root->right, sum);
    int h = max(lh, rh) + 1;
 
    sum = sum + lh + h + rh;
    return h;

		
}

int getSumHeight(BinaryTreeNode *root)
{
	int sum = 0;
	
	//calling the Utility function
	getTotalHeightUtil(root,sum);
	
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
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
//	Insert(&root1,2);
//	Insert(&root1,1);
	
	cout<<SumHeights(root1);
	
	cout<<endl;
	
	cout<<"efficient method:"<<endl;
	int sum=0;
	cout<<getSumHeight(root1);
	
	
	
	
	


}
