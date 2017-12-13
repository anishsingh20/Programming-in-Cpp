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
		
		//if delimitters, continue
		if(exp[i]==' '|| exp[i]==',') continue;
		
		//if opening parenthesis-push it to stack
		else if(exp[i]=='('|| exp[i]=='[' || exp[i]=='{') {
			
			S.push(exp[i]); //pushing the opening parenthesis
			
		}
		
		//if closing parenthesis and stack is not empty pop form TOS
		else if(exp[i]==')'|| exp[i]==']' || exp[i]=='}' ) {
			
			//condition if expression contains only closing parenthesis, in that case - stack will be empty too but not a balanced expression
			if(S.empty()) return false;
			
			//on reading a closing brace - if stack is not empty then-
			else  S.pop(); //if stack has opening parenthesis '(' then pop it when reading a closing parenthesis ')'
			
			
			
			
 			 
			
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



