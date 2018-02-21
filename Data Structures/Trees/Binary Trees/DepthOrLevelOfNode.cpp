#include<iostream>

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
int DeothOrLevel(BinaryTreeNode *root,int n1,int d=0)
{
	
	if(root)
	{
		if(root->data==n1)
		{
			return d;
		}
		
		//recur to the left subtree and increment d, until the node n1 is found
		int l = dist(root->left,n1,d+1);
		
		//recur to the right subtree and increment d, until the node n1 is found
		int r = dist(root->right,n1,d+1);
		
		//if l is non-zero
		if(l) return l;
		else return r;		
		
		
		
	}	
	
}

