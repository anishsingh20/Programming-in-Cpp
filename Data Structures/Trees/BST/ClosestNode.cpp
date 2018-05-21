#include<iostream>
#include<cmath>
#include<queue>


using namespace std;


/*Given a key - we have to find the closest node to that key in a BST

1)Using Level order traversal
2) Using Recursion
3)Efficient-Using Morris Inorder traversal- as we know inorder traversal of a BST produces an sorted list, so we can iteratively search for the closest
node starting from root to its left subtree and then rigt subtree i.e inorder traversal. 

*/


struct BSTnode {
	
	int data;
	BSTnode *left,*right;
};


BSTnode *ClosestNode(BSTnode *root,int key)
{
	if(!root)
		return NULL;
		
	if(root->data==key)
		return root;
		
	// the closest to key is in left subtree
	if(root->data > key )
	{
		if(!root->left)
			return root;
		
		BSTnode *temp = ClosestNode(root->left,key);
		
		return ( abs( temp->data - key ) > abs( root->data- key ) ) ? root : temp;	
		 
	}
	
	
	//in this case the closest to key is in right subtree
	if(root->data < key)
	{
		if(!root->right)
			return root;
			
		BSTnode *temp = ClosestNode(root->right,key);
		
		return ( abs( temp->data - key ) > abs( root->data- key ) ) ? root : temp;
	}
}

//TIME COMPLEXITY = O(n) for worst case(skew-tree) and  Average case =  O(logn) when tree is balanced.
//Space complexity = O(n) for worst case i.e height of recursion tree(skew-tree) and Average case is O(logn).



//Method-2 Using level order traversal
BSTnode *ClosestNodeLevelOrder(BSTnode *root,int key)
{
	if(!root)
		return NULL;
		
	int diff = INT_MAX;
	queue<BSTnode*>q;
	BSTnode *temp,*closest;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(diff > abs(temp->data - key))
		{
			diff = abs(temp->data - key);
			
			closest  = temp;
		}
		
		if(temp->left)
			q.push(temp->left);
			
		if(temp->right)
			q.push(temp->right);
			
			
	}
	
	return closest;
}



//Method-2 Using Morris Inorder traversal-memory efficient method-No recursion, no stack/queue
BSTnode* ClosestNodeInorderMorris(BSTnode *root,int key)
{
	int diff = INT_MAX;
	BSTnode *curr = root;
	BSTnode *closest ;
	
	while(curr)
	{
		if(curr->left==NULL)
		{
			//updating diff if the current diff is smaller than prev difference
			if(diff > abs(curr->data-key))
			{
				diff = abs(curr->data-key);
				closest = curr;
				
				
			}
				
			curr = curr->right;
		}
		
		//finding the inorder predecessor
		else{
			BSTnode *pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;
				
			if(pre->right==NULL)
			{
				pre->right = curr;
				
				curr = curr->left;
			}
			
			//threaded link between curr and its predecessor already exists
			else
			{
				pre->right = NULL;
				
				if(diff > abs(curr->data-key))
				{
					diff = abs(curr->data-key);
					closest = curr;
					
				
				}
				
				curr = curr->right;
				
				
			}
		}
		
		
	}
	
	return closest;
	
}
//TIME COMPLEXITY = O(n) for worst case 
//SPACE COMPLEXITY = O(1)- as no recursion ot stack/queue is used.



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

BSTnode *newNode(int data)
{
	BSTnode *temp = new BSTnode();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}


int main()
{
	
	
	BSTnode *root  = newNode(4);
	
	insert(root,2);
	insert(root,3);
	insert(root,1);
	insert(root,7);
	insert(root,6);
	insert(root,12);
	insert(root,20);	
	
	cout<<ClosestNode(root,15)->data;
	cout<<endl;
	cout<<ClosestNodeLevelOrder(root,15)->data;
	cout<<endl;
	cout<<ClosestNodeInorderMorris(root,10)->data;
}
