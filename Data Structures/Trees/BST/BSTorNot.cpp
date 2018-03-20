#include<iostream>

using namespace std;

/*PROGRAM TO CHECK IF A GIVEN BINARY TREE IS BST OR NOT-
	
Idea is to do something similar to inorder traversal-
Methdod-1
1)We check if the current node's key is larger than it's inorder predecessor i.e the maximum in left subtree.
2)We check if the current node's key is smaller than its inorder successor- i.e minimum in right subtree.
3)We check the above 2 conditions recursively for the left and right subtrees and true , then it is a BST
	
*/
int main()
{
	
}
