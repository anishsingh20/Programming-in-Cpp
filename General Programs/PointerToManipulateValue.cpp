#include<iostream>

using namespace std;

int main() {
	int a=10;
	int *ptr=&a;
	cout<<"Initially a: "<<a<<endl;
	cin>>*ptr; //input value which is indirectly manipulated
	cout<<"Using pointer manipulation, a becomes: "<<a<<endl; //value is updated
	
}
