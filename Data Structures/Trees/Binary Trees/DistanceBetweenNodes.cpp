#include<iostream>
#include<queue>

using namespace std;

/*program to find distance between 2 nodes in a Binary tree
1)distance(n1,n2) = dist(root,n1) + dist(root,n2) - 2*dist(root,LCA(n1,n2)) 
 or 
2)another better solution is to find dist(n1,n2) = dist(LCA(n1,n2),n1)  + dist(LCA(n1,n2),n2) -in this approach we simply 
find the distance from the LCA(n1,n2) node to n1 and n2 and add them
We first find LCA(n1.n2) ,then we find distance from LCA to two nodes.
*/

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};



//function to find the distance from a root to a node--
//this function can also be used to find level of node n1,or depth of a node
int dist(BinaryTreeNode *root,int n1,int d=0)
{
	
	if(root)
	{
		if(root->data==n1)
		{
			return d;
		}
		
		//recur to the left subtree and increment d, until the node n1 is found
		int l = dist(root->left,n1,d+1);
		
		//recur to the right subtree and increment d, until the node n1 is found
		//if l is non-zero
		if(l) return l;
		else dist(root->right,n1,d+1);		
		
		
		
	}	
	
}

//progrm to find the LCA of 2 nodes
BinaryTreeNode *FindLCAusingSingleTraversal(struct BinaryTreeNode *root, int n1,int n2)
{
	
		//base condition
		if(root==NULL) return NULL;
		
		if(root->data==n1 || root->data==n2)
		 	return root;
		
		//otherwise recur down to left and right subtrees
		BinaryTreeNode *left = FindLCAusingSingleTraversal(root->left,n1,n2);
		BinaryTreeNode *right = FindLCAusingSingleTraversal(root->right,n1,n2);
		
		//if both left and right funcion calls return non-NULL then we have found the LCA , and its is their parent
		if(left && right)	return root;
		
		return (left) ? left : right;

	
	
	
}

//function to find distance between 2 nodes-i.e the number of edges between them, or length of path
int DistNode(BinaryTreeNode *root,int n1,int n2)
{
/*METHOD-1	

	int d1 = dist(root,n1);
	
	int d2 = dist(root,n2);
	
	//finding LCA of n1 and n2 nodes
	BinaryTreeNode *LCA = FindLCAusingSingleTraversal(root,n1,n2);
	int dLCA = dist(root,LCA->data); //distance between root and LCA node 
	
	return (d1+d2-2*dLCA);
	*/
	
//METHOD2
	//distance between root and LCA of n1 and n2
	//finding LCA
	BinaryTreeNode *LCA = FindLCAusingSingleTraversal(root,n1,n2);
	int n1LCA= dist(LCA,n1);
	int n2LCA = dist(LCA,n2);

	return n1LCA + n2LCA;
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
	Insert(&root1,6);
	Insert(&root1,7);
	Insert(&root1,8);
	Insert(&root1,9);

	cout<<dist(root1,3)<<endl;
	
	cout<<DistNode(root1,5,9);
	return 0;
}
