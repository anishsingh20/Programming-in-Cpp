#include<iostream>

using namespace std;

/*SOME FACTS ABOUT REFERENCES-
	1)A reference must be initialized when declared
	2)Once a reference is created, it cannot be later made to reference another  object i.e it cannot be reset.
	3)Reference cannot be NULL
	4)References can refer to constant values by making a constant reference to point to a constant variable.
*/

int main()
{
	//1) statement
	int y=10;
	int &x=y; //reference variable must be initialized when declared


	//3)int &z=NULL; produces error , as a reference variable cannot be NULL
	
	//4) Constant references refer to constant var
	const int b=100;
	//int & a = b; - produces error 
	const int &a = b ;
	cout<<a<<endl;
		
	return 0;
}
