#include<iostream>

using namespace std;


struct Node {
	
	int data;
	Node *next,*prev;
};




//function to reverse a doubly linked list using recursion and return the new head
Node  *reverseRec(Node *head)
{
	Node *temp;
	
	
	if(!head) return NULL;
	
	//first swap the next and prev pointers
	temp=head->next;
	head->next = head->prev;
	head->prev = temp;

	//if prev becomes NULL, this means we have reversed the list and reached end
	if(head->prev==NULL)
	{
		
		return head;	
	}	
	
	//otherwise simply keep swapping next nd prev until we reach the end and prev becomes NULL
	return reverseRec(head->prev);		
}


int maxOccuringItem(Node *head)
{
	if(head==NULL)	return -1;
	
	Node *temp=head;
	Node *temp1;
	while(temp!=NULL)
	{
		temp1 = temp;
		while(temp1->next!=NULL)
		{
			if(temp->data==temp1->next->data)
			{
				return temp->data;	
			}
			
			temp1 = temp1->next;
		}
		temp =temp->next;
	}
	return 0;
}


//simply traversing the list in reverse order-by first traversong till end of list, then simply swapping next and prev pointers and printing
void reversePrint(Node *head)
{
	Node *temp;
	if(!head) return;
	
	//first reach till end of list
	reversePrint(head->next);
	
	//now first print and simply swap the next and rprev pointers
//	cout<<head->data<<"<->";
//	
//	//swapping the next and prev pointers
//	temp=head->next;
//	head->next = head->prev;
//	head->prev = temp;

	cout<<head->data<<"<->";	
}


void printAlternateRec(Node *head,bool odd=true)
{
	if(head==NULL) return ;

	if(odd==true)
	{
	
		
		cout<<head->data<<"<->";
		
		
	}	
	
	//this bool variable will make sure to print alternate nodes
	printAlternateRec(head->next,!odd);	
}



void printOddEvenNodes(Node *head,bool even=false)
{
	if(head==NULL) return;
	
	if(even==true)
	{
		
		cout<<head->data<<"->";
		
		
	}
	
	printOddEvenNodes(head->next,!even);
}



void Traverse(Node *head)
{
	if(head)
	{
		cout<<(head)->data<<"<->";
		
		Traverse(head->next);
	}
}

using namespace std;


int main()
{
	struct Node *head = new Node();
	struct Node *n1 = new Node();
	struct Node *n2 = new Node();
	struct Node *n3  = new Node();
	struct Node *n4 = new Node();
	
	
	head->data=1;
	n1->data=2;
	n2->data=3;
	n3->data=4;
	n4->data=5;
	
	
	head->next = n1;
	head->prev=NULL;
	
	n1->next=n2;
	n2->next = n3;
	n3->next=n4;
	n4->next=NULL;
	
	n1->prev=head;
	n2->prev=n1;
	n3->prev=n2;
	n4->prev=n3;
	
	
	Traverse(head);
	
	cout<<endl;
	
	cout<<"Odd position nodes are:"<<endl;
	
	printAlternateRec(head);
	cout<<endl;
	
	cout<<"Even position nodes are:"<<endl;
	printOddEvenNodes(head);

	
	
//	cout<<endl;	
//		
	cout<<maxOccuringItem(head);
	//storing the new head	
//	Node *new_head = reverseRec(head);
//	
//	Traverse(new_head);//list reversed
	
	return 0;
}
