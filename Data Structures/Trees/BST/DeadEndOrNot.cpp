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
		return false;
		
	//populating the hash maps
	FillHashMap(root,all_nodes,leafNodes);
	
	
	//now checking if there exists a leaf x and nodes with x+1 or x-1
	for(set<int>::iterator i = leafNodes.begin(); i != leafNodes.end() ; i++)
	{
		int x =  (*i);//storing the leaf node
		
		if(all_nodes.find(x+1) != all_nodes.end() && 
		   all_nodes.find(x-1) != all_nodes.end())
		   	return true;
	}
	
	return false;
		
	
}


int main()
{
	return 0;
}
