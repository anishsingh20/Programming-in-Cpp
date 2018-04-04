#include<iostream>
#include "InsertionInAVL.cpp"
#include<queue>

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
	
}//Time complexity  = O(logn), Space  = O(logn) stack space consumed, as the tree is balanced


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
}//Time compelxity = O(logn) , Space = O(1) constant memory consumed



//method-3 )using level order traversal

int CountRangeLevelOrder(AVLnode *root,int a,int b)
{
	queue<AVLnode *> q;
	int count=0;
	
	AVLnode *temp;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->data <= b && temp->data >= a)
		{
			count++;
		}
		
		if(temp->left)	
			q.push(temp->left);
			
		if(temp->right)
			q.push(temp->right);
	}
	
	return count;
	
}//Time complexity = O(logn) as it is an AVL tree, Space = O(n) for queue


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
	
	cout<<endl;
	
	cout<<CountRangeLevelOrder(root,5,10);

}

