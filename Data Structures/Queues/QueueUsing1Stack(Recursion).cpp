#include<iostream>
#include<stack>

// Date- 18/12/17 10:46
using namespace std;

//queue using 1 stack and recursion(function call stack)

stack<int>S1;

class Queue{
	public:
		void Enqueue(int data);
		int dequeue();
		
};


void Queue::Enqueue(int data) { //simply push into stack S1
	
	
	//simply push data into stack s1
	S1.push(data);


	
		
}



int Queue::dequeue() {
	
	int res,x,y;
	if(S1.empty()) {
		cout<<"Queue is Empty..."<<endl;
		return -1;
	}
	
	
	//case when stack has only one element-base condition
	if(S1.size()==1) { //if stack has only one element
		
		x = S1.top();
		S1.pop();
		
		return x;
		
	}
	
	else { //recursively call dequeue(), until stack has only 1 item left and above conditon is true
		
		y = S1.top();
		S1.pop();
		
		res = dequeue(); //res stores the last popped element
		
		//push everything back to stack, leaving the last item in stack, which is returned
		
		S1.push(y);
		
		return res; //returning the last popped item
		
		
	}
}





int main() {
	
	Queue q; //creating object of class Queue
	int choice,data;
	
	
	while(1){
		cout<<"\n1)Insert\n2)Delete\n3)Exit\n"<<endl;
		cin>>choice;
		
		
		switch(choice) {
			
			case 1: 
				cout<<"Enter data :"<<endl;
				cin>>data;
				q.Enqueue(data);
				break;
			case 2:
				
				cout<<q.dequeue();
				break;
			
			
			default:
				exit(0);
				break;
				
		}
	}
	
return 0;
		
}


