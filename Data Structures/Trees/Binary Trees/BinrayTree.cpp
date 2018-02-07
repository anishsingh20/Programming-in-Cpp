#include<iostream>
#include<stack>
#include<queue>

//IMPLEMENTATION OF A BINARY TREE- a tree which can have atmost i.e <= 2 child nodes

using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

     
/*TRAVERSING A BT-
1)PREORDER - a) visit the root node b)traverse the left subtree in preorder c) visit the right subtree in preorder

2)INORDER - a) Traverse to the left subtree in Inorder  b) visit the root node c) traverse to the right subtree in inorder

3)POSTORDER-a) Traverse to the left subtree in postorder  b) traverse to the right subtree in postorder c) visit the root node 

4) Level order traversal - BFS -breadth first search
*/   
     
     
//RECURSIVE IMPLEMENTATION-

void PreOrderRec(struct BinaryTreeNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		PreOrderRec(root->left);
		PreOrderRec(root->right);
	}
	
	
}


//non recursive implementation using a stack
void PreOrder(struct BinaryTreeNode *root)
{
	stack <BinaryTreeNode*>s;
	
	while(1)
	{
		while(root)
		{
			//visit current node
			cout<<root->data<<" ";
		
			s.push(root);
			
			//if left subtree exits then add it to stack
			root = root->left;
		}
		
		
	if(s.empty()) break; 
	
	//now we have traversed the left subtree and current node
	//pop from stack
	root = s.top();
	s.pop();
	
	root = root->right;
	
	}
}



void InOrderRec(struct BinaryTreeNode *root)
{
	if(root)
	{
		InOrderRec(root->left);
		cout<<root->data<<" ";
		InOrderRec(root->right);
	}	
}

/*non-recursive inorder traversal using a stack
The only change is, instead
of processing the node before going to left subtree, process it after popping (which is indicated
after completion of left subtree processing).
*/
void InOrder(struct BinaryTreeNode *root)
{
	//a stack to store the nodes
	stack <BinaryTreeNode*>s1;
	
	while(1)
	{
		while(root)
		{
			//if left subtree exits then add it to stack
			//traverse to the left subtree in InOrder
			s1.push(root);
			root = root->left;
			
		}
		
		
		
	if(s1.empty() ) 
		break; 
	
	//now we have traversed the left subtree 
	//pop from stack
	root = s1.top();
	s1.pop();
	
	//now simply visit the current node
	cout<<root->data<<" ";
	
	//now traverse the right subtree in Inorder
	root = root->right;
	
	}
}




void PostOrderRec(struct BinaryTreeNode *root)
{
	if(root)
	{
		PostOrderRec(root->left);
		PostOrderRec(root->right);
		cout<<root->data<<" ";
	}
	
}

//non recursive implementation of POSTORDER-bit complicated as we visit a root node twice in POSTORDER
void PostOrder(struct BinaryTreeNode *root)
{
	 struct BinaryTreeNode *prev = NULL;
	 stack<BinaryTreeNode *> s;
	 do
	 {
	 	//traversing the left subtree and pushing the nodes in left subtree to stack
		 while(root!=NULL)
		 {
		 	s.push(root);
		 	
		 	//traverse the left subtree
		 	root = root->left;
		 }
		 
		 //when left subtree has benn completely traversed,
		 while( root==NULL && !s.empty())
		 {
		 	root = s.top(); //root is the top node in stack
			//case when we enter if it is a leaf node , or when prev is the right child of current root
			if(root->right==NULL || root->right == prev)
			{
				//visit the node
				cout<<root->data<<" ";
				s.pop(); 
				prev = root;
				root=NULL;
			}
			
			//traverse the right subtree, if not leaf
			else
			{
				root = root->right;
				
			}  
		 	
		 }
		 
	} while(!s.empty());
	
}



 //In level order we will use a queue to store the level+1 nodes in queue    
void levelOrder(struct BinaryTreeNode *root)
{
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *>q;
	
	if(!root) return;
	
	q.push(root);//push the root into queue
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		cout<<temp->data<<" ";
		
		//pushing temp's left and right child if any to queue
		//we will keep (level+1) children in the queue
		if(temp->left)
		{
			q.push(temp->left);
		}
		
		if(temp->right)
		{
			q.push(temp->right);
		}
	}
}     //TIME COMPLEXITY = O(n) , SPACE COMPLEXITY = O(n)
     
     
     
int main()
{
	
	//generating a full binary tree -  n(no of nodes) = 2^(h+1) -1 , h = height of tree
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
	
	
	cout<<"Pre order traversal outputs-"<<endl;
	PreOrder(root);
	
	cout<<endl;
	
	cout<<"In order traversal outputs-"<<endl;
	InOrder(root);
	
	cout<<endl;
	
	cout<<"Post order traversal outputs-"<<endl;
	PostOrderRec(root);
	
	cout<<endl;
	
	cout<<"Post order traversal outputs-"<<endl;
	PostOrder(root);
	
	cout<<endl;
	
	cout<<"Level order traversal-"<<endl;
	
	levelOrder(root);
	

	
	
	return 0;
}


