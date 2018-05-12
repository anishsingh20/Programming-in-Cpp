#include<iostream>


using namespace std;


/* Program to find the LCA of 2 nodes in a BST.

if the root's data lies between n1 and n2  then that is the LCA of n1 and n2. If root->data is less than n1, then LCA is in right subtree, otherwise LCA is in the

left subtree.

LCA(n1,n2) is useful in calculating the distance between 2 nodes in a BST.

*/



struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


BSTnode *findLCA(BSTnode *root,int n1,int n2)
{
	//this method will onlt work for some cases-not all test cases are passed with this method
	
//	if(!root) return NULL;
//	
//	//LCA found between n1 and n2
//	if(n1 < root->data && n2 > root->data || n1 > root->data && n2 < root->data)
//		return root;
//		
//	if(n2 < root->data)
//	{
//		return findLCA(root->left,n1,n2);
//	}
//	
//	else return findLCA(root->right,n1,n2);


//	while(1)
//	{
//		if( (n1 < root->data && n2 > root->data) || (n1 > root->data && n2 < root->data) )
//			return root;
//			
//		if(n1 < root->data)
//			root = root->left;
//			 
//		else root=root->right;
//		
//	}


	if(!root ) return NULL;
	
	if(root->data == n1 || root->data == n2)
		return root;
	BSTnode *left = findLCA(root->left,n1,n2);
	
	BSTnode *right = findLCA(root->right,n1,n2);
	
	if(left&&right)
		return root;
	
	return (left) ? left : right;
		
}


BSTnode *insert(BSTnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		BSTnode *temp  = new BSTnode();
		temp->data = value;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
	}
	
	
	
	//returning root of the updated tree
	return root;
}

BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}



//function to find parent of a node
BSTnode* findParent(BSTnode *root,BSTnode *n1)
{
	if(!root) return NULL;
	
	if(root)
	{
		if( root->left && root->left->data == n1->data || root->right && root->right->data==n1->data )
		{
			return root;
		}
	
	//search for the node with key n1 if left or right subtree
		if(root->data < n1->data)
			return findParent(root->right,n1);
		
		if(root->data > n1->data)
			return findParent(root->left,n1);
	}
	

	
}



//simplified method to find LCA of 2 nodes using parent node
BSTnode *findLCASimple(BSTnode *root,BSTnode *v1,BSTnode *v2)
{
	if(!root) return NULL;
	
	BSTnode *parent1 = findParent(root,v1);
	
	BSTnode *parent2 = findParent(root,v2);
	
	//if both have same parents
	if(parent1==parent2)
		return parent1;
	
	if(v1->left==v2 || v1->right==v2)
		return v1;
		
	if(v2->left==v1 || v2->right == v1)
		return v2;
	
	
	//otherwise root node is the parent if none of the conditions match
	return root;
		
	
}


int main()
{
	
//	BSTnode *root  = newNode(4);
//	
//	insert(root,2);
//	insert(root,3);
//	
//	
//	insert(root,1);
//	insert(root,7);
//	insert(root,6);
//	
//	cout<<findLCA(root,2,3)->data;
//	
//	cout<<endl;
//	
//	cout<<findParent(root,6)->data;


	BSTnode *root=newNode(7);

	root->left = newNode(5);
	root->right = newNode(9);
	root->right->left = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->right = newNode(11);
	
	
	cout<<findLCASimple(root,root->left->left,root->left->right)->data;
	
}
