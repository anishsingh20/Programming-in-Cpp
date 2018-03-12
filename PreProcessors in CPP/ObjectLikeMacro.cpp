#include<iostream>


//the below defined macros are called object like macros
#define ANISH "anish"

#define ONE 1
#define TWO ONE+ONE
#define THREE TWO+ONE 



using namespace std;


//MACRO- its is simply a fragment of code with a name
//Object like macro in cpp



int main()
{
	cout<<ANISH<<endl;
	cout<<endl;
	cout<<THREE<<" "<<TWO<<" "<<ONE;
}
