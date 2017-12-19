#include<iostream>
#include<queue>


using namespace std;


//IMPLEMENTING STACK USING 2 QUEUES

queue<int> q1;
queue<int> q2;


class Stack {
	public:
		void Push(int data); //Takes-O(1) time complexity
		void Pop();//-Takes -O(n)- time complexity- as we transfer n items from Queue1 to Queue2
		void Top();
};



void Stack::Push(int data) {
	
	if(q1.empty()) {
		q2.push(data); //if queue 1 is empty, then enqueue data to queue 2
	}
	else { //otherwise enqueue data to queue1
		q1.push(data); 
	}
	
}


void Stack::Pop() {
	int i=0,size;
	if(q1.empty() && q2.empty()) {
		cout<<"The stack is empty"<<endl;
		return;
	}
	
	if(q2.empty()) { //case if queue1 is not empty
		
		size= q1.size();
		while(i < q1.size()-1 )  //transfer n-1 items from queue1(storage Queue) to queue2(temporary queue)
		{
			q2.push(q1.front()); //enqueue n-1 items from Queue 1 to Queue2
			q1.pop();
			i++;
		}
		cout<<"Deleted "<<q1.front()<<" from top."<<endl; //queue1 now has only 1 item-which will be popped in LIFO fashion
		 q1.pop();
	}
	
	else {
		size=q2.size();
		
		while(i < size-1) { //transfer n-1 items from Q2(storage queue) to Q1(temp queue) 
			q1.push(q2.front()); //enqueue n-1 items from Queue2 to Queue1
			q2.pop();
			i++;
		}
		 cout<<"Deleted "<<q2.front()<<" from top."<<endl; // Queue2 now has only 1 item which is popped
		 q2.pop();
		
	}
	
}


void Stack::Top() {
	int i=0,size,front;
	if(q1.empty() && q2.empty()) {
		cout<<"The stack is empty"<<endl;
		return ;
	}
	
	if(q2.empty()) { //case if queue1 is not empty
		
		size= q1.size();
		while(i < q1.size()-1 )  //transfer n-1 items from queue1(storage Queue) to queue2(temporary queue)
		{
			q2.push(q1.front()); //enqueue n-1 items from Queue 1 to Queue2
			q1.pop();
			i++;
		}
		
		front=q1.front(); //storing last element of storage queue Q1 in front
		
		cout<<"Top of stack is "<<front<<endl;
	
		//inserting last element of Q1 to Q2
		q2.push(q1.front());
		q1.pop();
		
		
		//now again transfer all back to storage queue Q1(storage queue) and make Q2 empty,for the condition of this block to be true
		while(!q2.empty()) {
			q1.push(q2.front()); //
			q2.pop();
			
			
		}
			//now Q2(temp queue is again empty)
	}
	
	else {
		size=q2.size();
		
		while(i < size-1) { //transfer n-1 items from Q2(storage queue) to Q1(temp queue) 
			q1.push(q2.front()); //enqueue n-1 items from Queue2 to Queue1
			q2.pop();
			i++;
		}
		front = q2.front();
		
		cout<<"Top of stack is "<<front<<endl;
		
		 
		//insert the last item in Q2(storage queue) to Q1(temp queue)
		q1.push(q2.front());
		q2.pop();
		
		
		//now again transfer all items back to Q2(storage queue) and make Q1 empty
		while(!q1.empty()) {
			
			q2.push(q1.front()); //
			q1.pop();
		
			
		}
		 
		 
		
	}
	
	
}




int main() 
{
	
	Stack s;
	int choice,data;
	while(1)
	{
		
		
		cout<<"\n1)Insert\n2)Delete\n3)Top of stack\n4)Exit\n"<<endl;
		cin>>choice;
		
		
		switch(choice) {
			
			case 1: 
				cout<<"Enter data :"<<endl;
				cin>>data;
				s.Push(data);
				break;
			case 2:
				
				s.Pop();
				break;
			case 3:
				s.Top();
				break;
			
			default:
				exit(0);
				break;
				
		}
	}
	
	return 0;
}
