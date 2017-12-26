#include<iostream>
#include<string>

using namespace std;

int palindrome(string a)
{
	int i=0;
	int j = a.size()-1;
	while(i<=j && a[i]==a[j])  {
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
	return 0;
}
