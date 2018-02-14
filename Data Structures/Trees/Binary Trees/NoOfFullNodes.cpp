#include<iostream>
#include<queue>

//Program to find number of FULL NODES in a BINARY TREE- Full nodes are those which have both left and right children

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

//1) RECURSIVE APPROACH-similar to finding number of leaf nodes



int FullNodesRec(struct BinaryTreeNode *root)
{
	//Approach 1- Inorder approach
//	int ll,lr;
//	if(!root) return 0;
//	
//	
//	else{
//		
//		//first recur to the left subtree and count full nodes
//		ll = FullNodesRec(root->left);
//		
//		if(root->left && root->right)
//		{
//			ll++; //increment 
//			lr++;
//		}
//		//go to the right subtree and find Full nodes
//		lr = FullNodesRec(root->right);
//	}
//	
//	return ll+lr; //sum of FULL nodes in left and right subtrees


//Approach 2- static counter approach
	
	static int count = 0;
	if(!root) return 0;
	else
	{
		if(root->left && root->right) count++;
		
		//recur down to left and right subtrees
		FullNodesRec(root->left);
		FullNodesRec(root->right);
		
	}
	return count;
	
	
/*approach3-without using a static counter var
The idea is to traverse the tree in postorder. If the current node is full node, we increment result by 1 and add returned values of left and right subtrees.
	if (root == NULL)
       return 0;
  
    int res = 0;
    if  (root->left && root->right) 
       res++;
  
    res += (getfullCount(root->left) + 
            getfullCount(root->right));
    return res;
	*/
}



//simple iterative approach
int FullNodesUsingLevelOrder(struct BinaryTreeNode *root)
{
	queue<BinaryTreeNode *> q;
	BinaryTreeNode *temp;
	int count=0;
	
	if(!root) return 0;
	
	q.push(root);
	
	while(!q.empty())
	{
		
		temp = q.front();
		q.pop();
		
		//count full nodes
		if(temp->left && temp->right) count++;
		
		if(temp->left) q.push(temp->left);
		
		if(temp->right) q.push(temp->right);
	}
	
	
	return count;
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
	struct BinaryTreeNode *root = NULL;
	
	Insert(&root,1);
	Insert(&root,2);
	Insert(&root,3);
	Insert(&root,4);
	Insert(&root,5);
	Insert(&root,6);
	Insert(&root,7);
	
	cout<<FullNodesRec(root)<<endl;
	
	cout<<FullNodesUsingLevelOrder(root);
	
	return 0;
}


