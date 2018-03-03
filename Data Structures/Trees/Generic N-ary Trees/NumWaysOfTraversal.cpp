#include<iostream>
#include<vector>
#include<queue>

//program to find the number of ways a N-ary tree can be traversed

using namespace std;

//we can use a vector to store the child nodes of a node

struct GenericTree{
	int data;
	vector <GenericTree*> child; //a vector to store children of a node
};


/*Solution
Number of ways an N-ary tree can be traversed is the factorial of the number of children each node has;
*/

//program to find factorial of a number;


GenericTree *NewNode(int data)
{
	GenericTree *temp = new GenericTree();
	temp->data=data;
	
	return temp;
}

unsigned long long int factorial(int n)
{
	//base condition
	if(n<=1)
	{
		return 1;
	}
	
	else
	{
		return n*factorial(n-1);
	}
}


//function to count total possible ways a N-ary tree can be traversed
//using level order traversal(BFS) to count the number of child each parent node has at each level
//usingned long long int inorder to avoid overflow because factorials can take very large values
unsigned long long int numTraversals(struct GenericTree *root)
{
	int ways = 1;
	if(!root) return 0;
	queue<GenericTree *> q;
	struct GenericTree *temp;
	
	q.push(root);
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		
		// The number of ways is the product of
         	// factorials of number of children of each node
         	ways = ways*factorial(temp->child.size());
         	
         	//now enqueue all children of the dequed item
         	
         	for(int i=0; i < temp->child.size();i++)
         	{
         		q.push(temp->child[i]);
		}
	}
	
	return ways;
}



int main()
{
		
	
	GenericTree *root = NewNode(1);
	
	root->child.push_back(NewNode(2));
	root->child.push_back(NewNode(3));
	root->child.push_back(NewNode(4));
	
	
	root->child[0]->child.push_back(NewNode(5));
	root->child[0]->child.push_back(NewNode(6));
	root->child[0]->child[1]->child.push_back(NewNode(11));
	root->child[0]->child[1]->child.push_back(NewNode(12));
	root->child[0]->child[1]->child.push_back(NewNode(13));
	
	
	root->child[0]->child.push_back(NewNode(7));
	
	root->child[1]->child.push_back(NewNode(8));
	
	root->child[2]->child.push_back(NewNode(9));
	root->child[2]->child.push_back(NewNode(10));
	
	/* The above tree has structure
		  1
		  
	      /	   |   \
	      2    3    4  = 3!
	    / | \  |   / \
	   5  6  7 8   9  10 = 3! * 1! * 2! 
	     
	     / | \		
	    11 12 13   = 3!
	
	TOTAL = 3! * (3!) * 3! * 2! * 1!
	
	
	*/
	
	
	cout<<numTraversals(root);
	
	
	

	
	return 0;
}
