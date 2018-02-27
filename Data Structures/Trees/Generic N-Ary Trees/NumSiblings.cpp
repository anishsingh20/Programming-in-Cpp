#include<iostream>
#include<queue>

//PROGRAM TO FIND SUM OF NODES IN A GENERIC TREE

using namespace std;

struct TreeNode{
	int data;
	struct TreeNode *firstChild;
	struct TreeNode *nextSibling;
};









int numSiblings(TreeNode *root)
{

	int count = 0;
	
	while(root)
	{
		
		count++;
		
		
		
		root = root->nextSibling;
	}
	
	return count;
}



//simply first go to the first child , and then keep counting all the nextSiblings of current node
int numChildren(TreeNode *root)
{
	int count = 0;
	
	root  = root->firstChild;
	
	while(root)
	{
		count++;
		root=root->nextSibling;
	}
	
	return count;
}

int main()
{
	
	struct TreeNode *root= new TreeNode();
	struct TreeNode *n1= new TreeNode();
	struct TreeNode *n2= new TreeNode();
	struct TreeNode *n3= new TreeNode();
	struct TreeNode *n4= new TreeNode();
	struct TreeNode *n5= new TreeNode();
	
	root->data=1;
	n1->data=2;
	n2->data=3;
	n3->data=4;
	n4->data=5;
	n5->data = 6;
	
	root->firstChild = n1;
	
	n1->nextSibling = n2;
	
	n2->nextSibling = n3;
	
	n2->firstChild = n5;
	
	n1->firstChild  = n4;
	
	
	cout<<numChildren(n2);

	return 0;
	
	
	
}

