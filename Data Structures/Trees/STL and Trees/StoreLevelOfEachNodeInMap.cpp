#include<iostream>
#include<map>
#include<queue>

using namespace std;

//Program to store all nodes and their corresponding level/or diatance from root in a HASH MAP

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};


/*a simple function to populate the map with a node and its corresponding distance from root/or level
//simply traverse in any traveral order, inorder,preorder,postorder and insert the root and the level
//in this case we are traversing in Inorder.
increment the level + 1 each time be visit a left child or right child recursively
*/
void InsertDistInMap(BinaryTreeNode *root,map<BinaryTreeNode*,int>&DistMap,int l=0)
{

	
	if(root==NULL)	return ;
		
	InsertDistInMap(root->left,DistMap,l+1);
	
	//storing Each node and its corresponsing level in MAP
	DistMap[root] = l;
	
	InsertDistInMap(root->right,DistMap,l+1);	
}

void TraverseMap(BinaryTreeNode *root)
{
	map<BinaryTreeNode*,int> DMap;
	map<BinaryTreeNode*,int>::iterator it;
	
	int sumNode=0,sumLevel=0;
	//populate the map
	InsertDistInMap(root,DMap,0);
	
	//traversing the map using iterators
	cout<<"Node"<<" | "<<"Level"<<endl;
	for(it=DMap.begin();it!=DMap.end();it++)
	{
		cout<<it->first->data<<" ---- "<<it->second<<endl;
		sumNode += it->first->data;
		sumLevel += it->second;
	}
	
	cout<<"Sum"<<endl;
	cout<<sumNode<<"---"<<sumLevel;
	
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
	

	
	
	TraverseMap(root1);
	
	
	return 0;
}
