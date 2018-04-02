#include<iostream>

using namespace std;

/*Program to find Minimum number of nodes in an AVL tree of height h i.e generating an MINIMAL AVL tree

We will utilize the recurrence relation
N(h) = 1+ N(h-1) + N(h-2)  are minimum number of nodes in an AVL tree of height h 
*/


struct AVLnode {

	int data;
	struct AVLnode *left,*right;
};



int count = 1;

//given height of AVL tree- generate minimal AVL tree i.e AVL tree with minimum number of nodes
AVLnode* GenerateMinimalAVL(int h)
{
	
	AVLnode *temp = new AVLnode();
	
	if( h == 0 ) return NULL;
		
	
	
	temp->left  = GenerateMinimalAVL(h-1);
	
	temp->data = count++;
	
	temp->right = GenerateMinimalAVL(h-2);
	
	return temp;
	
}


void Inorder(AVLnode *root)
{
	if(!root)
		return;
		
	Inorder(root->left);
	
	cout<<root->data<<" ";
	
	Inorder(root->right);
}


int main()
{
	struct AVLnode *root = GenerateMinimalAVL(2);
	
	Inorder(root);
	
	
	
}
