#include<iostream>



//program to do insertion in an AVL tree. Similar to BST insertion with onlu caution that we check after every insertion
// for the appropiate rotation to be applied for balancing the tree.

using namespace std;

//struct AVLnode {
//	
//	int data,height;
//	struct AVLnode *left,*right;	
//};


AVLnode *insert(AVLnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		AVLnode *temp  = new AVLnode();
		temp->data = value;
		temp->height = 0;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	//insetion in left subtree
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
		//after insertion check for imbalances and do appropiate rotations to balance the tree
		if(height(root->right)-height(root->left)==2)
		{
			if(root->left->data < value)
				root = DoubleLeftRightRotation(root);
				
			else
				root = SingleleftRotation(root);
				
		}
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
		
		//after insertion check for imbalances and do appropiate rotations to balance the tree
		if(height(root->right)-height(root->left)==2)
		{
			if(root->right->data < value)
				root = DoubleRightLeftRotation(root);
				
			else
				root = SingleRightRotation(root);
				
		}
	}
	
	
	
	//returning root of the updated tree
	return root;
}


AVLnode *newNode(int data)
{
	AVLnode *temp = new AVLnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}

void InorderTraverse(AVLnode *root)
{
	InorderTraverse(root->left);
	
	cout<<root->data<<" ";
	
	InorderTraverse(root->right);
}



AVLnode *SingleleftRotation(AVLnode *X)
{
	//we have to make the left child of X as root say(W is the left child of X) and move X as right of W
	//then the right child of W should be made the left child of X
	//then make X as right child of W
	AVLnode *W = X->left;
	X->left = W->right;
	W->right  = X;
	
	X->height = max(height(X->left),height(X->right)) + 1;
	W->height  = max(height(W->left), X->height) + 1;
	
	return W;//new root
	
}



AVLnode *SingleRightRotation(AVLnode *X)
{
	//we have to make the right child of X as root say(W is the right child of X) and move X to left of W
	//then the left child of W should be made the right child of X
	//then make X as left child of W
	AVLnode *W = X->right;
	X->right = W->left;
	W->left  = X;
	
	X->height = max(height(X->left),height(X->right)) + 1;
	W->height  = max(height(W->right), X->height) + 1;
	
	return W;//new root
	
}


AVLnode *DoubleLeftRightRotation(AVLnode *X)
{

	X->left = SingleRightRotation(X->left);
	
	return SingleLeftRotation(X); 
	
}

AVLnode *DoubleRightLeftRotation(AVLnode *X)
{
	X->right = S::SingleLeftRotation(X->right);
	
	return N::SingleRightRotation(X);  

}
int main()
{
	AVLnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);
	
	InorderTraversal(root);
	
	
}

