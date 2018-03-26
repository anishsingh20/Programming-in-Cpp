#include<iostream>

using namespace std;

//program to find e^x using taylor series-


//this program for larger values of y, appriximates e^x
float exp(float x,int y)
{
	float p,s; int i;
	
	for(s = 1 ,p=1,i=1; i<y ; i++)
	{
		 p *= x/i;
		 s += p;
	}
	
	return s;
}


int main()
{
	cout<<exp(10,10);
	
}

