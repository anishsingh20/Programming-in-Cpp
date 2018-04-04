#include<iostream>

using namespace std;

/*Program to find number of different structured minimal AVL trees i,e AVL tree with minimum nodes.

We know to find minimum no nodes in an AVL tree is given by N(h) = 1 + N(h-1) + N(h-2).

In simialr manner number of different minimal AVL trees is given by the below recurrence relation

NT(h) = 2*NT(h-1)*NT(h-2) , NT(h) are no of Minimal AVL trees possible

*/

struct AVLnode{
	int data;
	AVLnode *left,*right;
};

long long int numMinimalAVLTrees(int h)
{
	//base cases - if height = 0 , only one node -root
	if(h==-1)
		return 0;
		
		
	if(h==0 || h==1)
		return h+1;
	
	//if height is 1-then 2 diff AVL trees possible	
	
		
	else
	{
		long long int left = numMinimalAVLTrees(h-1);
		long long int right = numMinimalAVLTrees(h-2);
		return 2*left*right;
	}
		
	
}//Time complexity = O(2^h)-exponential time algorithm, Space  = O(h) i.e proportional to recursion tree's height



/*
Maximal AVL trees possible given height- MAximal AVL trees are nothing but FULL BST i.e a BALANCED BST , where each node has 
balance factor = 0  i.e equal no of left and equal no of right child or same heights of left and right subtree.
*/
long long int numMaximalAVLTrees(int h)
{
	//base cases - if height = 0 , only one node -root
	if(h==-1)
		return 0;
		
		
	if(h==0 || h==1)
		return h+1;
	
	//if height is 1-then 2 diff AVL trees possible	
	
		
	else
	{
		//storing result in a var to avoid redundant calls
		long long int num =  numMinimalAVLTrees(h-1);
		return 2*num*num;
		
	}
		
	
}//Time complexity = O(2^h)-exponential time algorithm, Space  = O(h) i.e proportional to recursion tree's height




int main()
{
	cout<<"Number of minimal AVL trees possible are :";
	cout<<endl;
	cout<<numMinimalAVLTrees(4);
	cout<<endl;
	
	cout<<"Number of maximal AVL trees possible are :";
	cout<<endl;
	cout<<numMaximalAVLTrees(4);
	
}
