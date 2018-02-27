#include<iostream>
#include<queue>

//PROGRAM TO FIND SUM OF NODES IN A GENERIC TREE

using namespace std;

struct TreeNode{
	int data;
	struct TreeNode *firstChild;
	struct TreeNode *nextSibling;
};



//simple recursive program
int SumNodes(TreeNode *root)
{
	if(!root) return 0;
	
	else return (root->data + SumNodes(root->firstChild) + SumNodes(root->nextSibling));
}


//level order traversal method

int SumNodesLevelOrder(TreeNode *root)
{
	queue<TreeNode *>q;
	TreeNode *temp;
	int sum = 0;
	
	if(!root) return 0;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		sum += temp->data;
		
		
		if(temp->nextSibling)
		{
			q.push(temp->nextSibling);
		}
		
		if(temp->firstChild)
		{
			q.push(temp->firstChild);
		}
		
		
	}
	
	return sum;
}



int numSiblings(TreeNode *root)
{

	int count = 0;
	
	while(root)
	{
		
		count++;
		
		
		
		root = root->nextSibling;
	}
	
	return count;
}


void LevelOrderTraversal(TreeNode *root)
{
	queue<TreeNode *>q;
	TreeNode *temp,*temp1;

	if(!root) return;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		
	
		
		if(temp->nextSibling)
		{
			temp1 = temp;
			for(int i=0;i<numSiblings(temp1);i++)
			{
		
				q.push(temp1->nextSibling);
				temp1 = temp1->nextSibling;
				
			}	

//		q.push(temp->nextSibling);
			
		}
		
		
		
		if(temp->firstChild)
		{
			q.push(temp->firstChild);
			
		}
		
		
		
	}
	
}




int main()
{
	
	struct TreeNode *root= new TreeNode();
	struct TreeNode *n1= new TreeNode();
	struct TreeNode *n2= new TreeNode();
	struct TreeNode *n3= new TreeNode();
	struct TreeNode *n4= new TreeNode();
	struct TreeNode *n5= new TreeNode();
	
	root->data=1;
	n1->data=2;
	n2->data=3;
	n3->data=4;
	n4->data=5;
	n5->data = 6;
	
	root->firstChild = n1;
	
	n1->nextSibling = n2;
	
	n2->nextSibling = n3;
	
	n2->firstChild = n5;
	
	n1->firstChild  = n4;
	
	LevelOrderTraversal(root);	


//	cout<<numSiblings(n2);
 	
//	cout<<SumNodes(root);
//	cout<<endl;
//	
//	cout<<SumNodesLevelOrder(root);
	return 0;
	
	
	
}

