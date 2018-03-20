#include<iostream>

using namespace std;

//PROGRAM TO DELETE A NODE IN A BST-complicated



struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};




BSTnode *maxNode(BSTnode *root)
{
	if(!root) return NULL;
	
	
	if(root->right==NULL)
		return root;
		
	else return maxNode(root->right);
}


BSTnode* Min(BSTnode*root)
{
	if(!root)	return NULL;
	
	if(root->left==NULL)
		return root;
		
	else return Min(root->left);
}

//recursive implementation to delete a node
BSTnode *deleteNode(BSTnode *root,int value)
{
	BSTnode *temp;
	if(!root) return NULL;
	
	//first we need to search for the node to delete 
	
	if(root->data > value)
	{
		root->left  = deleteNode(root->left,value);
	}
	
	else if(root->data < value)
	{
		root->right = deleteNode(root->right,value);
	}
	
	else //when node is found
	{
		//case1- when the node to be deleted has both left and right children
		if(root->left && root->right)
		{
			//replace the nodes to be deleted data's with its inorder predecessor i.e largest in left subtree
			//or we can also replace the current root's data with its inorder successor-i.e smallest in right subtree
			temp = maxNode(root->left);
			
			//replacing data
			root->data  = temp->data;
			
			root->left = deleteNode(root->left,value);
			
		}
		
		//case 2- if the node to be deleted has only 1 child
		else
		{
			temp = root;
			
			if(root->left)
				root= root->left;
				
			if(root->right)
				root = root->right;
			
			delete temp;
		}
	}
	
	return root;
	
} //TIME COMPLEXITY = O(n), SPACE COMPLEXITY  = O(n) -recursion call stack




BSTnode* deleteNodeIterative(BSTnode *root,int value)
{
	if(!root) return NULL;
	BSTnode *temp;
	
	//first find the node to be deleted
	
	while(root)
	{
		if(root->data > value)
		{
			
			if(root->data == value)
			{
				if(root->left && root->right)
				{
					temp = maxNode(root->left);
				
					root->data = temp->data;
				
					root = root->left;
					
					
					
				}
				
				//if has only 1 child
			
				else
				{
					temp = root;
				
					if(root->left)
						root=root->left;
					
					if(root->right)
						root=root->right;
					
					delete temp;
					
				}
				
			}
			
			root = root->left;
		}
		
		
		if(root->data < value)
		{
			
			
			//if node to be deleted has both children
			if(root->data == value)
			{
				if(root->left && root->right)
				{
					temp = maxNode(root->left);
				
					root->data = temp->data;
				
					root = root->left;
					
					
					
				}
				
				//if has only 1 child
			
				else
				{
					temp = root;
				
					if(root->left)
						root=root->left;
					
					if(root->right)
						root=root->right;
					
					delete temp;
					
				}
				
			}
			
			root = root->right;
			
			
			
			
			
			
		}
	}
	
	
	return root;

}



BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


BSTnode *insert(BSTnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		BSTnode *temp  = new BSTnode();
		temp->data = value;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
	}
	
	
	
	//returning root of the updated tree
	return root;
}



void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	cout<<root->data<<" ";
	
	Inorder(root->right);
}


int main()
{
	
	BSTnode *root  = newNode(7);

	insert(root,3);
	insert(root,10);
	
	insert(root,12);
	insert(root,2);
	insert(root,1);
	
	Inorder(root);
	cout<<endl;
	
	//deleting node with key 10
	deleteNodeIterative(root,10);
	
	Inorder(root);
	
	
}
