#include<iostream>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;

queue<int>q;

void Push(stack<int>&s,int data);
int Delete(stack<int>&s);
void display(stack<int>s);


void Push(stack<int>&s,int data) {
	
	s.push(data); //simply Enqueue data into queue from front
	
}

int Delete(stack<int>&s) {
	
	if(s.empty()) {
		cout<<"Stack is empty"<<endl;
		return 0;
	}
	cout<<"\n";
	//now dequeue from the front of queue
	int item=s.top();
	s.pop();
	
	return item;
	
}

void display(stack<int>s)
{
	if(s.empty()) {
		cout<<"Stack is Empty"<<endl;
		return;
	}
	
	cout<<"Top->";
	while(!s.empty()) {
		
		
		cout<<"\t"<<s.top()<<endl;
		s.pop();
		
		cout<<"\t"<<"--"<<endl;
		
	}	
	
	
}


// TIME COMPLEXITY and SPACE COMPLEXITY of this function- O(n) ,as transfer of items are being done from queue to stack and stack to queue
int checkConsecutive(stack<int>&s) { 
	
	if(s.empty()) {
		
		cout<<"Stack is empty"<<endl;
		
	}
	
	if(s.size()%2!=0) {
		
		return 0; //not consecutive as there are odd number of items and all cannot be paired
		
	}
	
	int pairwiseOrdered=1;
	
	//Transfer all items from Stack to Queue
	while(!s.empty()) {
		
		q.push(Delete(s));
		
	}
	
	//Again transfer all items from queue to stack
	while(!q.empty()) {
		
		Push(s,q.front());
		q.pop();
	}
	
	
	while(!s.empty()) {
		int n  = Delete(s);
		q.push(n);
		
		
		if(!s.empty()) {
			
			int m = Delete(s);
			q.push(m);
			
			
			//condition if the 2 pairs are not consecutive i.e their absulute diff is not 1
			if(abs(n-m)!=1) {
				
				pairwiseOrdered=0;
				
			}
			
		}
		
	}
	

	
	//again at the end pushing all items back to stack, to avoid errors
	while(!q.empty()) {
		s.push(q.front());
		q.pop();
	}
		
	return pairwiseOrdered;	
	
	
	
	
	
 	
}


int main () {
	int choice;
	stack<int>s;
	
	while(1){
		cout<<"\n";
		cout<<"\n1)Insert\n2)Delete\n3)Check Consecutive\n4)Display\n5)Exit\n"<<endl;
		cin>>choice;
		cout<<"\n";
		
		switch(choice) {
			
			case 1: 
				int data;
				cout<<"Enter data :"<<endl;
				cin>>data;
				Push(s,data);
				break;
			case 2:
				
				cout<<"Deleted :"<<Delete(s);
				break;
				
			case 3:
				if(checkConsecutive(s)==1) {
					cout<<"Pairs are consecutive"<<endl;
				}
					
				else {
					cout<<"Pairs are not consecutive"<<endl;
				}
				
				break;
				
			case 4:
				display(s);
				break;
				
			default:
				exit(0);
				break;
				
		}
	}
	return 0;
	
	
	;
	return 0;
}
