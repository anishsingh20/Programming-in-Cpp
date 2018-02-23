#include<iostream>
#include<stack>


//implementing queue using 2 stacks

//global declaration of stacks
using namespace std;
 stack <int> s1;//for enquing
 stack <int> s2;//for dequeue
 
 

class Queue{
	public:
		void Enqueue(int data);
		void Dequeue();
		
};

 
 
void Queue::Enqueue(int data) { //simply push into stack S1
	
	
	//simply push data into stack s1
	
		s1.push(data);


		
}


void Queue::Dequeue() {
	
	
	if(s1.empty() && s2.empty()) {
		cout<<"Both stacks are empty"<<endl;
		exit(0);//exitting the program
		
	}
	
	//will enter this condition only at the first call to Dequeue() after inserting some data in queue
	//if stack 2 is empty , only then we transfer all items from stack1 to stack2 
	if(s2.empty()){ 
	
		//transfering from stack1 to stack2
		while(!s1.empty())
		{
		
			s2.push(s1.top());
			s1.pop();
		}
		cout<<"Deleted :"<<s2.top()<<endl;
		s2.pop();
			
			
		
	}
	
	//control comes here when  stack2 is not empty
	else {
	
	cout<<"Deleted :"<<s2.top();
	s2.pop();
	}

	
	cout<<"\n";
		

	
	
	
}



int main()
{
	
	Queue q; //creating object of class Queue
	int choice,data;
	
	
	while(1)
	{
		cout<<"\n1)Insert\n2)Delete\n3)Exit\n"<<endl;
		cin>>choice;
		
		
		switch(choice) 
		{
			
			case 1: 
				cout<<"Enter data :"<<endl;
				cin>>data;
				q.Enqueue(data);
				break;
			case 2:
				
				q.Dequeue();
				break;
			
			
			default:
				exit(0);
				break;
				
		}
	}
	
return 0;
		
}
