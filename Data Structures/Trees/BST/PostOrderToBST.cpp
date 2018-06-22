#include<iostream>
#include<stack>

/*if we want to construct a tree from given traversals-

then any one of the postorder or pre-order traversals are enough.

Method1)
1)Using a stack.-T(n) = o(n)
2)Using recursion T(n) = O(n)
*/

using namespace std;

struct node {
	int data;
	struct node *left,*right;
};


struct node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	
	return temp;
}



node *PostorderToBSTRecursion(int post[], int *postIndex,int key,int min,int max,int size)
{
	struct node *root=NULL;
	if(*postIndex >= size)
		return NULL;
		
	if(key > min && key < max)
 	{
		//make last item in postorder list as root
		root = newNode(key);
		
		*postIndex = *postIndex - 1; //decrementing the postIndex
	
	
		if( *postIndex < size )
		{
			
			
			//constructing the right subtree
			root->right = PostorderToBSTRecursion(post,postIndex,post[*postIndex],key,max,size);
			
			//constructing the left subtree.
			root->left = PostorderToBSTRecursion(post,postIndex,post[*postIndex],min,key,size);
			
			
			
		}
        }
        
        return root;
}


struct node *ConvertBSTPostorder(int post[],int size)
{
	int postIndex = size-1;//initially post index is last index
	
	return PostorderToBSTRecursion(post,&postIndex,post[size-1],INT_MIN,INT_MAX,size);
}



void Inorder(node *root)
{
	
	if(!root)
		return;
		
	
		Inorder(root->left);
	
		cout<<root->data<<" ";
	
		Inorder(root->right);
	
		
	
}


int main()
{
	int post[] = {1,7,5,50,40,10};
	
	struct node *root = ConvertBSTPostorder(post,sizePost);
	Inorder(root)

}
