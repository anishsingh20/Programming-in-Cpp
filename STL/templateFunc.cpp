#include<iostream>

using namespace std;


template<typename T>

void Swap(T *a, T *b) {
	
	T temp = *a;
	*a=*b;
	*b=temp;
	
	
}


int main () 
{
	int a=10,b=20;
	string a1 = "Anish", b1 = "mrinal";
	
	Swap(&a,&b);
	
	cout<<"a :"<<a<<"  |  "<<"b :"<<b<<endl;
	
	Swap(&a1,&b1);
	
	
	cout<<a1<<endl;
	cout<<b1<<endl;

	
	return 0;
}
