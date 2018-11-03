
#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

/*program to find smallest number in BST greater than equal to N
1)Method-1 Using level order traversal.
2)Using Morris traversal.
3)using Recurion and inorder traversal
4)By finding floor is also an space efficient approach
*/

struct node {
	int data;
	struct node *left,*right;
};


node *SmallestNumGreaterThanN(struct node *root,int n)
{
	int diff = INT_MAX;
	queue<node *>q;
	if(!root) return 0;
	
	struct node *small ;
	
	q.push(root);
	struct node *temp;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->data >= n)
		{
			if(diff > abs(n-temp->data) )
			{
				diff = abs(n-temp->data);
				small = temp;
			}
			
		}
		
		if(temp->left)	q.push(temp->left);
		
		if(temp->right)	q.push(temp->right);	
			
		
	}	
	
	return small;
}
//Time complexity = O(n), space compelxity =  O(n) for queue

node* newNode(int item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}

// C++ code to find the smallest value greater
// than or equal to N
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node *left, *right;
};
 
// To create new BST Node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// To insert a new node in BST
Node* insert(Node* node, int key)
{
    // if tree is empty return new node
    if (node == NULL)
        return newNode(key);
 
    // if key is less then or grater then
    // node value then recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    // return the (unchanged) node pointer
    return node;
}
 
// Returns smallest value greater than or 
// equal to key.
int findFloor(Node* root, int key)
{
    Node *curr = root, *ans = NULL;
 
    // traverse in the tree
    while (curr) {
 
        // if the node is smaller than N,
        // move right.
        if (curr->key > key) {
            ans = curr;
            curr = curr->left;
        }       
             
         
        // if it is equal to N, then it will be
        // the answer
        else if (curr->key == key) {
            ans = curr;
            break;
        }
             
        else // move to the right of the tree
            curr = curr->right;
    }
     
    if (ans != NULL)
       return ans->key;
     
    return -1;
}

//method-2
node *SmallestNumGreaterThanNUsingMorris(node *root,int n)
{
	if(!root) return NULL;
	
	node *curr = root;
	node *small;
	
	int diff = INT_MAX;
	while(curr)
	{
		if(!curr->left)
		{
			
			if(curr->data >= n)
			{
				if(diff  > abs(curr->data-n))
				{
					diff = abs(curr->data - n );
					small=curr;
				}
			}
			
			curr = curr->right;
		}
		
		else
		{
			//finding the inorder predecessor
			node *pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
			{
				pre = pre->right;
			}
			
			//building thread
			if(pre->right==NULL)
			{
				pre->right = curr;
				curr = curr->left;
			}
			
			//if thraded link already exists
			else
			{
				pre->right = NULL;
				if(curr->data >= n)
				{
					if(diff  > abs(curr->data-n))
					{
						diff = abs(curr->data - n );
						small=curr;
					}
				}
				
				curr = curr->right;
				
			}
		}
	}
	
	
	return small;
}
//Time complexity = O(n), Space complexity = O(1)



//method 3 using recursion
node *SmallestNumGreaterThanNUsingRecursion(node *root,int n)
{
	int diff  = INT_MAX;
	if(!root)
		return NULL;
		
	if (root->left == NULL && root->right == NULL 
                                && root->data < n)
        	return NULL;
		
	
	
	
	if( (root->data >= n && root->left==NULL) || (root->data >=n && root->left->data < n ) )
	{
		return root;	
	}
	
	
	if(root->data <= n)
	{
		return SmallestNumGreaterThanNUsingRecursion(root->right,n);
	}
	
	else
		return SmallestNumGreaterThanNUsingRecursion(root->left,n);
	
	
		
}


//
void nthPreorder(node *root,int n)
{
	if(!root) return;
	static int k = 0;
	node *kthnode;
	
	if( ++k == n)
	{
		cout<<root->data;
		return;
	}
	
	if(root->left)
		nthPreorder(root->left,n);
	
	if(root->right)
		nthPreorder(root->right,n);
		
	
	
}



int main()
{
	struct node *root = newNode(19);
	
	root->left = newNode(7);
	root->right = newNode(21);
	
	root->left->left = newNode(3);
	
	root->right->right = newNode(24);
	
	
	
	
//	cout<<SmallestNumGreaterThanN(root,10)->data;
//	
//	cout<<endl;
//	
	cout<<SmallestNumGreaterThanNUsingMorris(root,8)->data;
//	

	
	
	return 0;
}
