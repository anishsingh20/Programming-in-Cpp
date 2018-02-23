//CIRCULAR ARRAY IMPLEMENTATION OF QUEUE
#include<iostream>

using namespace std; 
//making the std namespace as global namespace

#define size 10

class Queue{
	public:
		int arr[size]; //array of size 20
		int front,rear; //2 indices to keep track of front and rear or queue and do insertion and deletions
		Queue() {
			front=-1;
			rear=-1;
			 //initlally 
		} //constructor called as soon as a object of class QUEUE is generated
	//method-operations
		void Enqueue(int n);
		void Dequeue();
		void display();
		bool isEmpty();
		bool isFull();	
		void showFront();
		void showLast();
		int showCount();
};

bool Queue::isEmpty() {
	
	return (rear==-1 && front ==-1) ? true:false ;
	
}

bool Queue::isFull() {
	return ( (rear+1)%size == front) ? true : false;
	 //full when next index to rear is front index i.e (rear+1)%N(size of array) == front
	
}

void Queue::Enqueue(int n ) {
	
	if(isFull()) {
	cout<<"Queue is full"<<endl;
	return;
	 
	
	}//array is full
	
	else if(isEmpty()) {
		
	front=rear=0; //make a new cell for adding element
	
	} //array is empty then generate a new cell to insert
	
	else {
		//increment rear and add data from rear of queue
		rear= (rear+1)%size;
		
		
	}
	
	arr[rear]=n;// insert from rear end
	
	
}

void Queue::Dequeue() {
	
	if(isEmpty()) {
	cout<<"Queue is Empty"<<endl;
	return;
	}
	
	//only 1 element in queue i.e when front==rear
	else if(front==rear) {
		
		cout<<"Deleted :"<<arr[front]<<endl;
		front=rear=-1; //now both after deletion will be -1
	} 
	
	else {
		//increment the front index
		cout<<"Deleted :"<<arr[front]<<endl;
		front = (front+1)%size;
	}
	
	
	
	
	
}

void Queue::showFront() {
	if(front==-1) //queue is empty
	{
	
		cout<<"Queue is Empty"<<endl;
		return ;
	}
	
	else {
		
		 cout<<arr[front]<<endl;
	}
}


void Queue::showLast() {
	if(front==-1) //queue is empty 
	{
		cout<<"Queue is Empty"<<endl;
		return ;
	}
	
	else{
		 cout<<arr[rear]<<endl;
	}
}

//to print count of elements in queue
int Queue::showCount() {
	if(isEmpty()) 
	{
	 	 cout<<"queue is empty"<<endl;
	 	 return -1;
	}
	
	else {
		cout<<"\n";
		return (rear+size-front+1)%size;
		
	}	
	
	
}

void Queue::display() {
	
	//finding number of elements in queue
	int count;
	count = ( rear + size - front )%size+1; //counting elements is queue
	for(int i=0 ; i<showCount();i++ ){ 
	
		int index= (front+i)%size; //used to print elements in queue from front 
		cout<<endl<<arr[index]<<endl;
		 //increment front
	} 
	cout<<endl;
}


int main() {
		
	Queue q; //object to access and use Queue operation methods
	int choice;
	int data;
	
	while(1) {
		
		cout<<"\n1)Insert\n2)Delete\n3)Display\n4)Show Front\n5)Show last\n6)Show Count\n7)Exit\n"<<endl;
		cin>>choice;
		cout<<"\n";
		
		
		switch(choice) {
			
			case 1: 
				cout<<"Enter data"<<endl;
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
				q.showFront();
				break;
			case 5:
				q.showLast();
				break;
				
			case 6:
				
				cout<<q.showCount()<<endl;
				break;
				
			default:
				exit(0);//to exit the entire program
				break;
		
		}
	} //end while
	
	return 0;
}
















