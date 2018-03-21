#include<iostream>

using namespace std;


/*PRogram to convert a sorted linked list to a Binary Search tree-

1)Method-1 )Similar to the array version-1)Find middle node of list and make it as root
					 2) Recursively do the same for left and right half of list.
					 	2.1)left child is the middle node in lower half of list
						2.2)right child is the middle node in upper half of list			

*/
