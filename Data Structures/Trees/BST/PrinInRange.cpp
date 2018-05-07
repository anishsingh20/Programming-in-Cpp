#include<iostream>
#include<queue>

using namespace std;

/*Program to print data within a range say K1 and K2 in a BST-Asked in Microsoft and Flipkart.
1)Recursive method-
2)Level order traverasl method
3)Threaded tree and inorder successor using MORRIS TRAVERSAL-which is used to do inorder traverasl using the inorder predecessor thread, and 
consumes constant extra memory = O(1)


*/
struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};

//1)Recursive method-
void RangePrint(BSTnode *root,int low,int high)
{
	static int count = 0 ;
	if(!root) return;
	
	if(root->data >= low )
		RangePrint(root->left,low,high);
	
	//if between the range , then simply print
	if(root->data <= high && root->data >= low)
	{
		cout<<root->data<<" ";
		count++;
	}
	
	if(root->data <= high)
		RangePrint(root->right,low,high);
	
}//T(n) = O(n), S(n) = O(n) for recursion call stack space

int RangeCount(BSTnode *root,int low,int high)
{
	static int count = 0 ;
	if(!root) return -1;
	
	if(root->data >= low )
		RangeCount(root->left,low,high);
	
	//if between the range , then simply print
	if(root->data <= high && root->data >= low)
	{

		count++;
	}
	
	if(root->data <= high)
		RangeCount(root->right,low,high);
		
		
	return count;
	
}//T(n) = O(n), S(n) = O(n) for recursion call stack space


//Method-2:Using Level order traversal.
void RangePrintLevelOrder(BSTnode *root,int low,int high)
{
	if(!root)	return;
	
	queue<BSTnode*>q;
	BSTnode *temp;
	
	q.push(root);
	
	while(!q.empty())
	{
		
		temp = q.front();
		q.pop();
		
		if( temp->data >= low  && temp->data <= high)
		{
			cout<<temp->data<<" ";
			
		}
		
		if(temp->left && temp->data >= low)
			q.push(temp->left);
			
		if(temp->right && temp->data <= high)
			q.push(temp->right);
	}	
}//Time complexity = O(n), spcae complexity = O(n) consumed by queue



//Method3-Using Threaded tree
void RangePrintMorrisTraversal(BSTnode *root,int low,int high)
{
	if(!root) return;
	
	BSTnode *curr = root;
	
////	if( low <= root->data <= high )
//		cout<<root->data<<" ";
	
	while(curr)
	{
		
	

		if(curr->left==NULL)
		{
			if(curr->data <= high && curr->data >= low)
			{
				cout<<curr->data<<" ";
				
				
			}
				
				
			curr = curr->right;
		}
		
		else
		{
			BSTnode *pre = curr->left;
			//finding the inorder predecessor-
			//inorder predecessor is the right most in left subtree or the left child, i.e in BST
			//it is the maximum(right most) in left subtree. 
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;
				
			if(pre->right==NULL)
			{
				pre->right = curr;
				
			
				curr = curr->left;
			}
			
			else
			{
				pre->right  = NULL;
				
				if(curr->data <= high && curr->data >= low)
				{
					
					cout<<curr->data<<" ";
						
						
				}
				
				curr = curr->right;						
					
			}
		}

	}
}//EFFICIENT SOLUTION-CONSUMES CONSTANT EXTRA SPACE = O(1), T(n)  = O(n)






BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}



BSTnode *insert(BSTnode *root,int value)
{
	//we first need to find the appropiate location to insert data
	if(root==NULL)
	{
		BSTnode *temp  = new BSTnode();
		temp->data = value;
		temp->left = temp->right = NULL;
		
		root = temp;
	}
	
	
	else if(root->data > value)
	{
		root->left = insert(root->left,value);
	}
		
	else if(root->data < value)
	{
		root->right = insert(root->right,value);
	}
	
	
	
	//returning root of the updated tree
	return root;
}




int main()
{
	
	BSTnode *root  = newNode(20);
	
	insert(root,4);
	insert(root,8);
	insert(root,12);
	insert(root,22);
	
	
//	RangePrint(root,4,22);

	RangePrintMorrisTraversal(root,10,22);
	
	cout<<endl;
	
	RangePrintLevelOrder(root,10,22);
	cout<<endl;
	cout<<RangeCount(root,10,22);

	
	
	
	return 0;
}


