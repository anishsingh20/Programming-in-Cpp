#include<iostream>
#include<map>
#include<vector>
#include<queue>


/*Program to do DIAGONAL TRAVERSAL IN A BINARY TREE-logic is to do something similar to VERTICAL TRAVERSAL-but here
we use the slope distances as the key  in map and a vector of nodes at that distance as value
*/

using namespace std;


struct BinaryTreeNode{
	
	int data;
	struct BinaryTreeNode *left,*right;
};


void PopulateMap(struct BinaryTreeNode *root, map < int,vector<int> >&Map,int d)
{
	if(!root) return ;
	
	Map[d].push_back(root->data);
	//now recursively traverse to left and right subtrees
	
	//we increase the vertical distance by 1 for each left node
	PopulateMap(root->left,Map,d+1);
	
	//for a right node it reamins the same
	PopulateMap(root->right,Map,d);
	
}


void DiagonalTraversal(struct BinaryTreeNode *root)
{
	map< int,vector<int> > Map;
	
	//populating the map
	PopulateMap(root,Map,0);
	
	//simply traverse the map 
	map< int ,vector<int> >::iterator it;
	for(it=Map.begin();it!=Map.end();it++)
	{
		cout<<it->first<<"-->";
		
		for(int i= 0 ;i < it->second.size();i++)
		{
			cout<<it->second[i]<<" ";
		}
		
		cout<<endl;
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


int main()
{
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,8);
	Insert(&root1,3);
	Insert(&root1,10);
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,6);
	Insert(&root1,14);
	Insert(&root1,7);
	Insert(&root1,13);
	
	DiagonalTraversal(root1);
}
