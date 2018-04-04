#include<iostream>
#include "InsertionInAVL.cpp"

using namespace std;



/*Program to count the number of nodes in an AVL tree in range [a,b].

1)Inorder traversal approach.
2)level order traversal approach
3) Efficient Morris Inorder approach which consumes conatant extra memory.
*/


int CountRange(AVLnode *root,int a,int b)
{
	static int count=0;//static count variable
	
	if(!root)
		return -1;
	
	//recursively count in left subtree	
	if(root->data >= a)
		 CountRange(root->left,a,b);
		 
	
	//if the data of current node lies in the range-simply increment count	
	if( a <= root->data && root->data <= b)
	{
		count++;
		
	}
	
	//recursively count in right subtree-don't return as we need to count
	if(root->data <= b)
		 CountRange(root->right,a,b);

	return count;
	
}




int main()
{



	AVLnode *root  = newNode(5);
	
	Insert(root,2);
	Insert(root,3);
	Insert(root,1);
	Insert(root,7);
	Insert(root,6);
	Insert(root,12);
	Insert(root,20);
	Insert(root,10);
	Insert(root,9);	
	
	cout<<CountRange(root,5,10);

}

