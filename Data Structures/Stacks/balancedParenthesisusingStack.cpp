//Checking for balancing parenthesis- implementation using stacks
#include<iostream>
#include<stack>
#include<string>

using namespace std;


//function to check whether a given expression has balanced parenthesis or not? 
void checkBalance(string exp) {
	
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
		else if(!S.empty() && exp[i]==')'|| exp[i]==']' || exp[i]=='}' ) {
			//pop from TOS
			S.pop();
		}
		
		
	}
	
	//coming out of loop after reading the complete expression
	//now we have to check if the stack is empty of not?
	
	//if stack is empty -then the expression is balanced
		if(S.empty()) {
			cout<<endl<<"Stack is Empty, hence balanced expression"<<endl;
		}
		
		else {
			cout<<endl<<"Unbalanced expression"<<endl;
		}
}




int main () {
	
	string exp;
	cin>>exp;
	
	checkBalance(exp);
	
	return 0;
}



