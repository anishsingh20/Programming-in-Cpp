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
//usingned long long int inorder to avoid overflow becasue factorials can take very large values
unsigned long long int numTraversals(struct GenericTree *root)
{
	int ways = 1;
	if(!root) return;
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
	
	return 0;
}
