#include<iostream>

using namespace std;

/*Program to count the number of different BST poossible with 1...n keys = CATALAN NUMBER

This particular question is an application of CATALAN NUMBER.

*/


int CountBST(int n)
{
	if(n<=1)
		return 1;
		
	int sum=0;

	int root,left,right;
	for(root=0; root < n ; root++)
	{
		left = CountBST(root);
		right = CountBST(n-root-1);
		
		sum += left*right;
	}
	
	return sum;
}
//this program simply finds the nth catalan number recursively.

int main()
{
	cout<<CountBST(8);
}
