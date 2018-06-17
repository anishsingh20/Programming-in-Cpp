#include<iostream>
#include<queue>

using namespace std;

struct node {
	int data;
	struct node *left,*right;
};

node* newNode(int item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}


//doing reverse inorder traversal and counting the nodes visited, until the count is less than K, we add up those current nodes.
int SumKLargestRecursion(node *root,int k)
{
	if(!root)
		return -1;
	
	static int sum=0;	
	static int count = 0;//count of visited nodes
	
	if(root->right)
		SumKLargestRecursion(root->right,k);
		
	if(++count <= k)
	{
		sum += root->data;
	}
	
	if(root->left)
		SumKLargestRecursion(root->left,k);
		
		
	return sum;
	
}//T(n) = O(n), space complexity = O(n) for implicit stack space(recursive stack)

int main()
{
	struct node *root = newNode(8);
	
	root->right = newNode(10);
	root->left = newNode(7);
	root->left->left = newNode(2);
	
	root->right->right = newNode(13);
	
	root->right->left = newNode(9);
	
	cout<<SumKLargestRecursion(root,2);
	
}
