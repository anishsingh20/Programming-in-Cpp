#include<iostream>
#include<queue>

using namespace std;

/*Program to find inorder successor of a node in a binary tree
Inorder sucessor-: inorder successor of a node n is the next node which is to be traversed after n in inorder fashion.
Inorder successor of last node in inorder traverasl is NULL, i.e the right most node in a tree in right subtree. 
*/



struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//function to make a new node
BinaryTreeNode *newNode(int data)
{
	BinaryTreeNode *temp = new BinaryTreeNode();
	
	temp->data = data;
	
	temp->right = temp->left = NULL;
	
	return temp;
}


//function to find the lest most node in a tree
BinaryTreeNode* leftMost(BinaryTreeNode *root)
{
	
	//recursive solutuion
//	if(!root) return NULL;
//	
//	//when left most leaf is found
//	if(root->left==NULL && root->right==NULL)
//		return root;
//	
//	//otherwise simply recur to the left subtree of each node
//	leftMost(root->left);

//iterative solution
	while(root!=NULL && root->left!=NULL)
	{
		root = root->left;
	}
	
	return root;
	
		
	
}


BinaryTreeNode *rightMost(BinaryTreeNode *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	rightMost(root->right);
}



BinaryTreeNode* findInorderRecursive(BinaryTreeNode* root, BinaryTreeNode* x )
{
	
	BinaryTreeNode *temp;
    if (!root)
        return NULL;
 
    if (root==x || (temp = findInorderRecursive(root->left,x)) ||
                   (temp = findInorderRecursive(root->right,x)))
    {
        if (temp)
        {
            if (root->left == temp)
            {
                cout << "Inorder Successor of " << x->data;
                cout << " is "<< root->data << "\n";
                return NULL;
            }
        }
 
        return root;
    }
 
    return NULL;
}


BinaryTreeNode* findPredecessorRecursive(BinaryTreeNode* root, BinaryTreeNode* x )
{
	
	BinaryTreeNode *temp;
    if (!root)
        return NULL;
 
    if (root==x || (temp = findInorderRecursive(root->left,x)) ||
                   (temp = findInorderRecursive(root->right,x)))
    {
        if (temp)
        {
            if (root->right == temp)
            {
                cout << "Inorder Successor of " << x->data;
                cout << " is "<< root->data << "\n";
                return NULL;
            }
        }
 
        return root;
    }
 
    return NULL;
}

//function to find inorder predecessor of a node
void InorderPredecessor(BinaryTreeNode *root,BinaryTreeNode *x)
{
	//CASE-1: if x has a left child-then find the rightmost node in its left subtree
	if(x->left!=NULL)
	{
		BinaryTreeNode *rightmost = rightMost(x->left);
		
		cout<<rightmost->data;
	}
	
	//CASE-2: if left child is NULL
	if(x->left==NULL)
	{
		//CASE-if x is left most node in tree, then its inorderPredecessor is NULL
		BinaryTreeNode *leftleaf  = leftMost(root);
		
		if(x==leftleaf) cout<<"NULL, as it is left most node"<<endl;
		
		else
			findPredecessorRecursive(root,x);	
	}
	
	
}

void InorderSuccessor(BinaryTreeNode *root,BinaryTreeNode *x)
{
	//Case1-if right child is not NULL-then its inorder successor is the left most node in its right subtree
	if(x->right!=NULL)
	{
		BinaryTreeNode *leftmost = leftMost(x->right);
		
		cout<<leftmost->data<<endl;
		
	}
	
	//Case 2:if right child is NULL
	if(x->right==NULL)
	{
		int f = 0;
		//Case 3: if x is the right most node in tree-then its inorder succcessor is NULL
		BinaryTreeNode *rightmost = rightMost(root);
		
		if(x==rightmost)
		{
			cout<<"NULL, as it is right most node"<<endl;
		}
		else
		{
			findInorderRecursive(root,x);
		}
	}
}

int main()
{


	BinaryTreeNode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(7);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	
//	cout<<leftMost(root)->data;
//	cout<<endl;
//	cout<<rightMost(root)->data;

	InorderSuccessor(root,root->left->right);
	
	cout<<endl;
	
	InorderPredecessor(root,root->right);	
	

	
	
}
