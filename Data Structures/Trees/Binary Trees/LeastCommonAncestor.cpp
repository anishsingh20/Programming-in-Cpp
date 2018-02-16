#include<iostream>
#include<vector>
#include<queue>

/*Program to find least common ancestor of 2 nodes

Method-1 ) a) Finding paths from root to node n1 , and root to node n2 ad stroring the paths in a vector
	   b) Then returning the first same element in the vectors, before mismatch. 	
	   
This method does 2 traversals of tree to store the paths and then consumes extra memory due to involvement of storing paths
Time complexity=O(n)
*/

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//Method-1

bool FindPath(struct BinaryTreeNode *root,vector<int>&path, int data)
{
	//base condition
	if(root==NULL) return false;
	
	//otherwise simply push node in a the path vector
	path.push_back(root->data);
	
	 // See if the data is same as root's data
	if(root->data==data) return true;
	
	//check if data is found in left or right subtrees
	if(root->left && FindPath(root->left,path,data) || root->right && FindPath(root->right,path,data))
		return true;
		
	//if data not in the tree , remove root from path vector and return false
	path.pop_back();
	return false;
	
}


int FindLCA(struct BinaryTreeNode *root,int n1, int n2)
{
	//vectors to store paths
	vector<int>path1,path2;
	
	if(!FindPath(root,path1,n1) || !(FindPath(root,path2,n2)))
		return -1;
	
	//compare the paths to get first different value
	int i;
	for(i=0;i<path1.size() && i<path2.size();i++)
	{
		if(path1[i]==path2[i])
			break;
		
		else
			return path1[i-1];

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
	struct BinaryTreeNode *root1=NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	
	cout<<FindLCA(root1,5,6);
	
	return 0;
}


