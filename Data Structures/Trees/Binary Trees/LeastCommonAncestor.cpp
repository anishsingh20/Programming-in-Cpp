#include<iostream>
#include<vector>
#include<queue>
#include<map>

/*Program to find least common ancestor of 2 nodes

Method-1 ) a) Finding paths from root to node n1 , and root to node n2 ad stroring the paths in a vector
	   b) Then returning the first same element in the vectors, before mismatch. 	
	   
This method does 2 traversals of tree to store the paths and then consumes extra memory due to involvement of storing paths
Time complexity=O(n)


METHOD 2 )FINDING PARENTS 
METHOD 3) SINGLE TRAVERSAL
METHOD 4) USING PARENT POINTER AND MAPS 
*/

using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
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
int findParentNode(struct BinaryTreeNode *root,int data)
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
			return root->data;
		}
		
		//else recur down to the left and right subtrees
		
			 int left = findParentNode(root->left,data);
			 if(left) return left;
			 
			 else return  findParentNode(root->right,data);
		
	}
	
	
}


//MEthod-2 -Single traversal technique
bool FindNode(struct BinaryTreeNode * root,int data)
{


	if(root==NULL) return false;
	
	/// If key is present at root, or in left subtree or right subtree,
    // return true;
	if(root->data==data || FindNode(root->left,data) || FindNode(root->right,data))
		return true;
		
	else return false;

}


int FindLCAsimple(struct BinaryTreeNode *root,BinaryTreeNode *n1, BinaryTreeNode *n2)
{
	if(!FindNode(root,n1->data) || !FindNode(root,n2->data)) 
	{
		cout<<"Node not found in tree"<<endl;
		return -1;
	}
		
	
	int parent1 = findParentNode(root,n1->data);
	int parent2 = findParentNode(root,n2->data);
	
	if(root==NULL)
		return -1;
	
	
	
	//if both nodes n1 and n2 have same parents- then return their parent as in this case it is their LCA
	if(parent1==parent2)
	{
		return parent1;
	}
	
	//if n2 is left or right child of n1, then n1 is the LCA
	if(n1->left==n2 || n1->right==n2) return n1->data;
	
	//if n1 is left or right child of n2, then n2 is the LCA
	if(n2->left==n1 || n2->right==n1) return n2->data;
	
	
	//if none of the conditions is true , then the LCA of n1 and n2 is the root node obviously
	else return root->data;
	
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
			//creating the parent link
			new_node->parent = temp;
			return;
			
			    
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			new_node->parent = temp;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
}



//Method 3- using a single traversal

BinaryTreeNode *FindLCAusingSingleTraversal(struct BinaryTreeNode *root, int n1,int n2)
{
	
	if( !FindNode(root,n1) && !FindNode(root,n2))
		return NULL;
	
	
	
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



//Method-4 using a simple Hash Map to store all ancestors of n1 and then finding the firt matching parent with n2

BinaryTreeNode *findLCAParentPointer(BinaryTreeNode *n1,BinaryTreeNode *n2)
{
	
	if(!n1 || !n2) return NULL;
	map<BinaryTreeNode *,bool> m;
	
	//insert all ancestors of n1 into  map
	while(n1!=NULL)
	{
		//inserting inside the map 
		m.insert(make_pair(n1,true)); //can also do m[n1] = true
 		n1 = n1->parent;
	}
	
	//checking if n2 or any of its ancestors is in map
	while(n2!=NULL)
	{
		if(m.find(n2) != m.end())
			return n2;
		
		
		n2 = n2->parent;
	}
	
	
	
} 
/*Time complexity = O(hlogh) , as maps are implemented using BST, so each of its operation such as insertion , deletion ,findind is
O(logh), and then we traverse the tree from bottom to root fashion fidning parents nodes. This method is efficient but it consumes some extra
memory & space due to involment of maps
*/


int main()
{
	struct BinaryTreeNode *root1=NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);


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
	r1->parent = root;
	r2->data = 3;
	r2->parent = root;
	
	r3->data = 4;
	r3->parent = r1;
	r4->data = 5;
	r4->parent = r1;
	
	r5->data = 6;
	r5->parent = r2;
	r6->data = 7;
	
	r6->parent = r2;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
	r5->left  = r6->left  = NULL;
	r5->right  = r6->right  = NULL;	
	
		
	cout<<FindLCAsimple(root,r5,r2);
	
	cout<<endl;
	
	
	cout<<FindLCAusingSingleTraversal(root1,2,7)->data;
	
	cout<<endl;
	
	cout<<findLCAParentPointer(r5,r6)->data;
	return 0;
}


