#include<iostream>
#include<stack>


//implementing queue using 2 stacks

//global declaration of stacks
using namespace std;
 stack <int> s1;
 stack <int> s2;

class Queue{
	public:
		void Enqueue(int data);
		Dequeue();
		void display();
};

 
 
void Queue::Enqueue(int data) { //simply push into stack S1
	
	
	//simply push data into stack s1
	s1.push(data);
	
}

 Queue::Dequeue() {
	
	//case- when stack1 empty, it means that queue is also empty
//	if(s1.empty()) {
//		cout<<"Queue is empty"<<endl;
//		return;
//	}
	if(!s2.empty()) {
		
		cout<<"Deleted Data is:"<<s2.top()<<endl;
		s2.pop();	
		}
	//until stack s1 is empty -pop elements from s1 and push them to s2
	else {
		//pop from stack 1 and push to stack 2
		
		while(!s1.empty())
		{
			//transferring elements from stack1 to stack2
			s2.push(s1.top());
			s1.pop();
			 
		}
		
		
		
	}
	//now popping from stack2 for dequeue
	
	//the Dequeued element will be the one on top of stack2
	
	
	

	
}


void Queue::display()
 {
 	
 	if(s1.empty()) {
 		cout<<"Queue is Empty."<<endl;
 		return;
	 }
	 
	 //first we need to transfer all elements from stack1 to stack2
	cout<<"Elements of Queue are :"<<endl; 
 	while(!s1.empty()) {
		
		//pop from stack 1 and push to stack 2
		s2.push(s1.top());
		s1.pop(); 
	}
 	

 	
 	
 	//stack 2 has the correct order of elements of queue
 	//so simply printing elements in stack 2
 	while(!s2.empty()) {
 		int x=s2.top();
 		cout<<x<<"\t";
 		s2.pop();
 	}
	
}


int main() {
	
	Queue q; //creating object of class Queue
	int choice,data;
	
	
	while(1){
		cout<<"\n1)Insert\n2)Delete\n3)Display\n4)Exit\n"<<endl;
		cin>>choice;
		
		
		switch(choice) {
			
			case 1: 
				cout<<"Enter data :"<<endl;
				cin>>data;
				q.Enqueue(data);
				break;
			case 2:
				
				q.Dequeue();
				break;
			case 3:
				q.display();
				break;
			
			default:
				exit(0);
				break;
				
		}
	}
	
return 0;
		
}
