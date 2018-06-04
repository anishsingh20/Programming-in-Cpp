#include<iostream>

//Program to demonstrate Recursive approaches to fidn pow(x,n) with different time complexities
//First to solve any problem by recursion we need to define and calculate a recurrence relation or recursion defination
//Space complexity of a recursive program is direclty proportional to the height/depth of the recursion tree


//Method-1
long long int Pow(int x,int n)
{
	//base condition-state where recursion ends and return 1-leaf of recursion tree
	if(n==0)
		return 1;
		
	return x*Pow(x,n-1);
} //Time complexity  = O(n) = linear , but very high SPACE COMPLEXITY due to very large recursion tree proportional to n
//So the stack space required to store the state of function calls is proportional to n

//Method-2 , more efficient, LESSER SPACE COMPLEXITY due to lesser funcition calls states stored in stack 
long long int Pow1(int x,int n)
{
	//base condition-state where recursion ends and return 1-leaf of recursion tree
	if(n==0)
		return 1;
	
	//if n is even power
	if(n%2==0)
	{
		long long int y = Pow1(x,n/2);
		return y*y;
	}
	
	//if x is odd
	else
	{
		return x*Pow1(x,n-1);
	}
	pow
}

using namespace std;

int main()
{
	
	cout<<Pow(13,60); // takes 61 steps = n  , height of recursion tree is 61,very high space complexity
	cout<<endl;
	cout<<Pow1(10,60); //takes  = logN ,around 10 steps , height of recursion tree is 10 , veru low space complexity
 	
	return 0;
}
