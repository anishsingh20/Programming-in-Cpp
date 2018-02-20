#include<iostream>
#include<map>
#include<queue>
#include<iomanip>

/*Program to find vertical sum in a given Binary tree-
A vertical line is formed when 2 nodes have same horizontal distance from root
*/

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};


using namespace std;

//Method-1 Using a hash map

//traverse the tree in Inorder and recursively go to left and store different HD nodes in map
//this function is similar to finding horizontal distance of a node, but this time we simply,
//insert all the HD of nodes inside the MAP
void VerticalSumUtil(BinaryTreeNode *root,map<int,int>&Map,int hd)
{
	//base condition
	if(root==NULL) return;
	
	

	//recur to left subtree
	VerticalSumUtil(root->left,Map,hd-1);
	
	//populate the map
	Map[hd] += root->data;
	
	//recur to right subtree
	
	VerticalSumUtil(root->right,Map,hd+1);
}
	

//function to find the vertical sum and traverse the map	
void VerticalSum(BinaryTreeNode *root)
{
	//Map to store different HD and their corresponding nodes data lying on same vertical line-i.e same HD
	map<int,int>Map;
	map<int,int>::iterator it;
	
	
	//fill the map
	VerticalSumUtil(root,Map,0);
	
	//traverse the map to print the verticals sums of each HD
	cout<<" HD " <<":" <<" Vertical Sum "<<endl;
	for(it = Map.begin();it!=Map.end();it++)
	{
		cout<<it->first<< setw(2) << " : " << setw(4) <<it->second<<endl;
	}
	
	
}	

//TIME COMPLEXITY = O(n) , but extra space is consumed due to using MAPS



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
//	Insert(&root1,8);
//	Insert(&root1,9);
	
	VerticalSum(root1);
	
	return 0;
}
