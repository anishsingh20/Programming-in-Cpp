#include<iostream>
#include<queue>

//Program to search for a node in Binary tree
using namespace std;

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


//Revirsive implementation
bool FindNode(struct BinaryTreeNode *root, int data)
{
//	bool temp;
//	if(root!=NULL)
//	{
		//if data present at root
//		if(data==root->data)
//		{
//			return true;
//		}
//		else
//		{
//			temp =  FindNode(root->left,data);
//			if(temp) return temp;
//			
//			//otherwise search in right subtree
//			else return FindNode(root->right,data);
//		}	
//	}
//	
//	else
//		return false;

//Method2- 

	if(root==NULL) return false;
	
	/// If key is present at root, or in left subtree or right subtree,
    // return true;
	if(root->data==data || FindNode(root->left,data) || FindNode(root->right,data))
		return true;
		
	else return false;
}



//Non recursive implementation using level order traversal technique-BFS

bool FindInTreeUsingLevelOrder(struct BinaryTreeNode *root, int data)
{
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	
	if(!root) return false;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(data == temp->data) return true;
		
		//pushing the child nodes in queue
		if(temp->left) 
		{
			q.push(temp->left);
		}
		
		if(temp->right)
		{
			q.push(temp->right);
			
		} 
	}
	
	//if queue gets empty and data is not found
	return false;
	
	 
}

int main()
{
	struct BinaryTreeNode *root = new BinaryTreeNode();
	struct BinaryTreeNode *r1 = new BinaryTreeNode();
	struct BinaryTreeNode *r2 = new BinaryTreeNode();
	struct BinaryTreeNode *r3 = new BinaryTreeNode();
	struct BinaryTreeNode *r4 = new BinaryTreeNode();
	struct BinaryTreeNode *r5 = new BinaryTreeNode();
	struct BinaryTreeNode *r6 = new BinaryTreeNode();	
	
	root->data = 1;
	r1->data = 2;
	r2->data = 3;
	r3->data = 4;
	r4->data = 10;
	r5->data = 6;
	r6->data = 7;
	
	root->left  = r1;
	root->right = r2;
	
	r1->left = r3;
	r1->right = r4;
	
	r2->left = r5;
	r2->right = r6;
	
//	if(FindInTreeUsingLevelOrder(root,100))
//	{
//		cout<<"Found"<<endl;
//	}
//	else
//	{
//		cout<<"Not found"<<endl;
//	}

	//boolalpha is a manipulator
//	cout.setf(ios::boolalpha); - to set the flag
	cout<<boolalpha<<FindNode(root,7);
	return 0;
}
