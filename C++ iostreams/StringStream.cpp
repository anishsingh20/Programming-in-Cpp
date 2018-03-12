#include<iostream>
#include<sstream>


using namespace std;

//program to demonstrate the usage of string stream class in CPP to convert any type of stream to a string stream and vice versa 


int main()
{
	
	
	int input;
	cin >>input;
	
	stringstream sobj;
	
	
	sobj << input;
	string input_String;
	sobj >> input_String;
	
	
	cout<<input+20<<" is the integer type"<<endl;
	cout<<input_String + "10"<<" is the string type"<<endl;
	
	
	//now converting string to other type
	
	cout<<endl;
	
	stringstream sobj2;
	
	string age = "25";
	
	sobj2 << age;
	
	int my_age;
	
	sobj2 >> my_age;
	
	cout<<"my age in integer form is "<<my_age-4<<endl;
	cout<<sizeof(string);
	
	
	return 0;
}


