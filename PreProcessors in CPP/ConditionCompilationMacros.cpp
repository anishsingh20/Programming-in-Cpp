#include<iostream>

using namespace std;
//CONDITIONAL COMPILATION MACROS

#define WIN 1
#define LIN 1
#define MAC 3


 #define OS MAC
int main()
{
	
		
	#if OS == WIN
		cout<<"Windows OS macro"<<endl;
	
	#elif OS == LIN
		cout<<"LINUX OS macro"<<endl;
		
	#else
		cout<<"MAC OS macro"<<endl;
		
	#endif	

	
	return 0;
}
