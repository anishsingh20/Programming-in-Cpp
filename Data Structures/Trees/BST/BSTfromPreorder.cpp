#include<iostream>
#include<stack>

/*if we want to construct a tree from given traversals-

then any one of the postorder or pre-order traversals are enough.

Method1)
1)Using a stack
*/

struct node {
	int data;
	struct node *left,*right;
};


struct node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	
	return temp;
}

node *PreorderToBSTStack(int pre[],int size)
{
	//first element in preorder is the root of tree
	node *root = newNode(pre[0]);
	
	stack<node *>s(size); //creating a stack
	
	s.push(root);
	
	struct node *temp;
	
	for(int i=1; i < size ; i++ )
	{
		temp = NULL;
		while(!s.empty() && pre[i] > s.top())
		{
			temp = s.top();
			s.pop()
			
		}
		
		//if the node in pre list is  > top of stack,make it the right of top node in stack
		if(temp!=NULL)
		{
			
			temp->right = newNode(pre[i]);
			s.push(temp->right);	
		}	
		
		//otherwise make it the left child and push it to stack
		else
		{
			(s.top())->left = newNode(pre[i]);
			s.push((s.top())->left);
			
		}	
	}

	return root;

}


void Inorder(node *root)
{
	Inorder(root->left);
	
	cout<<root->data;
	
	Inorder(root->right);
}


int main()
{
	return 0;
}
