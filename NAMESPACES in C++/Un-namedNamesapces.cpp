#include<iostream>


using namespace std;

//Un-named or anynymous namespaces. A namespcae which has no name. Each program/file has its own un-named namespace by default, and these unnamed namsapces are loacl
//to a file and cannot span multiple files.


namespace {
	
	
	int factorial(int n)
	{
		
		if(n<=1)
			return n;
			
		else return n*factorial(n-1);	
	}
	
}


int main()
{
	
	
	cout<<factorial(30);	

}
