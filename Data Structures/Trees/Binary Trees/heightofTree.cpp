#include<iostream>
#include<stack>
#include<queue>

//IMPLEMENTATION OF FINDING HEIGHT OF BINARY TREE - height is the longest path from the root of the tree to the deepest node(leaf)

using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//recursive solution -similar to DFS 
int height(struct BinaryTreeNode *root)
{
	int htL=0,htR=0;
	if(root==NULL) return 0;
	
	else
        {
        	
        	return 1 + max(height(root->left),height(root->right)) ;
        	
        	//or 
//            htL = height(root->left);
//            htR = height(root->right);
//            
//            if(htL < htR)
//            {
//            	return (1 + htR);
//	    }
//	    else
//	    {
//	    	return (1 + htL);
//	    }
	    
        }
        
		
	
}


//Non recursive solution to find height of a tree using level order traversal-similar ot BFS
//end of level is identified with NULL
int heightLevelOrder(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode *> q;
	BinaryTreeNode *temp;
	int level=0;
	
	if(!root)
	{
		return 0;
	}
	
	q.push(root);
	
	//end of first level marked by pushing NULL
	q.push(NULL);
		while(!q.empty())
		{
			root = q.front();
			q.pop();
			
			//completion of current level i.e when it reaches NULL 
			if(root==NULL)		
			{
				if(!q.empty())
				{
					q.push(NULL);		
				}
				level++;
				
			}
			
			else {
				if(root->left) q.push(root->left);
				if(root->right) q.push(root->right);
			}
		}
		
		
		return level;		
	
	
	
}


void TopView(struct BinaryTreeNode *root)
{
	if(!root) return;
	
	//heights of left and right subtree
	int hl = height(root->left);
	
	int hr = height(root->right);
	
	
	if(root)
	{
		cout<<root->data<<" ";
		
		if(hl >= hr) TopView(root->left);
		
		else TopView(root->right);
	}
	
}


//function to traverse the tree in level order-BFS
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
}     //TIME COMPLEXITY = O(n) , SPACE COMPLEXITY = O(n)
     
     


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
	
	struct BinaryTreeNode *root=NULL;
	Insert(&root,1);
	Insert(&root,2);
	Insert(&root,3);
	Insert(&root,4);
	Insert(&root,5);
	
//	Insert(&root,11);
//	Insert(&root,12);
//	Insert(&root,13);
//	Insert(&root,15);
	
	levelOrder(root);
	cout<<endl;
	
	cout<<height(root)<<endl;
	cout<<heightLevelOrder(root);
	
	cout<<endl;
	
	TopView(root);
	
	return 0;
}
