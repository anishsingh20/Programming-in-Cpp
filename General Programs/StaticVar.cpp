#include<iostream>

using namespace std;

void fun(int *x) {
	
		
	
	cout<<&x;
}

void fun(int y[]) {
	
	cout<<y<<endl;
	
}

int main() {
	
	int x = 20;
	int *ptr=&x;
	cout<<&x<<endl;
	cout<<ptr<<endl;	
	fun(&x+1);
	
	
	
	return 0;
}



