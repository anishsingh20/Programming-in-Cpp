#include<iostream>

using namespace std;


//A program/file can have multipe namespaces and each namesapce can be redefined multiple times

namespace a {

	int x;
	void intro()
	{
		cout<<"Hi,! this is namespace a,and value of x  = "<<x<<endl;
	}

}


namespace b
{
	int y;
	void intro()
	{
		cout<<"Hi!, this is namespace b, and value of y = "<<y<<endl;
	}
}

using namespace a;
using namespace b;


int main()
{
	
	x=10;
	
	y=20;
	
	a::intro();
	
	b::intro();
	
}
