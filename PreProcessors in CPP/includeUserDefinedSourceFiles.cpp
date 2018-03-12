#include<iostream>
using namespace std;

#include "MyInfoCLass.cpp"


/*program to demonstrate the usage of #include pre-processor directive in CPP to include and load custom build source files(classes)

Pre-processor- is simply a software of a small program which run before the compilation of the program
Pre-processor directive-: using a diretive we can tell a the compiler to compile certain parts of our program based on our instruction
 */
 
 
 
int main()
{
	Person Anish(20,"Anish");
	
	Anish.getInfo();
	
	return 0;
}
