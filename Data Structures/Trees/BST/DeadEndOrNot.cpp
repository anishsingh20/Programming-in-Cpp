#include<iostream>
#include<set>

/*Program to check if a BST has dead end or not
*/
using namespace std;

struct node {
	int data;
	struct node *left,*right;	
		
};


struct node *newNode(int data)
{
	struct node *temp = new node();
	temp->data = data;
	
	return temp;
}


void FillHashMap(node *root,set<int> &allNodes,set<int>LeafNode)
{
	if(root==NULL)
		return;
		
	allNodes.insert(root->data);
	
	
	//inserting leaf nodes in a separate hash map
	if(root->left==NULL && root->right==NULL)
	{
		LeafNode.insert(root->data);
		return;
	}
	
	//recursively calling the function on left and right subtrees
	FillHashMap(root->left,allNodes,LeafNode);
	FillHashMap(root->right,allNodes,LeafNode);
}



bool DeadEndOrNot(node *root)
{
	set<int>all_nodes,leafNodes;
	
	if(!root)
		return;
		
	//populating the hash maps
	
	FillHashMap(root,all_nodes,leafNodes);
	
	
	//now checking if there exists a leaf x and nodes with x+1 or x-1
	for(auto i = leafNodes.begin(); i != leafNodes.end() ; i++)
	{
		
	}
		
	
}


int main()
{
	return 0;
}
