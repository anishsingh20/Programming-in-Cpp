#include<iostream>

using namespace std;


/*Program to find NEON NUMBER- A neon number is a nunber if the sum of digits of the square of the number n equals itself.

example-9 , sq(9) = 81, 8+1 = 9
*/

bool NeonNumber(int n)
{
	int sum=0;
	int sq = (n*n); //square of number
	int digit;

	//finding digits from the square and adding them up
	while(sq != 0)
	{
	 	int digit = sq%10;
	 	sq = sq /10;
	 	sum += digit;
		
				
		
	}
	
	//if the sum of digits equals the number itself then it is a neon number
	if(sum == n)
	{
		return true;
	}
	
	return false;

	
	
}


int main()
{
	cout<<NeonNumber(9);
	
}
