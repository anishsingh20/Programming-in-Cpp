#include<iostream>

using namespace std;

int main() 
{
	
	 enum flag{
	 	const1,const2,const3,const4,const5
	 };
	 
	 cout<<sizeof(flag);//will print 4 as size of a integer on 32 and 64bit machines is 4 bytes
	 
		
	
	
	return 0;
}
	
//PROGRAM 1	
//	int x=4,y=x;
//	int count =0;
//	
//	for(int i=1;i<4;++i) {
//		count++; loop runs 3 times
//		x+=x;
//	}
//	
//	cout<<x<<endl; x is 32
//	cout<<y*4<<endl;
//	cout<<count;
//------------

//PROGRAM 2

//	int func(int);//function prototyping
//	int i = func(10);
//	cout<<i<<endl;
//	cout<<i--<<endl;
//	cout<<i;
//	return 0;

//-------------------


//PROGRAM-3
//int func();
//int i = func(); 
//
//cout<<i; //returns value of 1 ,as function called is true
//
//
//}
//
//int func() {
//	 _AX=1090;
//}


//int func(int x ) {
//	return x++;
//}
