#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define maxsize 10

class Stack {
       public:
	 int top;
	 int n;
	 int data;
	 int array[maxsize];
	 
	 //constructor
	 Stack() {
	 	top=-1; //initially
	 	
	 	
	 }
	 //defining the operations of stack
	 int isEmpty();
	 int isFull();
	 int Push();
	 int pop();
	 int displayStack();	
};

int Stack :: isEmpty() {
	return(top==-1) ;

}

int Stack::isFull() {
	return(top > maxsize-1) ;
		
	
}

int Stack :: Push() {
	if(isFull()) {
		cout<<"Stack is full"<<endl;
	}
	else {
		cout<<"Enter no of elements in stack"<<endl;
		cin>>n;
		cout<<"Enter the data in stack"<<endl;
		for(int i = 0; i < n ; i++) {
			cin>>data;
			array[++top] = data ;
			cout<<"\n";
		 
			
		}
		
	}
	
}

int Stack::pop() {
	top==-1;
	if(isEmpty()) {
		cout<<"Stack is empty"<<endl;
		
	}
	else {
		//remove element from top of stack
		return(array[top--]);
	}
	
}
int Stack::displayStack() {
	if(isFull()) { 
	 cout<<"Stack is Full"<<endl;
		
	}
	else if(isEmpty()) {
		cout<<"Stack is empty"<<endl;
	}
	else {
		cout<<"Top"<<"\n";
		cout<<"|";
		
		for(int i=n-1 ; i >= 0 ;i--) {
			cout<<"\n"<<array[i];
		}
		
		cout<<"\n"<<"Bottom"<<endl;
		
	}
}
	


int main() {
	Stack s;
	
	s.Push();

	
	s.displayStack();
	
	cout<<"\n"<< s.pop() <<" " << "Popped from top of stack"<<endl;
	
	s.displayStack();

	
	return 0;
}	
