#include<iostream>


using namespace std;

//Un-named or anynymous namespaces. A namespcae which has no name. Each program/file has its own un-named namespace by default, and these unnamed namsapces are loacl
//to a file and cannot span multiple files. We can also generate nested unnamed namespaces and also nest unnamed namesapces inside named namesapces or vice versa


namespace {
	
	
	int factorial(int n)
	{
		
		if(n<=1)
			return n;
			
		else return n*factorial(n-1);	
	}
	
	
	//nesting named namesapce inside an un-named namesapce
	namespace b{
	
		int x;
		void fact()
		{
			cout<<factorial(x);
		}
		
	
	}
	
}


int main()
{
	
	
	b::x=6;
	b::fact();
	

}
