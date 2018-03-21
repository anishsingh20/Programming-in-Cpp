#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;


/* Program to convert a Binary tree to a BST-
Algorithm-
1)While doing inorder traversal of the tree copy items in an temporary container-say array,set or vector.
2)Now sort the container- we can use Quick sort or merge sort for better time complexity and efficiency.
3)Now again do inorder traversal of the tree and copy each item one by one from sorted container to the tree.

We do inorder traversal becasue we know INORDER TRAVERSAL OF A BST GIVES US A SORTED LIST

The final resulting tree would be a BST. 


*/

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


/*helper function needed
1) TO copy nodes while doing inorder traversal to an array.
2)Sorting the array.
3) Again a method to copy array items back to the tree while doing inorder treaversal.
*/


//method to copy tree nodes to array
void TreetoArray(BSTnode *root, int arr[],int *index)
{
	if(!root) return;
	
	//first treverse to the left subtree
	TreetoArray(root->left,arr,index);
	
	//pushing contents of inorder traversal to vector/array
	arr[*index] = root->data;
	(*index)++;
	
	TreetoArray(root->right,arr,index);	
}


//helper function to copy array items one by one to the binary tree while doing inorder traversal which makes a BST
void arrayToTree(int *arr,BSTnode *root,int *index)
{
	if(!root) return;
	
	arrayToTree(arr,root->left,index);
	
	root->data = arr[*index];
	(*index)++;
	
	arrayToTree(arr,root->right,index);
	
}


int countNodes(BSTnode *root)
{
	if(!root)	return 0;
	
	else return (countNodes(root->left)  + countNodes(root->right) + 1);
}





//Quick sort to sort the array
int Partition(int arr[],int start,int end)
{
	//initially pindex is 0 index
	int pindex = 0;
	
	//pivot element is last
	int Pivot = arr[end];
	
	for(int i = 0 ; i < end; i++ )
	{
		if(arr[i] < Pivot )
		{
			swap(arr[i],arr[pindex]);
			pindex++;
		}
	}
	
	swap(arr[pindex],arr[end]);
	
	
	
	//returning the partition index
	return pindex;
}



//randomized version of quick sort which chooses a random element as Pivot element, not the last element. This ensures that
//the probability of O(nlogn) is highest i.e in worst case too(when array is already sorted) it gives O(nlogn) as time compexity.
int RandomizedPartition(int *arr,int start, int end)
{
	int range = (end - start + 1);
	int pindex = start + rand() % range;
	
	swap(arr[pindex],arr[end]);
	
	return Partition(arr,start,end);
}

void Qsort(int *arr,int start,int end)
{
	if(start < end)
	{
		//finding the partition index
		int pindex = RandomizedPartition(arr,start,end);
		
		//recursively call Qsort of left half of Pivot
		Qsort(arr,start,pindex-1);
		
		//recursively call Qsort on right half of Pivot
		Qsort(arr,pindex+1,end);
	}
}//TIME COMPLEXITY = O(nlogn)


void BinaryTreeToBST(BSTnode *root)
{

	int size = countNodes(root);
	
	int *arr = new int[size];
	int i=0;
	
	//copying the inorder traversal nodes to an vector/array
	TreetoArray(root, arr, &i);
	
	//sorting the array
	Qsort(arr,0,size-1);
	
	
	//now copying array elements one by one to the inorder traversal
	i = 0;
	arrayToTree(arr,root,&i);
	
	
	delete [] arr;

	
       
}


BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


void Inorder(BSTnode *root)
{
	if(!root)	return;
	
	Inorder(root->left);
	
	cout<<root->data<<" ";
	
	Inorder(root->right);
}

int main()
{
	BSTnode *root=newNode(5);

	root->left = newNode(7);
	root->right = newNode(9);
	root->right->left = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(11);
	

	cout<<"Inorder traversal of the binary tree: "<<endl;
	Inorder(root);
	
	cout<<endl;
	cout<<endl;
	cout<<"Converting Binary tree to BST :"<<endl;
	cout<<endl;
	BinaryTreeToBST(root);
	
	
	cout<<"Inorder traversal of BST is a sorted list :"<<endl;
	
	Inorder(root);
	
	
	
}
