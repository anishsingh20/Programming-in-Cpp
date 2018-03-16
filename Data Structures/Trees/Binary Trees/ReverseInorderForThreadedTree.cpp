#include<iostream>
#include<queue>

using namespace std;


/*Reverse Inorder traversal for a threaded binary tree using predecessor threads, where each node with left NULL pointers point to their inorder predecessors.

We simply have to link the left NULL pointers to their inorder predecessors and make the tree threaded. Logic is to use a queue to store the reverse inorder traversal nodes.
Then again do inorder reverse traversal, pop from queue and then check is current's node left is NULL, then simply connect its left NULL pointer to the front of queue which
has its inorder predecessor node.
InEfficient technique as it cosumes O(n) extra memory due to usage of queue.
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
	
	return temp;
}


Node *rightMost(Node *root)
{
	while(root && root->right!=NULL)
		root = root->right;
		
	return root;
}


void PopulateQueueReverseInorder(Node *root, queue <Node *> *q)
{
	
	if(!root) return;
	//populate the map in inorder fashion
	
	//traverse to the right subtreee and right most node
	if(root->right)
		PopulateQueueReverseInorder(root->right,q);
	
	//now push in queue
	q->push(root);
	
	if(root->left)
		PopulateQueueReverseInorder(root->left,q);
}


//function to again do reverse inorder traversal and connect all left NULl pointers to their inorder pre-decessor(if any)
void createThread(Node *root,queue<Node *> *q)
{
	if(!root) return ;
	if(root->right)
		createThread(root->right,q);
		
	//pop node from queue
	q->pop();
	
	if(root->left)
		createThread(root->left,q);
		
	//case when root does not has a left child, then link its left pointer to the front of queue which is its inorder predecessor	
	else
	{
		root->left = q->front();
		root->isThreaded= true;
	}
}



void createThreadedTree(Node *root)
{
	//populating the queue with inorder nodes
	queue<Node *> q;
	PopulateQueueReverseInorder(root,&q);
	
	//creating the threaded links
	createThread(root,&q);
}



//Method-2) using inorder successor of current node to connect its left null pointer to the current node
Node *createThreadedSuccessor(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL) return root;
	
	//finding the successor node-if right is not NULL, we find the leftmost in the right subtree, or the right child itself
	if(root->right!=NULL)
	{
		//inorder successor is the left most in right subtree
		Node *r = createThreadedSuccessor(root->right);
		
		//conecting left pointer of inorder successor of curr to current node
		r->left = root;
		r->isThreaded = true;
	}
	
	//if the right child of root is null, then return root;
	if(root->left==NULL)
		return root;
	
	//recur to the right subtree
	return createThreadedSuccessor(root->left);
}


void ReverseInorder(Node *root)
{
	if(!root) return;
	
	//finding the right most node in tree-as it is the first one to be visited
	Node *curr = rightMost(root);
	
	while(curr != NULL)
	{
		cout<<curr->data<<" ";
		
		//if the left thread exists i.e curr has its left pointing to its inorder predecessor
		if(curr->isThreaded)
			curr = curr->left;//going to the predecessor of current node via its left predecessor link
		
		//otherwise simply find the righrtmost in the left subtree	
		else
		{
			//move to the predecessor of current
			//predecessor is the right most child of left subtree
			curr  = rightMost(curr->left);
		}
		
		
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
	
//	createThreadedSuccessor(root);
	
	createThreadedTree(root);
		
	cout<<"Reverse inorder traversal is:"<<endl;
	ReverseInorder(root);
	
	
}
