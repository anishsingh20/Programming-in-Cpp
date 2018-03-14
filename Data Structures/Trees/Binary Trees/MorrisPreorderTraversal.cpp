#include<iostream>

using namespace std;


//Program to do Pre-order traversal using MORRIS TRAVERSAL



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


void MorrisPreTraversal(Node *root)
{
	if(!root) return;
	
	Node *curr,*pre;
	
	curr = root;
	
	while(curr!=NULL)
	{
		//if current has nor left child, then visit it and move to right child of current
		if(curr->left==NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->right;
		}
		
		else
		{
			//finding the rightmost node in currents left subtree i.e finding current node's inorder predecessor
			
			pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;
			
			//if the right link of predecessor node is NULL-then we connect its right link to current node i.e make it threaded 
			if(pre->right==NULL)
			{
				pre->right=curr;
				
				//visit the current node to preserve preorder's property
				cout<<curr->data<<" ";
				
				//now move to the left
				curr = curr->left;
			}
			
			//if predecessor right link is not NULL i.e to move back to the current node i.e the inorder successor of predecessor node
			else
			{
				pre->right=NULL;
				
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
	
	MorrisPreTraversal(root);


	
}

