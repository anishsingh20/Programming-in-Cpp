#include<iostream>


using namespace std;

/*A leap year is-
program to find whether a year is leap year or not.
A year is a leap year if it is divisible by 4 , and if the year is evenly divisible by 100, then is is not a leap year, unless it is divisible by 400.
if the year is divisible by 400, then it is a leap year.
*/
bool leapOrNot(long int year)
{
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


