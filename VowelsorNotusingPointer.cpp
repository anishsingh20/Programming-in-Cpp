#include<iostream>
#include<string>
#include <string.h>

using namespace std;

int main() {
	
	char *ptr;
	char name[100];
	//arrays are always autmoatically passed by reference
	
	ptr = name; //ptr now stores address of name array, array's label itself acts as an address of the array
	int countv=0,countc=0;
	
	//will use the pointer to do all the ops, as char pointer and char array act as same thing
	
	gets(ptr);//reading the char
	
	for(int i=0;ptr[i]!='\0';i++) 
		{
			
		if(isalpha(ptr[i])) { //only check for alphabets
			
			if(ptr[i]=='a'|| ptr[i]=='e' || ptr[i]=='i' || ptr[i]=='o' || ptr[i] =='u') {
				
				countv++;
			}
			else {
				countc++;
			}
		}
	}
	cout<<"The number of vowels are: "<<countv<<endl;
	cout<<"Number of consonants are: "<<countc<<endl;
	return 0;
	
}
