#include<iostream>
#include<queue>

using namespace std;

/*PROGRAM TO CONVERT A BINARY TREE TO A PRE-DECESSOR THREADED BINARY TREE.

A predecessor threaded binary tree is a type of threaded tree in which the left NULL pointers point to their inorder predecessors.
This type of threaded tree is used in reverse inorder traversal and postorder traversal too.

2 Methods-1) Using queue to store the reverse of inorder traversal-consumes extra space
	  2) Using inorder successor link to the curent node-more efficient

*/

struct Node {
	
	int data;
	Node *left,*right;
	bool isThreaded;
};


Node *newNode(int data){
	Node *temp = new Node;
	
	temp->data = data;
	temp->right=temp->left=NULL;
	temp->isThreaded=false;
	
	return temp;
}

//method to conver a binary tree to predecessor threaded tree-using the fact that we link from inorder successors to the current node

Node *ConvertPredecessorThreaded(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
	
	//now finding the inorder successor of current root-left most in right subtree, or right child itself	
	if(root->right!=NULL)
	{
		Node *r = ConvertPredecessorThreaded(root->right);
		
		r->left = root;//making the left link of inorder successor of current point to current node i.e creating a predecessor thread
		r->isThreaded = true;
	}
	
	//if left is null return root
	if(root->left==NULL)
		return root;
		
	return ConvertPredecessorThreaded(root->left);
}


//Method-1 Using a queue

void PopulateQueue(Node *root, queue <Node*> *q )
{
	//storing the reverse inorder traverasl in queue-recur to Right subtree, visit current, recur to left subtree
	if(!root) return;
	
	if(root->right)
		PopulateQueue(root->right,q);
	
	q->push(root);
	
	
	if(root->left)
		PopulateQueue(root->left,q);
}


void ConvertThreadedUtil(Node *root,queue <Node*> *q)
{
	//again doing reverse inorder traversal, and popping from queue
	//connecting the left null pointers to the front of queue i.e its inorder predecessor
	
	if(!root) return; 
	
	
	if(root->right)
		ConvertThreadedUtil(root->right,q);
	
	
	q->pop();
	
	
	
	if(root->left)
		ConvertThreadedUtil(root->left,q);
		
	
	//othersise if left is null, then connect left null pointer to the front of queue which is current node's inorder predecessor
	else
	{
		root->left = q->front();
		root->isThreaded=true;
	}
		
}



//main function to populate the queue in reverse inorder and create left predecessor thread links
void PredecessorThreaded(Node *root)
{
	
	//populating the map
	queue<Node*>q;
	
	PopulateQueue(root,&q);
	
	//creating predecessor threads
	
	ConvertThreadedUtil(root,&q);
}






//function to find the right most node in a tree
Node *RightMost(Node *root)
{
	while(root && root->right)
		root=root->right;
		
	return root;
}

//function to do reverse inorder traversal using the predecessor threaded tree
void ReverseInorder(Node *root)
{
	if(!root) return;
	Node *curr = RightMost(root);
	
	while(curr!=NULL)
	{
		//visit the rightmost node
		cout<<curr->data<<" ";
		
		//if left predecessor thread exists
		if(curr->isThreaded)
			curr=curr->left;
			
		//otehrwise find the rightmost in the left subtree, to find the inorder predecessor
		else
			curr = RightMost(curr->left);
			
	}
}



int main()
{
	
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(7);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	
//	ConvertPredecessorThreaded(root);

	PredecessorThreaded(root);
	
	ReverseInorder(root);
	
	
	
	
}
