#include<iostream>

using namespace std;

//UGLY NUMBERS program-finding Nth sequence of ugly number

//METHOD-1 BRUTE FORCE APPROACH

//function which divides a numeber a by greatest divisible power fo b 
int greatestDivide(int a, int b)
{
	while(a%b==0)
		a=a/b;
		
	return a;
}



//function to check if a number is UGLY number or not
int CheckUgly(int n)
{
	n = greatestDivide(n,2);
	n = greatestDivide(n,3);
	n = greatestDivide(n,5);
	
	return (n==1) ? 1 : 0;

} //when we finally get 1 this means it is a ugly number


int getNthUglyNo(int n)
{

	int i=1;//ugly number sequence
	int count = 1; //ugly number count
	
	while(n > count)
	{
		i++;
		if(CheckUgly(i))
		{
			count++;		
		}
		
				
	}	

	return i;	

}//TIME COMPLEXITY  = O(n) , Space complexity = O(1)



int main()
{


	cout<<getNthUglyNo(150);
		
}
