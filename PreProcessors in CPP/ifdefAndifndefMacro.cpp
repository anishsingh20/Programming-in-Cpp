#include<iostream>

//using ifdef and ifndef macros in cpp

/* 1) ifdef= if a macro is defined then do something
   2) ifndef = if  macro is not defined then do something	
*/

using namespace std;

#define ANISH 1

int main()
{
	#ifdef ANISH
		cout<<"ANISH macro is defined"<<endl;
		
	#else 
		cout<<"Not defined"<<endl;
		
	#endif
	
	cout<<endl;
	
	#undef ANISH  //undefining the ANISH macro
	
	#ifndef ANISH
		cout<<"ANISH macro undefined"<<endl;
		
	#endif
	
	
	return 0;
}
