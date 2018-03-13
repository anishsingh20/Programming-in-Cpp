#include<iostream>
#include<map>
#include<queue>

using namespace std;

/*PROGRAM TO FIND SUM OF NODES AT EACH DIAGONAL LINE- APPROACH IS SIMILAR TO FINDING VERTICAL SUMS OF NODES AT LYING ON EACH VERTICAL LINE

simply use the vertical distance of nodes as key and keep adding nodes having same distance in map as value 

*/
struct BinaryTreeNode{
	
	int data;
	struct BinaryTreeNode *left,*right;
};



void PopulateMap(struct BinaryTreeNode *root, map < int,int >&Map,int d)
{
	if(!root) return ;
	
	Map[d] += root->data;
	//now recursively traverse to left and right subtrees
	
	//we increase the vertical distance by 1 for each left node
	PopulateMap(root->left,Map,d+1);
	
	//for a right node it reamins the same
	PopulateMap(root->right,Map,d);
	
}


void DiagonalSum(struct BinaryTreeNode *root)
{
	map< int,int> Map;
	
	//populating the map
	PopulateMap(root,Map,0);
	
	//simply traverse the map 
	map< int ,int>::iterator it;
	
	cout<<"Slope Distance"<<"----"<< "Sum at diagonals"<<endl;
	for(it=Map.begin();it!=Map.end();it++)
	{
		cout<<it->first<<"------------------------->"<<it->second<<endl;
		
		
		
	}
	
}


//iterative approach- simply keep a variable sum to print sum of nodes on each diagonal line, then reset sum to 0.
//we keep a delimitter NULL in queue to mark end of current diagonal and print sum, then reset sum.
void SumDiagonalsIterative(struct BinaryTreeNode *root)
{
	if(!root) return;
	
	queue<BinaryTreeNode *> q;
	BinaryTreeNode *curr;
	int sum=0;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		
		if(curr==NULL)
		{
			//delimitter for starting of new diagonal
			if(!q.empty())	q.push(NULL);
			
			
			
			cout<<sum<<" ";
			
			sum=0;
			
			cout<<endl;
			
		}
		
		else
		{
			while(curr)
			{
				sum += curr->data;
				
				if(curr->left)	q.push(curr->left);
				
				curr = curr->right;
			}
			
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


int main()
{
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,1);
	Insert(&root1,2);
	Insert(&root1,3);
	Insert(&root1,4);
	Insert(&root1,5);
	Insert(&root1,6);
	Insert(&root1,14);
	Insert(&root1,7);
	Insert(&root1,13);
	
	DiagonalSum(root1);
	
	cout<<endl;
	
	SumDiagonalsIterative(root1);
	
	cout<<endl;
	

}
