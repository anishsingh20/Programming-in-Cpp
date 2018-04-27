#include<iostream>


using namespace std;


//Program to find PERFECT NUMBER- a perfect number is a number whose factors leaving itself when added equals to the number itself.

//eg-6, its factors= 1,2,3 = 3+2+1=6

//to check if a number is a perfect number or not
bool PerfectNumber(int n)
{
	int factors=1;
	int sum = 0;
	
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

void PerfectNumbersInRange(int range)
{
	
}


int main()
{
	cout<<PerfectNumber(6);
	
}

