#include<iostream>

using namespace std;


struct Node {
	
	int data;
	Node *next,*prev;
};



//simply traversing the list in reberse order-by first traversong till end of list, then simply swapping next and prev pointers and printing
void reverseRec(Node *head)
{
	Node *temp;
	
	if(!head) return;
	
	//traverse till end of list
	reverseRec(head->next);
	
		cout<<head->data<<"<->";
		temp=head->next;
		head->next = head->prev;
		head->prev = temp;
			
		
		
		
}


void Traverse(Node *head)
{
	if(head)
	{
		cout<<head->data<<"<->";
		
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
	
	
//	Traverse(head);
	
	reverseRec(head);
	
	
//	Traverse(head);
	
	return 0;
}
