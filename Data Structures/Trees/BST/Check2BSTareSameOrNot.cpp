#include<iostream>
#include<set>
#include<vector>

using namespace std;

struct BSTnode{
	
	int data;	
	struct BSTnode *left,*right;
};


/*Program to find if 2 BST are same , i.e have same elements or not.

*/


int height(BSTnode *root)
{
	if(!root)
		return -1;
		
	return max(height(root->left),height(root->right)) + 1;
}

//Function to check if both BSTs have same structure as well
void AreSameBSTUtil(BSTnode *root,vector<int>&v1)
{

	if(!root)	
		return ;
		
	AreSameBSTUtil(root->left,v1);
	
	v1.push_back(root->data);
	
	AreSameBSTUtil(root->right,v1);
	
	

}//TIME COMPLEXITY = O(n), Space  = O(n) stack space.


bool AreSameBST(BSTnode *root1,BSTnode *root2)
{
	
	if(!root1 && !root2)
		return true;
		
	vector<int>v1;
	vector<int>v2;
	AreSameBSTUtil(root1,v1);
	AreSameBSTUtil(root2,v1);
	
	return (v1==v2);
	
	
}

void PopulateSet(BSTnode *root,set<int>&S)
{
	if(!root)
		return;
	
	PopulateSet(root->left,S);
	
	S.insert(root->data);
		
	PopulateSet(root->right,S);
}


bool SameOrNotUsingSet(BSTnode *root1,BSTnode *root2)
{
	
			
	//populate Set with data in Tree1
	
	set<int>S;
	PopulateSet(root1,S);
	
	if(!root1||!root2)
		return false;
		
		
	
	

	
	return SameOrNotUsingSet(root1,root2->left);
	
	set<int>::iterator it=S.begin();
	
	
	if(root2->data == *it)
	{
		
		return true;
		
	}	
			
	S.erase(it);

		
	return SameOrNotUsingSet(root1,root2->right);
	
	


	
}


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
	BSTnode *root1  = newNode(10);
	
	insert(root1,5);
	insert(root1,20);
	insert(root1,15);
	insert(root1,30);
	
	
	BSTnode *root2 = newNode(10);
	
	insert(root2,20);
	insert(root2,15);
	insert(root2,30);
	insert(root2,5);
	
	
	//height of root1 =2, height of root2 = 3, both trees are different
	cout<<height(root1)<<" "<<height(root2)<<endl;
	
	//both of the above trees have different structures although have same data
	cout<<AreSameBST(root1,root2);
	cout<<endl;
//	cout<<SameOrNotUsingSet(root1,root2);
	
	return 0;
		
}
