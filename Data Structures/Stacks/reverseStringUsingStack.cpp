#include<iostream>
#include<string>

using namespace std;

//reversing a string using stack- TIME COMPLEXITY AND SPACE COMPLEXITY= O(n) , n = size of string

void reverse(string str) {
	
	int i = 0;
	int j = str.length()-1;
	
	
//	if(i==j) {
//		return;
//	}
	
	while(i<j) {
		
		swap(str[i],str[j]); //swapping 
		i++;
		j--;
	}
	
	cout<<str; //now str is updated with new reversed value	
}

int main() {
	string name;
	getline(cin,name);
	reverse(name);
	
	return 0;
}
