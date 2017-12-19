#include<iostream>
#include<queue>
#include<stack>

//reversing first K items of a queue using stack

using namespace std;

void display(queue<int>q);//function declaration-forward scoping

stack <int> s;

void reverseFirstK(queue <int> &q) {
	int k;
	cout<<"Enter K items to reverse:"<<endl;
	cin>>k;
	//corner cases if K > size of queue and or queue is empty	
	if(q.empty() || k>q.size()) {
		return;
	}
	
	if(k<0) {
		cout<<"invalid value of K"<<endl;
		return;
	}
	
	//push first K items of queue to stack
	for(int i=0;i<k;i++) {
		s.push(q.front());
		q.pop(); //dequeue first K items from queue and push them to stack
	}
	
	//now again enqueue those K items from stack to back of queue, now these K items are in revresed form
	while(!s.empty()) {
		q.push(s.top());
		s.pop(); //pop K items from stack and enqueue them to queue until stack gets empty
		
	}
	
	//now the K items in revresed form at at rear of queue, to preserve the order, we will dequeue the remaining size(queue)-k items
	//and enqueue them to the rear of queue.
	for(int j=0; j< q.size()-k;j++) {
		q.push(q.front());
		q.pop(); //enqueue remaining queue.size-k items which were not pushed to stack, to back of queue to preserver the order
		//and print only the first K items in reversed form
	}
	
	
	
	
	 
}


void display(queue<int> q) 
{
	if(q.empty()) {
		cout<<"Queue is empty"<<endl;
		return;
	}
	
	while(!q.empty()) {
		
		cout<<q.front()<< " | ";
		q.pop();
	}
	cout<<endl;
	cout<<"\n";
	
	
	
}



//recursive solution

//void reverseQueueFirstKElementsRecur(int k, queue<int>& Queue)
//{
//if (k == 0)
//return;
//
//int tmp = Queue.front();
//Queue.pop();
//reverseQueueFirstKElementsRecur(k - 1,Queue);
//Queue.push(tmp);
//}
//
//void reverseQueueFirstKElements(int k, queue<int>& Queue)
//{
//if (Queue.empty() == true || k > Queue.size())
//return;
//if (k <= 1)
//return;
//reverseQueueFirstKElementsRecur(k,Queue);
//
//for(unsigned int i = 0; i < Queue.size() - k; ++i)
//{
//Queue.push(Queue.front());
//Queue.pop();
//}
//}



int main() {
	
	
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50); //Queue -10 20 30 40 50
	
	display(q); 
	
	
	reverseFirstK(q);


	display(q); //will print the first K items of queue in reversed order
	
	return 0;
	
	
}

