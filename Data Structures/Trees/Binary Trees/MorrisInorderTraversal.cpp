#include<iostream>

using namespace std;

//PROGRAM TO DO INORDER TRAVERSAL WITHOUT USING A STACK AND WITHOUT RECURSION - using MORRIS TRAVERSAL-

//MORRIS traversal is based on threaded binary trees


struct Node {
	
	int data;
	Node *left,*right;

};

Node *newNode(int data){
	Node *temp = new Node;
	
	temp->data = data;
	temp->right=temp->left=NULL;

	
	return temp;
}

Node *rightMost(Node *root)
{
	if(!root) return NULL;
	
	if(root->left==NULL && root->right==NULL)
		return root;
		
	rightMost(root->right);
}


Node* leftMost(Node *root)
{
	
	//recursive solutuion
	if(!root) return NULL;
	
	//when left most leaf is found
	if(root->left==NULL && root->right==NULL)
		return root;
	
	//otherwise simply recur to the left subtree of each node
	leftMost(root->left);
}


Node *Predecessor(Node *root)
{
	if(!root) return NULL;
	
	Node *pre = root->left;
	
	
	
	while(pre->right!=NULL && pre->right!=root)
		pre=pre->right;
	

		
		
		
			
	return pre;
	
	
}

void MorrisTraversal(Node *root)
{
	Node *curr,*pre;
	
	if(!root) return ;
	
	curr=root;
	
	while(curr!=NULL)
	{
		//if curr has no left child , then simply visit it
		if(curr->left==NULL)
		{
			cout<<curr->data<<" ";
			
			curr=curr->right;
		}
		
		
		else
		{
			//finding the inorder predecessor of current node
			pre = curr->left;
			
		//finding the right most child in the left subtree which is the inorder predecessor of current
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;

		/*make current as right child of its inorder predecessor
			Make current as right child of the rightmost 
         		node in current's left subtree*/
				if(pre->right==NULL)
				{
					//making link between current and it's inorder succesors right link
					pre->right = curr;
					
					//go to the left child
					curr= curr->left;
					
				}
				
				
				//revert back the changes made in the tree
				
				else
				{
					pre->right=NULL;
					
					cout<<curr->data<<" ";
					
					curr = curr->right;
					
				}		
			
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
	
	MorrisTraversal(root);


	
}

