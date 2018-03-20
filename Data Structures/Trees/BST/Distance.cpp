#include<iostream>


using namespace std;

/*Program to find distance between 2 nodes in BST

2 methods to find the distance between 2 nodes-

a)distance(n1,n2) = dist(root,n1) +  dist(root,n2) - 2*dist(root,LCA(n1,n2))

b)distacne(n1,n2) = dist(LCA(n1,n2) , n1)  + dist(LCA(n1,n2) , n2) 
 
	
*/


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};



//program to find distance between root node and key or simply saying the level of a particular node
int findLevel(BSTnode *root,int key,int d=0)
{
	if(!root)
		return -1;
		
	if(root->data==key)
		return d;
	
	if(root->data < key)
	{
		return findLevel(root->right,key,d+1);
	}
	
	if(root->data > key)
	{
		return findLevel(root->left,key,d+1);
	}	
}

int findLevelIterative(BSTnode *root, int value,int level=0)
{
	if(!root) return -1;
	
	BSTnode *curr = root;
	
	while(curr != NULL)
	{
		if(curr->data < value)
		{
			
			
			
			if(curr->data==value)
			{
				return level;
				
			}
				
			level++;	
			
			curr = curr->right;
		}
		
		if(curr->data > value)
		{
			if(curr->data==value)
			{
				return level;
			}
				
				
			level++;
			
			curr = curr->left;
		}
	}
	
	return 0;
	
}



BSTnode *findLCA(BSTnode *root, int n1,int n2)
{
	
	if(!root ) return NULL;
	
	if(root->data == n1 || root->data == n2)
		return root;
	BSTnode *left = findLCA(root->left,n1,n2);
	
	BSTnode *right = findLCA(root->right,n1,n2);
	
	if(left&&right)
		return root;
	
	return (left) ? left : right;
}


//function to find the distance between 2 nodes in a BST
int distance(BSTnode *root,int v1,int v2)
{
	if(!root) return -1;
	
	//finding LCA of v1 and v2
	BSTnode *LCA = findLCA(root,v1,v2);
	
	//distance between v1 and it's LCA
//	int distLCA1 = findLevel(LCA,v1);
//	
//	int distLCA2 = findLevel(LCA,v2);
//	
//	
//	return distLCA1 + distLCA2;


	//method2-
	
	int d1 = findLevel(root,v1);
	int d2 = findLevel(root,v2);
	
	int distLCA = findLevel(root,LCA->data);
	
	return (d1+d2-2*distLCA);	
	
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


int main()
{
	
	
	BSTnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);	
	
	cout<<findLevel(root,12);
	cout<<findLevelIterative(root,4);
	
	
	cout<<endl;
	cout<<distance(root,1,6);
}
