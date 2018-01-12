#include<iostream>

//POINTER AIRTHEMETIC - Only addition and substraction possible
//TYPECASTING in POINTERS

//SOME BASICS OF POINTERS

using namespace std;

int main() {
	
	int a = 1025;
	//a is laid out in this way in memory
	// 00000000(Byte-4) 00000000(Byte-3) 00000100(Byte-2) 00000001(Byte-1)
	int* p;
	p=&a; //p stores address of 1 byte of a in memory , so p stores address of Byte-1
	cout<<p;
	cout<<*p; //deferencing pointer p which prints value at address stored in p ie 1025
	
	char* p1;
	
//	p1=p; //produces error 
	//TYPECASTING
	p1 = (char*)p; //is a char pointer which also stores the address of Byte-1
	
	cout<<p1;
	cout<<*p1; //decimal value of Byte-1  i.e 00000001 = 1 in decimal
	//this is because char is 1 bytes long and p1 is a char pointer so while dereferencing we looked at only 1 byte
	 
	
	
}
