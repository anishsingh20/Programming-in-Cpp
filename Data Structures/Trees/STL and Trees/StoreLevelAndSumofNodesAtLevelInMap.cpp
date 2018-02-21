#include<iostream>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

//Program to levels and sum of all nodes at that level in a MAP

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


void StoreSumLevel(struct BinaryTreeNode *root, map <int,int> &Map,int level=0)
{
	
	//base condition
	if(root==NULL)	return;
	
	//otherwise simply store sum of nodes at each different level in map
	//3 different method of inserting in a map
//	Map[level] += root->data;

//	Map.insert(make_pair(level,root->data));
	Map.insert(pair<int,int>(level,root->data));
	
	
		
	//recur to left subtree and keep incrementing level till we reach leaf
	StoreSumLevel(root->left,Map,level+1);
	
	//recur to right subtree and keep incrementing level till we reach leaf
	StoreSumLevel(root->right,Map,level+1);
	
}


void traverseMap(BinaryTreeNode *root)
{
	map<int,int>SMap;
	map<int,int>::iterator it;
	
	//populate the map by calling above function
	StoreSumLevel(root,SMap);
	
	map<int,int>cmap;
	
	//copying contents of SMap to cmap till we find key=2
	cmap.insert(SMap.begin(),SMap.find(2));	
	cout<<"Level"<<" - "<<"Sum"<<endl;
	for(it = cmap.begin(); it!=cmap.end() ;it++)
	{
		cout<<it->first<<setw(10)<<it->second<<endl;
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
	
	traverseMap(root1);

	return 0;	
		
}
