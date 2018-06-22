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


node *BSTfromPostorderStack(int post[],int size)
{	

 	stack<node*>s;

	node *root =  newNode(post[size-1]);//last node of the traversal is root
	
	node *temp;
	s.push(root);
	int i = size-2 ;
	while(i>=0)
	{
	    while(!s.empty() && post[i] < s.top()->data)
	    {
	        temp = s.top();
	
	        s.pop();
	    }
	    
	    //right child of current root
	    if(temp!=NULL)
	    {
	        temp->left = newNode(post[i]);
	        s.push(temp->left);
	    }
	    
	    //left subtree
	    else
	    {
	        (s.top())->right = newNode(post[i]);
	        s.push( (s.top())->right);
	    }
	    
	    i--;
	    
	}
	
	
	
		return root;

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
	
	
		if( *postIndex >= 0 )
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
	
	return PostorderToBSTRecursion(post,&postIndex,post[postIndex],INT_MIN,INT_MAX,size);
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
	int post[] = {1, 7, 5, 50, 40, 10};
	int sizePost = (sizeof(post)/sizeof(post[0]));
	
	struct node *root = ConvertBSTPostorder(post,sizePost);
	Inorder(root);
	cout<<endl;
		
//	struct node *root1 = ConvertBSTPostorder(post,sizePost);
//	Inorder(root1);


}
