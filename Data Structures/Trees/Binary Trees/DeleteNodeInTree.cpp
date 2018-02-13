#include<iostream>
#include<queue>
#include<cstdlib>
//program to delete a node in a given tree
struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

using namespace std;


BinaryTreeNode *FindNode(struct BinaryTreeNode *root,int data)
{
	if(!root) return NULL;
	
	else
	{
		if(root->data==data)
		{
			return root;
		}
		
		//recur down to left subtree and  right subtree to search
		else
		{
		
			BinaryTreeNode *left = FindNode(root->left,data);
			if(left)
			{
				return left;	
			}
			
			else 
			{
				 
				return FindNode(root->right,data);
			}
		
		}
		
	
	}
		
	
}




BinaryTreeNode *DeleteNode(struct BinaryTreeNode **root,int data)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	
	 BinaryTreeNode *del_node = FindNode(*root,data);
	 
	 if(!*root) return NULL;
	 
	 q.push(*root);
	 
	 while(!q.empty())
	 {
	 	temp = q.front();
	 	q.pop();
	 	
	 	if(temp->left) q.push(temp->left);
	 	
	 	if(temp->right) q.push(temp->right);
	 	
	}
	
	
	//if the node to be deleted in simply the deepest node-no need to swap data
	if(del_node==temp)
	{
		free(del_node);
		
	}
	else {
		swap(del_node->data,temp->data);
		cout<<"Deleted: "<<temp->data;
		free(temp);
	}
	
	
	
	
	return *root;
}


void levelOrder(struct BinaryTreeNode *root)
{
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *>q;
	
	if(!root) return;
	
	q.push(root);//push the root into queue
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		cout<<temp->data<<" ";
		
		//pushing temp's left and right child if any to queue
		//we will keep (level+1) children in the queue
		if(temp->left)
		{
			q.push(temp->left);
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		}
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


void Preorder(struct BinaryTreeNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		Preorder(root->left);
		Preorder(root->right);
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
	
	levelOrder(root1);
	
	cout<<endl;
	
	DeleteNode(&root1,2);
	
	cout<<endl;
	
	cout<<"After deleting the node :"<<endl;
	
	levelOrder(root1);
	
	return 0;

}
