#include<iostream>


using namespace std;


/*Program to find PERFECT NUMBER- a perfect number is a number whose factors leaving itself when added equals to the number itself.

eg-6, its factors= 1,2,3 = 3+2+1=6 , 28 , factors(28) = 1,2,4,7,14 = 28

to check if a number is a perfect number or not
*/


bool PerfectNumber( long int n)
{
	long int factors=1;
	long int sum = 0;
	
	while(n > factors)
	{
		//if n is divisible by factors
		if(n%factors==0)
		{
			sum += factors;
						
		}
		
		//otherwise simply increment and again check
		factors++;
	}
	
	if(sum==n)
	{
		return true;
	}
	
	return false;
	
}


//function to find all the Perfect numbers till a range
void PerfectNumbersInRange(int range)
{
	int i=1;
	while(i<=range)
	{
		if(PerfectNumber(i))
		{
			cout<<i<<endl;
		}
		
		i++;
	
	}
		
	
}


int main()
{
	
	PerfectNumbersInRange(10000);
	
}

