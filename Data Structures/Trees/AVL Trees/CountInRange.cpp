#include<iostream>
#include "InsertionInAVL.cpp"

using namespace std;



/*Program to count the number of nodes in an AVL tree in range [a,b].

1)Inorder traversal approach.
2)level order traversal approach
3) Efficient Morris Inorder approach which consumes conatant extra memory.
*/


int CountRange(AVLnode *root,int a,int b)
{
	static int count=0;//static count variable
	
	if(!root)
		return -1;
	
	//recursively count in left subtree	
	if(root->data >= a)
		 CountRange(root->left,a,b);
		 
	
	//if the data of current node lies in the range-simply increment count	
	if( a <= root->data && root->data <= b)
	{
		count++;
		
	}
	
	//recursively count in right subtree-don't return as we need to count
	if(root->data <= b)
		 CountRange(root->right,a,b);

	return count;
	
}


//Morris traversal to do Inorder traversal with constant extra memory
int CountRangeMorris(AVLnode *root,int a,int b)
{
	AVLnode *curr = root;
	if(!root)
		return -1;
		
	int count = 0;
	
	while(curr)
	{
		if(curr->left==NULL)
		{
			//count if current's data lies in range
			if( a <= curr->data && curr->data <= b)
				count++;
				
			curr = curr->right;
		}
		
		
		else
		{
			//finding inorder predecessor- it is the rightmost in left subtree or left child iteself
			AVLnode *pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;
				
			if(pre->right==NULL)
			{
				pre->right = curr;
				
				curr = curr->left;
				
			}
			
			else
			{
				pre->right = NULL;
				
				if(a <= curr->data && curr->data <= b)
					count++;
					
					
				curr = curr->right;
				
				
			}
		}
	}
	
	
	return count;
}


int main()
{



	AVLnode *root  = newNode(5);
	
	Insert(root,2);
	Insert(root,3);
	Insert(root,1);
	Insert(root,7);
	Insert(root,6);
	Insert(root,12);
	Insert(root,20);
	Insert(root,10);
	Insert(root,9);	
	
	cout<<CountRange(root,5,10);
	
	cout<<endl;
	
	cout<<CountRangeMorris(root,5,10);

}

