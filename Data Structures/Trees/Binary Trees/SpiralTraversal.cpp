#include<iostream>
#include<stack>
#include<queue>

/*PROGRAM TO TRAVERSE A TREE IN SPIRAL FASHION- at eac level we need to print data in alternating order
a) Using 2 stacks. One to print from left to right order, and other to print from right to left order-T(n) = O(n)
b) Usig recursive implementation-T(n) = O(n^2)
*/
using namespace std;


struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left,*parent;
	BinaryTreeNode *right;
};

//METHOD-1 : USING RECURSION and LEVEL ORDER TRAVERSAL

//function to get the height of tree
int heightTree(struct BinaryTreeNode *root)
{
	if(root==NULL) return 0;
	
	else return (1 + max(heightTree(root->left),heightTree(root->right ) ) );
}


//level wise traversal using recursion
void printTree(struct BinaryTreeNode *root,int level, bool ltr)
{
	//base condition
	if(root==NULL) return;
	
	
	if(level==0) 
	{
		cout<<root->data<<" ";
	}
		
	else if(level  > 0 )
	{
		//if order is to traverse from left to right
		if(ltr)
		{
			printTree(root->left,level-1,ltr);
			printTree(root->right,level-1,ltr);	
		}
		
		//when order is to print from right to left
		else
		{
			printTree(root->right,level-1,ltr);
			printTree(root->left,level-1,ltr);
		}
	}
}




void PrintSpiral(struct BinaryTreeNode* root)
{
	if(root==NULL) return;
	
	bool ltr = false;//after visiting each level we will reverse it
	
	int ht_tree = heightTree(root);//finding height of tree
	
	for(int level = 0 ; level < ht_tree ; level++)
	{
		printTree(root,level,ltr);
		ltr = !ltr;//reversing ltr order for printing in revrese order at next level
	}
}
//TIME COMPLEXITY = O(n^2), space complexity = O(n) for stack space for storing recursion calls







//METHOD-2 USING 2 STACKS

///We will use 2 stacks, One stack to print data from left to right, another stack to print data from right to left order
void SpiralTraversal(BinaryTreeNode *root)
{
	if(!root) return;
	BinaryTreeNode  *temp;
	stack<BinaryTreeNode *>s1; //stack to print from right to left
	stack<BinaryTreeNode *>s2;//satck to print from left to right
/*the concept is , if we want to print in left to right order, then in the stack first we need to push the right child first and then on top should be the
left child.So this will preserve as stack will print in reverse order*/  
	
	s1.push(root);
	
	while(!s1.empty() || !s2.empty() )
	{
		while(!s1.empty())
		{
			temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			
			if(temp->right) s2.push(temp->right);
			if(temp->left)  s2.push(temp->left);
		}
	
		while(!s2.empty())	
		{
			temp = s2.top();
			s2.pop();
			
			cout<<temp->data<<" ";
			
			if(temp->left) s1.push(temp->left);
			
			if(temp->right) s1.push(temp->right);
		}
	}
	
	
}


	
void Insert( struct BinaryTreeNode **root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	new_node->data = data;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(*root==NULL)
	{
		*root = new_node;
		return;
	}
	
	q.push(*root);
	
	while(!q.empty())
	{
		temp  = q.front();
		q.pop();
		
		if(temp->left==NULL)
		{
			temp->left = new_node;
			return;
			
			
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
}
//TIME COMPLEXITY = O(N) ,  SPACE COMPLEXITY = O(n)


int main()
{

	struct BinaryTreeNode *root1 = NULL;
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,7);


	cout<<"Using Recursive implementation"<<endl;
	PrintSpiral(root1);
	
	cout<<endl;
	
	cout<<"Implementation using stacks"<<endl;
	SpiralTraversal(root1);
	
	
	
	return 0;
}
