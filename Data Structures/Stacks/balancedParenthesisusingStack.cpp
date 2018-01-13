//Checking for balancing parenthesis- implementation using stacks
#include<iostream>
#include<stack>
#include<string>

using namespace std;


//function to check whether a given expression has balanced parenthesis or not? 
bool checkBalance(string exp) {
	
	stack<char>S;//defining a char stack
	//scanning left to right of the expression
	
	for(int i=0;i<exp.length();i++) {
		
		switch(exp[i]) {
			
			
			//if opening brace then push them to stack
			case '{' :
			case '(' :
			case '[' :
				S.push(exp[i]);
				break;
				
			case '}' :
				if(S.top()=='{' && !S.empty()) {
					S.pop();
				}
				break;
			case ']' :
				if(S.top()=='[' && !S.empty()) {
					S.pop();
				}
				break;
			case ')' :
				if(S.top()=='(' && !S.empty()) {
					S.pop();
				}
				break;
		}
	}
		
	//coming out of loop after reading the complete expression
	//now we have to check if the stack is empty of not?
	return S.empty() ? true : false;
	
	
//		if(!S.empty()) {
//			cout<<endl<<"Unbalanced expression"<<endl;
//			
//		}
//		//if stack is empty -then the expression is balanced
//		else {
//			cout<<endl<<"Stack is Empty, hence balanced expression"<<endl;
//		}
	
}




int main () {
	
	string exp;
	cin>>exp;
	
	if(checkBalance(exp)) {
		cout<<"Balanced expression"<<endl;
	}
	else {
		cout<<"unbalanced expression"<<endl;
	}
	
	return 0;
}



