#include<iostream>


/* Program to convert a sorted Array to a BST-

ALgorithm-
1) Get the middle of the array and make it as root node.
2)Recursively do the same for left and right half.
	2.1)Get the middle of left half and make it left child of root
	2.2)Get the middle of right half and make it right child of root.
	
T(n)  = 2T(n/2) + O(1) is the recurrence relation for the above recursive problem as it is an DECREASE AND CONQUER TECHNIQUE similar 
to Binary Search.

*/

using namespace std;





struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}

//recursive function to convert a sorted array to a BST
BSTnode *ArrayToBST(int *arr,int start,int end)
{
	//base condition where recursion terminates
	if(start > end)
		return NULL;
		
	
	//finding middle index		
	int mid = start + (end-start)/2;
	
	//making middle element as root
	BSTnode *root = newNode(arr[mid]);
	
	
	//recursively go to left and right halves of array and repeat the same procedure
	
	//left child is the middle of left half of array
	root->left = ArrayToBST(arr,start,mid-1); //T(n/2)
	
	//right child is the middle of higher half of array
	root->right = ArrayToBST(arr,mid+1,end);// T(n/2)
	
	//return the root.
	return root;
	
}//TIME COMPLEXITY = O(n), and the recurrence relation is T(n)  = 2T(n/2) + O(1)(for calculating the middle index)
 


void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	
	cout<<root->data<<" ";
	
	Inorder(root->right);
}



int main()
{

	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
//	BSTnode *root = ArrayToBST(arr,0,size-1);
	BSTnode *root = ArrayToBST(arr,0,size-1);
	
	Inorder(root);
	
}
