#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode *nextSibling;
};


//function to fill and connect the nextSibling pointer
int FillNextSiblingLevelOrder(BinaryTreeNode* root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	
	if(root==NULL) return 0;
	
	q.push(root);
	q.push(NULL); //marker for completion for level 0 of tree by pushing NULL
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp==NULL)
		{
			//another marker for completion of current level
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		
		else
		{
			//making the connection
			temp->nextSibling = q.front();
			
			if(temp->left) q.push(temp->left);
			
			if(temp->right) q.push(temp->right);
		}
	}
	return 1;
}

//TIME COMPLEXITY = O(n)

int InsertNextSibling(BinaryTreeNode *root, map <int,int> &Map)
{
	if(root==NULL) return -1;
	
	
	//simply inserting each node and its nextSibling in Map
	
	//inserting in In-order fashion	
	
	
	if(root)
	{
		Map[root->data] = root->nextSibling->data ;
		
		InsertNextSibling(root->left,Map;
		InsertNextSibling(root->right,Map);
		return 1;
	}
	
	
	return 0;
		
		
	
		
	
	
	
	


	
}


void TraverseMap(BinaryTreeNode *root)
{
	//filling siblings
	
	map<int,int>SMap;
	map<int,int>::iterator it;
	
	
	//filling the nextSiblings
	FillNextSiblingLevelOrder(root);
	
	
	//populating the map with node and its next sibling
	InsertNextSibling(root,SMap);
	
	
	cout<<"Node"<<"--"<<"Next Sibling"<<endl;
	for(it=SMap.begin();it!=SMap.end();it++)
	{
		cout<<it->first<<"---"<<it->second<<endl;
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
	
	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();
	struct BinaryTreeNode *r5 = new BinaryTreeNode();
	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 5;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	r5->left  = r6->left  = NULL;
	r5->right  = r6->right  = NULL;
	
	
		
	TraverseMap(root);
	
	return 0;
}
