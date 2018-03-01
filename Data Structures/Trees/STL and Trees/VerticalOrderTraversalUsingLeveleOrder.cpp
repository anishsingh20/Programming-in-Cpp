#include<iostream>
#include <queue>
#include<map>
#include<iomanip>


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


using namespace std;


void PrintVerticalOrderUsingLevelOrder(BinaryTreeNode *root)
{
	if(!root) return;
	
	//queue will store the node and the corresponsing horizontal distance
	queue< pair<BinaryTreeNode *,int> > qu;
	
	map< int,vector<int> >Vorder;
	
	//push root node and its hd as 0 in queue
	qu.push(make_pair(root,0));
	
	while(!qu.empty())
	{
		pair<BinaryTreeNode *,int> temp = qu.front();
		qu.pop();
		
		int hd = temp.second;//sotring the HD
		int node = temp.first->data;
		
		//inserting the HD as key and node data to map
		Vorder[hd].push_back(node);
		
		if(temp.first->left) qu.push(make_pair(temp.first->left,hd-1));//for left subtree HD = -1
		
		if(temp.first->right) qu.push(make_pair(temp.first->right,hd+1));//for right subtree hd = +1
		
	}
	
	map< int,vector<int> >::iterator it;
	

	
	for(it = Vorder.begin() ; it!=Vorder.end() ; it++)
	{
		for(int i=0; i < it->second.size() ; ++i)
		{
			cout << it->second[i] <<" ";
		
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
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	Insert(&root1,9);
	
	pair<int,string>p,anish;
	
	p = make_pair(20,"anish");
	
	anish = p;
	cout<<anish.first<<" "<<anish.second<<endl;
	
	
//	PrintVerticalOrderUsingLevelOrder(root1);
	
	return 0;
}
