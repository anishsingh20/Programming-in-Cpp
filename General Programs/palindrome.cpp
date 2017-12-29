#include<iostream>
#include<string>
#include<cstring> //to use the strlen(char) function

//implementing it using a C type string

using namespace std;

int palindrome(char *a) 
{
	int i=0;
	int j = strlen(a)-1;
	while(i<=j && a[i]==a[j])  {
		//true condition , simply change i and j indices
		i++;
		j--;
	}
		
		
	if(i<j) {
		
		cout<<"Not palindrome"<<endl;
		return 0;
		
		 
	}
	else {
		cout<<"Palindrome"<<endl;
		return 1;
	}
	
		
		
	}	

int main() {
	
	palindrome("nitin");
	palindrome("anish");
	return 0;
}
