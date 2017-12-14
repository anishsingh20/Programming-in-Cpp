#include<iostream>
#include<string>
#include<stack>

using namespace std;

//reversing a string using stack- TIME COMPLEXITY AND SPACE COMPLEXITY= O(n) , n = size of string

//void reverse(string str) {
//	
//	int i = 0;
//	int j = str.length()-1;
//	
//	
////	if(i==j) {
////		return;
////	}
//	
//	while(i<j) {
//		
//		swap(str[i],str[j]); //swapping 
//		i++;
//		j--;
//	}
//	
//	cout<<str; //now str is updated with new reversed value	
//}
//
//int main() {
//	string name;
//	getline(cin,name);
//	reverse(name);
//	
//	return 0;
//}



//------------------------USING STACK--------------------

void reverse(string str) {
	stack<char> s;
	
	//push string to stack
	//reading the string char one by one and pusing it to stack
	for(int i=0;i<str.length();i++) {
		s.push(str[i]);
	}
	
	//popping the chars and revrrsing
	for(int i=0; i<str.length();i++) {
		str[i] = s.top(); //storing top element of stack in str,reversal
		s.pop(); //popping
	}
	cout<<str; //string is now updated and reversed
}

int main() {
	string name;
	getline(cin,name);
	reverse(name);
	
	return 0;
}

