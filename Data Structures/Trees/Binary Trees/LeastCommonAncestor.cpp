#include<iostream>
#include<vector>
#include<queue>

/*Program to find least common ancestor of 2 nodes

Method-1 ) a) Finding paths from root to node n1 , and root to node n2 ad stroring the paths in a vector
	   b) Then returning the first same element in the vectors, before mismatch. 	
	   
This method does 2 traversals of tree to store the paths and then consumes extra memory due to involvement of storing paths
Time complexity=O(n)
*/

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//Method-1

bool FindPath(struct BinaryTreeNode *root,vector<int>&path, int data)
{
	//base condition
	if(root==NULL) return false;
	
	//otherwise simply push node in a the path vector
	path.push_back(root->data);
	
	 // See if the data is same as root's data
	if(root->data==data) return true;
	
	//check if data is found in left or right subtrees
	if(root->left && FindPath(root->left,path,data) || root->right && FindPath(root->right,path,data))
		return true;
		
	//if data not in the tree , remove root from path vector and return false
	path.pop_back();
	return false;
	
}


int FindLCA(struct BinaryTreeNode *root,int n1, int n2)
{
	//vectors to store paths
	vector<int>path1,path2;
	
	if(!FindPath(root,path1,n1) || !(FindPath(root,path2,n2)))
		return -1;
	
	//compare the paths to get first different value
	//Traverse both paths till the values in arrays are same. Return the common element just before the mismatch.
	int i;
	for(i=0;i<path1.size() && i<path2.size();i++)
	{
		//stay inside the loop and iterate until we have same nodes in both path vectors
		if(path1[i]!=path2[i])
			break;
	}
	//after coming out of loop  return 
	cout<<i<<endl;	
	return path1[i-1];

	
}



//function to find the parent of a node
struct BinaryTreeNode *findParentNode(struct BinaryTreeNode *root,int data)
{
	
	//checking if root is NULL
	if(root==NULL) 
		return NULL;
		
		
	//checking if root has left or right subtree	
//	if(root->left==NULL && root->right==NULL)
//		return NULL;
		

	else
	
	{
	
		//checking for root's left and right subtree to avoid errors
		if( root->left && root->left->data == data || root->right &&  root->right->data==data)
		{
			return root;
		}
		
		//else recur down to the left and right subtrees
		
			 BinaryTreeNode *left = findParentNode(root->left,data);
			 if(left) return left;
			 
			 else return  findParentNode(root->right,data);
		
	}
	
	
}


//MEthod-2 -Single traversal technique

struct BinaryTreeNode *FindLCASingle(struct BinaryTreeNode *root,BinaryTreeNode *n1, BinaryTreeNode *n2)
{
	BinaryTreeNode *parent1 = findParentNode(root,n1->data);
	BinaryTreeNode *parent2 = findParentNode(root,n2->data);
	
	if(root==NULL)
		return NULL;
	
	//if n2 is left or right child of n1, then n1 is the LCA
	if(n1->left==n2 || n1->right==n2) return n1;
	
	//if n1 is left or right child of n2, then n2 is the LCA
	if(n2->left==n1 || n2->right==n1) return n2;
	
	//if both nodes n1 and n2 have same parents- then return their parent as in this case it is their LCA
	if(parent1==parent2)
	{
		return parent1;
	}
	
	
	//if none of the conditions is true , then the LCA of n1 and n2 is the root node obviously
	else return root;
	
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
//	struct BinaryTreeNode *root1=NULL;
//	
//	Insert(&root1,1);
//	Insert(&root1,2);
//	Insert(&root1,3);
//	Insert(&root1,4);
//	Insert(&root1,5);
//	Insert(&root1,6);
//	Insert(&root1,7);

	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();
	struct BinaryTreeNode *r5 = new BinaryTreeNode();
	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
	struct BinaryTreeNode *r8 = new BinaryTreeNode();
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 5;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	r5->left  = r6->left  = NULL;
	r5->right  = r6->right  = NULL;	
	
		
	cout<<FindLCASingle(root,r5,r8)->data;
	
	return 0;
}


