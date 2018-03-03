#include<iostream>
#include<vector>

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


int main()
{
	return 0;
}
