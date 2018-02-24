#include<stdio.h>
#include<conio.h>
#include<cstdlib>


//program to implement Queue using linked list in C

struct node {
	int data;
	node *next;
};


//pointer for queue
struct node *front=NULL,*rear=NULL;



bool isEmpty()
{
	if(front==NULL && rear==NULL)
		return true;
		
		
	return false;
}

int Front()
{
	
	if(isEmpty())
		return -1;
		
	else return front->data;
}


int Rear()
{
	if(isEmpty()) return -1;
	
	else return rear->data;

}


void Enqueue(int data)
{
	struct node *new_node = (node*)malloc(sizeof(node));
	
	new_node->data = data;
	new_node->next = NULL;
	
	//if queue is empty initially
	if(isEmpty())
	{
		//both front and rear will point to same node
		front = rear = new_node;
	}	
	
	//insertion form rear end
	rear->next = new_node;
	rear = new_node;
	
}


int Dequeue()
{
	node *temp=front;
	if(isEmpty())
	{
		return 0;	
	}	
	
	//queue has only 1 item
	if(front==rear)
	{
		front=rear=NULL;	
	}
	
	//deletion from front
	else
	{
		front=front->next;
		
	}
	
	return temp->data;
	
	delete(temp);
}


void display()
{
	node *temp = front;
	
	while(temp != NULL)
	{
		printf("%d | ",temp->data);
		temp=temp->next;
	}
	
}


int main()
{
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	Enqueue(50);
	
	display();
	
	printf("\n");
	
	printf("Front = %d\n",Front());
	
	printf("Rear = %d\n",Rear());
	
	printf("Deleted Item is %d ",Dequeue());
	
	
	
	
		
}
