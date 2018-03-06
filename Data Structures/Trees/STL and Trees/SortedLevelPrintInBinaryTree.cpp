#include<iostream>
#include<map>


using namespace std;

//PROGRAM TO PRINT NODES AT EACH LEVEL IN SORTED MANNER USING MAPS


struct BinaryTreeNode{
	
	int data;
	struct BinaryTreeNode *left,*right;
};



void SortedLevelPrintUtil(struct BinaryTreeNode *root, map< int,<vector<int> > &Map,int level)
{
	if(!root) return ;
	
	SortedLevelPrintUtil(root->left,Map,level+1); //increment level as we recur to each left node
	
	Map[level].push_back(root->data); //insert level as key and the node's data in vector
	
	SortedLevelPrintUtil(root->right,Map,level+1); //increment level as we recur to each right node
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
//	Insert(&root1,2);
//	Insert(&root1,1);

return 0;


}

