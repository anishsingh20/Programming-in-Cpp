#include<iostream>


/* Program to convert a sorted Array to a BST-

ALgorithm-
1) Get the middle of the array and make it as root node.
2)Recursively do the same for left and right half.
	2.1)Get the middle of left half and make it left child of root
	2.2)Get the middle of right half and make it right child of root.

*/

using namespace std;


struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};




int main()
{
	
}
