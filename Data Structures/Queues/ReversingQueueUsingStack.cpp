#include<iostream>
#include<stack>

using namespace std; //assigning std namespace to global namesapce


//a node has 2 fields -data and a pointer next -points or stores mem address of next node in list
struct Node {
	int data;
	Node *next;
};

class Queue {
	public :
		Node *front,*rear;
		//front to store the address of first node, rear will store the address of last node
		
		//constructor is called each time a object of class is build
		Queue() {
			front=rear=NULL;//initially both pointer null
 		}
 		
 		void Enqueue(int n) ;
 		int Dequeue();
 		void display();
 		void ReverseQueue();
 		void showFront();
 		void showLast();
 		bool isEmpty();
};


void Queue::showFront() {
	if(isEmpty()) {
		cout<<"Queue is empty"<<endl;		
	}
	
	else {
		cout<<"First :"<<front->data<<endl;
		
	}
}


void Queue::showLast() {
	if(isEmpty()) {
		cout<<"queue is empty"<<endl;
	}
	else {
		cout<<"Last :"<<rear->data<<endl;
	}
	
	
}

void Queue::Enqueue(int n) {
	Node *temp = new Node(); //making a temp node 
//	cout<<"Enter data in queue"<<endl;
//	cin>>n;
	temp->data = n;
	temp->next=NULL; //initiall temp is not connected to any node
	
	if(isEmpty()){
		
		//connect front and rear to temp if queue is empty
		front=rear=temp;
		
	}
	//if not empty
	//insert from rear end
	rear->next=temp;
	rear=temp;
	
}


int Queue::Dequeue()
 {
 	Node *temp=front;//initially temp node points to front of queue-i.e first element 
 	//if queue is empty
 	if(front == NULL) {
		cout<<"Queue is Empty\n";
		return 0;
	}

	//SPECIAL CASE-if queue has only one element-then front==rear
	else if(front == rear) {
				
		front = rear = NULL;//now queue is empty , so both as NULL
	}
	
	//delete node from front end
 	else {
 		
 		front=front->next; //front now points to its next immediate node
 		
	 }
	 
	 //cout<<"deleted element from front is : "<<temp->data<<endl;
	 return(temp->data);
	 //deallocating memory to the temp node
	 //delete(temp);	
 }
 
 bool Queue::isEmpty() {
 	if(front==NULL && rear==NULL) {
 		return true;
	 }	
	 else {
	 	return false;
	 }
 }
 
 
 void Queue::display() {
 	Node *temp=front; //starting from front
 	//if empty
 	if(isEmpty()) cout<<"ERROR, Queue is empty"<<endl; 
 		
	 //until temp is not NULL
	 while(temp != NULL) {
	 	cout<<temp->data<<"\t";
	 	temp=temp->next; //increment temp
	 }
	 
	 cout<<"\n";
	 
}

//we will use a stack to Reverse a Queue-
void Queue::ReverseQueue() {
	stack<int>s;
	//until Queue is not empty-Push dequeued elements from Queue to stack
	while(!isEmpty()) {
		//PUSH to STACK
		s.push(Dequeue());
		
	}
		
	//Now Until Stack is not empty, Enqueue the popped elements from top of Stack to Queue 
	
	while(!s.empty()) {
		Enqueue(s.top()); //inserting top element of stack to queue
		s.pop();//deleting from top of stack
	}
	cout<<"Reversed queue is--:"<<endl;
	//The queue now has elemens in reversed order
	display();//calling display function
 }
 
int main() {
	
	Queue q; //object to access and use stack operation methods
	int choice;
	int data;
	
	while(1) {
		
		cout<<"\n1)Insert\n2)Delete\n3)Display\n4)Reverse Queue\n5)Show Front\n6)Show last\n7)Exit\n"<<endl;
		cin>>choice;
		
		
		switch(choice) {
			
			case 1: 
				cin>>data;
				q.Enqueue(data);
				break;
			case 2:
				q.Dequeue();
				break;
			case 3:
				q.display();
				break;
			case 4:
				q.ReverseQueue();
				break;
			case 5:
				q.showFront();
				break;
			case 6:
				q.showLast();
				break;
			default:
				exit(0);//to exit the entire program
				break;
		
		}
	} //end while
	
	return 0;
}

