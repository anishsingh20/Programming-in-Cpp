#include<iostream>
#include<queue>


using namespace std;


//Recursive implementation to travese a tree in level Order
struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};


//function to traverse a tree level wise in any order form left to right or right to left- Breadth first traversal
//ltr is the order of traversing, whether to traverse from left to right or from right to left subtree
void printTree(struct BinaryTreeNode *root,int level)
{
	//base condition
	if(root==NULL) return;
	
	
	if(level==0) 
	{
		cout<<root->data<<" ";
	}
		
	else if(level  > 0 )
	{
		
		printTree(root->left,level-1);
		printTree(root->right,level-1);
		//if order is to traverse from left to right
//		if(ltr)
//		{
//			printTree(root->left,level-1,ltr);
//			printTree(root->right,level-1,ltr);	
//		}
//		
//		//when order is to print from right to left
//		else
//		{
//			printTree(root->right,level-1,ltr);
//			printTree(root->left,level-1,ltr);
//		}
	}
}


//function the get the height of tree
int height(BinaryTreeNode *root)
{
	if(root==NULL) return 0;
	
	else return (1 + max(height(root->left),height(root->right)));
}

BinaryTreeNode *printleafTree(struct BinaryTreeNode *root,int level)
{
	//base condition
	if(root==NULL) return NULL;
	
	BinaryTreeNode *l,*r;
	
	int htl = height(root->left);
	int htr = height(root->right);
	if(level==0) 
	{
		return root;	
	}
		
	else if(level  > 0 )
	{
		//if order is to traverse from left to right
		
		if(htl > htr)
			l = printleafTree(root->left,level-1);
			if(l->left==NULL && l->right==NULL)
			{
				return l;
			}
		else
		{
			r=printleafTree(root->right,level-1);
			if(r->left==NULL && r->right==NULL) return r;
		}
				
	
		
		//when order is to print from right to left
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
	struct BinaryTreeNode *root1 = NULL;
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	
	for(int i =  0 ; i < height(root1); i++)
	{
		printTree(root1,i);
	}
	
}
