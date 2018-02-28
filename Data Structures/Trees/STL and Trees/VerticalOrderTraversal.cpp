#include<iostream>
#include<map>
#include<queue>
#include<vector>
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

/*Method-1 Using a hash map

1) traverse the tree in Inorder and recursively go to left and store different HD nodes in map
2) this function is similar to finding horizontal distance of a node, but this time we simply,
3) insert all the HD of nodes inside the MAP
4)Now we also maintain a vector of nodes to store nodes having same HD as key
This implementation has TIME COMPLEXITY = O(nlogn) , but extra space is consumed due to using MAPS;
as MAPS in CPP are implemented using self-balancing BST and their ops have T(n) = log(n)

But this implementation might not print nodes in same vertical order as they appear in tree.
*/



void VerticalOrderUtil(BinaryTreeNode *root, map < int, vector<int> > &Map,int hd)
{
	//base condition
	if(root==NULL) return;
	
	
	map<int,int>::iterator i;
	

	//recur to left subtree
	VerticalOrderUtil(root->left,Map,hd-1);
	
		//populate the map
		
		Map[hd].push_back(root->data);//O(logn)
		
	

	
	//recur to right subtree
	
	VerticalOrderUtil(root->right,Map,hd+1);
}//O(nlogn)
	

//function to traverse the map	
void VerticalOrder(BinaryTreeNode *root)
{
	//Map to store different HD and their corresponding nodes data lying on same vertical line-i.e same HD

	map< int,vector<int> > Map;
	map< int,vector<int> >::iterator it;
	
	
	//fill the map
	VerticalOrderUtil(root,Map,0);
	
	//traverse the map to print in Vertical order i.e nodes lying on same vertical line with same HD
	
	for(it = Map.begin();it!=Map.end();it++)
	{
		for(int i=0;i<it->second.size();++i)
			cout<<it->second[i]<<" ";
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
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	Insert(&root1,9);
	
	VerticalOrder(root1);
	
	return 0;
}
