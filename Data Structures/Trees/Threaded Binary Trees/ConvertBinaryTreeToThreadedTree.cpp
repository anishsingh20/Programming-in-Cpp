#include<iostream>
#include<queue>

/*PROGRAM TO CONVERT A BINARY TREE to THREADED BINARY TREE

METHOD-1)Using Queue-
We simply have to link the right NULL pointers to their inorder successors and make the tree threaded. Logic is to use a queue to store the inorder traversal nodes.
Then again do inorder traversal pop the node and check if its right is NULL, then simply connect its right pointer to the front of queue which has its inorder successor.
InEfficient technique as it cosumes O(n) extra memory due to usage of queue.
But can use MORRIS TRAVERSAL TO consume constant O(1) extra memory.

METHOD-2 ) Using inorder predecessors of current node and then creating a thread link from the predecessor to current node-Efficient solution as it consumes constant
extra memory.

*/


using namespace std;


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


Node *LeftMost(Node *root)
{
	//traverse till left most node
	while(root && root->left)
		root = root->left;
	
	return root;
}


//function to populate queue in in order-We can also use MORRIS TRAVERSAL TO DO EFFICIENT TRAVERSAL WITH O(1) constant extra space.
void PopulateQueueInInorder(Node *root, queue <Node *> *q)
{
	
	if(!root) return;
	//populate the map in inorder fashion
	
	//traverse to the left subtreee and left most node
	if(root->left)
		PopulateQueueInInorder(root->left,q);
	
	//now push in queue
	q->push(root);
	
	if(root->right)
		PopulateQueueInInorder(root->right,q);
}


//function to again do inorder traversal and connect all right NULl pointers to their inorder successors(if any)
void createThread(Node *root,queue<Node *> *q)
{
	if(!root) return ;
	Node *temp;
	if(root->left)
		createThread(root->left,q);
		
	//pop node from queue
//	temp = q->front();
	q->pop();
	
	if(root->right)
		createThread(root->right,q);
		
	//case when root does not has a right child, then link its right pointer to the front of queue which is its inorder successor	
	else
	{
		
		root->right = q->front();
		root->isThreaded= true;
	}
}



void createThreadedTree(Node *root)
{
	//populating the queue with inorder nodes
	queue<Node *> q;
	PopulateQueueInInorder(root,&q);
	
	//creating the threaded links
	createThread(root,&q);
}




//Method-2) using inorder predecessor of current node to connect its right pointer to the current node
Node *createThreadedPredecessor(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL) return root;
	
	//finding the predecessor node-if left is not NULL, we find the rightmost in the left subtree, or the left child itself
	if(root->left!=NULL)
	{
		//rightmost in left subtree is predecessor node
		Node *l = createThreadedPredecessor(root->left);
		
		//conecting right pointer of inorder predecessor of curr to current node
		l->right = root;
		l->isThreaded = true;
	}
	
	//if the right child of root is null, then return root;
	if(root->right==NULL)
		return root;
	
	//recur to the right subtree
	return createThreadedPredecessor(root->right);
}



//making a function to do inorder traversal for a threaded tree using threaded links
void InorderTraversal(Node *root)
{
	if(!root) return;
	
	//finding the left most node
	Node *curr = LeftMost(root);
	
	
	
	while(curr!=NULL)
	{
		//visit the left most
		cout<<curr->data<<" ";
		
		//if the threaded right link exists
		if(curr->isThreaded)
			curr = curr->right;//going to the inorder successor of current node via its right thread link
			
		else
		//find the inorder successor which is the leftmost in the right subtree
			curr = LeftMost(curr->right);
		
	}
	
}




Node *rightMost(Node *root)
{
	while(root && root->right)
		root= root->right;
		
	return root;
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
	
	
	//creating a threaded binary tree
//	createThreadedTree(root);

	createThreadedPredecessor(root);	
	
	
	InorderTraversal(root);
	
	

	
	
	
}

