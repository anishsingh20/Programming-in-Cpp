#include<iostream>
#include<stack>
#include<queue>

//Interleaving the 2 halves of a queue
using namespace std;

stack<int>s;


void Enqueue(queue<int>&q,int data);
int Dequeue(queue<int>&q);
void display(queue<int>q);




void InterleaveQueue(queue<int>&q)
{
	
	if(q.empty()) {
		cout<<"Queue is Empty"<<endl;
		return;
	}
	if(q.size()%2 != 0) { //if queue has odd size
		cout<<"Please enter even number of elements in queue"<<endl;
		
	}
	
	int halfsize = (q.size()/2);
	
	
	//Pushing half items of queue to stack
	for(int i=0;i<halfsize;i++) {
		
		s.push(Dequeue(q));
		
	}
	
	//now until stack is empty , Enqueue half items from stack to queue from rear of queue
	
	while(!s.empty()) {
		Enqueue(q,s.top());
		s.pop();
	}
	
	//now again dequeue half items of queue from front and enqueue them to back
	
	for(int i=0;i<halfsize;i++) {
		
		Enqueue(q,Dequeue(q));
		
	}
	
	//now Dequeue from front of queue and push them to stack
	for(int i=0;i<halfsize;i++) {
		
		s.push(Dequeue(q));
		
	}
	
	//magic happens here 
	while(!s.empty()) {
		//1)pop from stack and enqueue them to queue from back
		Enqueue(q,s.top());
		s.pop();
		
		//2)Now dequeue from front and enqueue to queue from rear end
		
		Enqueue(q,Dequeue(q));
		
		
	}
	//printing the interleaved queue
	display(q);
	cout<<"Queue interleaved"<<endl;
}
	



void Enqueue(queue<int>&q,int data) {
	
	q.push(data); //simply Enqueue data into queue from front
	
}


int Dequeue(queue<int>&q) {
	
	if(q.empty()) {
		cout<<"Queue is empty"<<endl;
		return 0;
	}
	cout<<"\n";
	//now dequeue from the front of queue
	int item=q.front();
	q.pop();
	
	return item;
	
}


void display(queue<int>q)
{
	if(q.empty()) {
		cout<<"Queue is Empty"<<endl;
		return;
	}
	
	while(!q.empty()) {
		
		cout<<" | "<<q.front()<< " | ";
		q.pop();
	}	
	
	
}


	
	
int main() {
	int choice;
	
	queue<int>q;
	
	
	while(1){
		cout<<"\n";
		cout<<"\n1)Insert\n2)Delete\n3)Interleave Queue\n4)Display\n5)Exit\n"<<endl;
		cin>>choice;
		cout<<"\n";
		
		switch(choice) {
			
			case 1: 
				int data;
				cout<<"Enter data :"<<endl;
				cin>>data;
				Enqueue(q,data);
				break;
			case 2:
				
				cout<<"Deleted :"<<Dequeue(q);
				break;
				
			case 3:
				InterleaveQueue(q);
				break;
				
			case 4:
				display(q);
				break;
				
			default:
				exit(0);
				break;
				
		}
	}
	return 0;
	
}
	
	
	
	
	



