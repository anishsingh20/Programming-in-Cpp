#include<iostream>



/*program to do insertion in an AVL tree. Similar to BST insertion with onlu caution that we check after every insertion
 for the appropiate rotation to be applied for balancing the tree.
 
 a)Recursive insertions
 Now the worst case time complexity will be O(logn) because, we keep the tree balanced via ROTATIONS.
 and space complexity becomes O(logn) as stack space consumed is proportional to the height of recursion tree which is logn for balanced binary search trees. 
 
 b) Iterative insertion- T(n) = O(logn), but space complexity is O(1) as no recursion is done
 
 */

using namespace std;

struct AVLnode {
	
	int data,height;
	struct AVLnode *left,*right;	
};


int Height(AVLnode *root)
{
	if(!root)
		return -1;
		
	else
		return max(Height(root->left),Height(root->right)) + 1;
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
	if(root)
	{
		InorderTraverse(root->left);
	
	cout<<root->data<<" ";
	
	InorderTraverse(root->right);
		
	}
	
}


void PreTraverse(AVLnode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		PreTraverse(root->left);
	
		
	
		PreTraverse(root->right);
		
	}
	
}


AVLnode *SingleleftRotation(AVLnode *X)
{
	//we have to make the left child of X as root say(W is the left child of X) and move X as right of W
	//then the right child of W should be made the left child of X
	//then make X as right child of W
	AVLnode *W = X->left;
	X->left = W->right;
	W->right  = X;
	
	X->height = max(Height(X->left),Height(X->right)) + 1;
	W->height  = max(Height(W->left), X->height) + 1;
	
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
	
	X->height = max(Height(X->left),Height(X->right)) + 1;
	W->height  = max(Height(W->right), X->height) + 1;
	
	return W;//new root
	
}


AVLnode *DoubleLeftRightRotation(AVLnode *X)
{

	X->left = SingleRightRotation(X->left);
	
	return SingleleftRotation(X); 
	
}

AVLnode *DoubleRightLeftRotation(AVLnode *X)
{
	X->right = SingleleftRotation(X->right);
	
	return SingleRightRotation(X);  

}


//insertion function while taking care of the balance factor and checking balance fator and doing appropiate rotations after every insertion
AVLnode *insert(AVLnode *root,AVLnode *parent,int value)
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
		root->left = insert(root->left,root,value);
		//after insertion check for imbalances and do appropiate rotations to balance the tree
		if( (Height(root->right)-Height(root->left)) == 2)
		{
			//when insertion in the right subtree of the left child of root
			if(root->left->data < value)
				root = DoubleLeftRightRotation(root);
				
			else
				root = SingleleftRotation(root);
				
		}
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,root,value);
		
		//after insertion check for imbalances and do appropiate rotations to balance the tree
		if( (Height(root->right)-Height(root->left)) ==2)
		{
			if(root->right->data < value)
				root = SingleRightRotation(root);
			
			//when insertion in the left subtree of the right child of root	
			else
				root = DoubleRightLeftRotation(root);
				
		}
	}
	
	//else data is in the tree already
	root->height = max(Height(root->left),Height(root->right)) + 1;
	
	//returning root of the updated tree
	return root;
}
//TIME COMPLEXITY = O(logn), Space complexity = proportional to height of tree which is equal to logn , so O(logn)




//Iterative insertion- Space efficient-O(1) Aux space
AVLnode *Insert(AVLnode *root,int key)
{
	AVLnode *temp = new AVLnode();//allocating memory
	temp->data = key;
	temp->height = 0 ;
	temp->left  = temp->right =NULL;
	
	if(root==NULL)
	{
		root = temp;
		
	}
	
	while(root)
	{
		
	
		if(root->data > key)
		{
			//if left is null, insert here
			if(root->left==NULL)
			{
				root->left = temp;
				break;
				
			}
			
			//check for unbalanced condition just after insertions
			if((Height(root->right)-Height(root->left)) == 2)
			{
				if(root->left->data < key)
				{
					root = DoubleLeftRightRotation(root);
				}
					
				else
				{
					root = SingleleftRotation(root);
				}
					
			}
			
			//otherwise simply traverse
			root = root->left;
		}
		
		
		//insertion in right subtree
		else if(root->data < key)
		{
			if(root->right==NULL)
			{
				root->right = temp;
				break;
			}
			
			
			//check for unbalanced condition just after insertions
			if((Height(root->right)-Height(root->left)) == 2) 
			{
				if(root->right->data > key)
				{
					root = DoubleRightLeftRotation(root);
				}	
						
				else 
					root = SingleRightRotation(root);
					
			}
			
			//otherwise simply traverse to the right
			root = root->right;
			
		}
	}
	
	root->height = max(Height(root->left),Height(root->right)) + 1;
	
	return root;	
}//Time complexity = O(logn) as tree is balanced via rotations. Constant Extra space consumed =  O(1)


//int main()
//{
//	AVLnode *root  = newNode(5);
//	
//	Insert(root,2);
//	Insert(root,3);
//	Insert(root,1);
//	Insert(root,7);
//	Insert(root,6);
//	Insert(root,12);
//	Insert(root,20);
//	Insert(root,10);
//	Insert(root,9);	
//	
//	//constructed the AVL tree
//	
//	InorderTraverse(root); //outputs a sorted list
//	cout<<endl;
//	PreTraverse(root);
//	
//}

