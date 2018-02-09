#include<iostream>
#include<queue>


/*PROGRAM TO FIND MAXIMUM ELEMENT IN A BINARY TREE-
1) Recursive implementation-find max in left subtree, find max in right subtree, compare them with the root_node val and return the max amongst them
2) Non-recursive -using level order traversal 
Both method have TIME COMPLEXITY = O(n) and SPACE COMPLEXITY =O(n)
*/
using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



//recursive implementation
int FindMax(struct BinaryTreeNode *root)
{
	int right,left,root_val,mx;

	if(root!=NULL)
	{
		root_val = root->data;
//		left  = FindMax(root->left);
//		right = FindMax(root->right);
		mx = max( FindMax(root->left), FindMax(root->right) );
		
//		if(left < right)
//		{
//			max = right;
//			
//		}
//		
//		else
//		{
//			max = left;
//		}
		
		if(mx < root_val)
		{
			mx = root_val;
		}
	}
	
	return mx;	
}

int FindMaxUsingLevelOrder(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode *> q;
	BinaryTreeNode *temp;
	int max = INT_MIN;
	if(!root) return -1;
	
	q.push(root);//initially enquing root into queue
	
	//enqueue the level+1 nodes to queue
	while(!q.empty())
	{
		temp = q.front();
		q.pop(); //pop node from front of queue
		
		if(max  <  temp->data)
		{
			max = temp->data;	
		}		
		
		if(temp->left) q.push(temp->left);
		
		if(temp->right) q.push(temp->right);
	}
	
	return max;	
}



int main()
{
	
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
	r4->data = 10;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	cout<<FindMax(root);
	cout<<endl;
	
	cout<<FindMaxUsingLevelOrder(root);
	
	return 0;
}
