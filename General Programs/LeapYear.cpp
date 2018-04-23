#include<iostream>


using namespace std;


//program to find whether a year is leap year or not.

bool leapOrNot(long int year)
{
	//if divisible by 4
	if(year % 4==0)
		return 1;
		
	//if it is divisible by 100, and not divisible by 400, then not a leap year
	if(year%100==0)
	{
		if(year%400==0)
			return 1;
	}
	
	return 0;
}




int main()
{
	cout<<leapOrNot(800);
	
}


