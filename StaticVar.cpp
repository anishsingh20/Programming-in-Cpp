#include<iostream>

using namespace std;
void display(); //function prototyping

int main()
{
	display();
	display();
	display();
	display();
	display();
}

void display(){
	 static int counter=0;//a variable which is initialized only once at the start of execution of program, 1 copy is maintained
	 int count=0;
	cout<<"Function called"<<" "<< ++counter<<" "<<"Times"<<endl;
	cout<<"Function called without using static variable"<<++count<< " "<<"Times"<<endl;
}
