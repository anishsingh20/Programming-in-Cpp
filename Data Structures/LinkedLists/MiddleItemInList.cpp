#include<iostream>

/*SINGLY LINKED LIST-Program to find Middle element in a linked list-IMP INTERVIEW QUESTION
3 Methods-
1)Using fast and slow pointers.
2)Using the count of list and traversing till count/2 elements.
3)using count and strating from mid as head, increment mid when count is odd.Then when head reaches NULL,
the mid will only be at the middle. 


*/

using namespace std;

struct node {
	int data;
	struct node *next;
};



//Approach-1 : Using fast and slow pointers, when fast pointer reaches NULL, then the slow one will always be at middle of list
struct node *midItem(struct node *head)
{
	struct node *temp=head;//slow pointer
	struct node *temp1=head;//fast pointer
	
	if(!head)
		return NULL;
		
	
	//important condition-until fast pointer is not null and fast pointer's next is not null
	//it is because both are required in case of odd and even elements in list	
	while(temp1 && temp1->next)
	{
			
			temp1 = temp1->next->next;//move temp1 by 2
			temp = temp->next; //move temp by 1
	}
	
	
	return temp;		
	
}



//finding length of a List
int length(struct node *head) {
	
	int len = 0;
	while(head!=NULL) {
		len++;
		head = head->next;
	}
	
	return len;
	
}


//Approach 2 Using length of list and simply finding middle element
//function to get the Middle of a list
int MiddleNode(struct node **head,int start=0) 
{
	
	
	if(*head==NULL) 
	{
		cout<<"list enpty"<<endl;
	}
	
	int len = length(*head);
	int mid = (start + (len-start)/2 );
	struct node *temp=*head;
	for(int i=0;i<mid;i++)
		temp=temp->next;
		
	return temp->data; 

}


int MiddleOddCount(node *head)
{
	node *mid = head;
	int count=0;
	
	while(head)
	{
		//if count is odd, then increment mid to next
		if(count & 1)
			mid = mid->next;
			
		++count;
		head = head->next;
	}
	
	return mid->data;
}


struct node *newNode(int data)
{
	node *temp = new node();

	
	temp->data = data;
	
	temp->next = NULL;
	
	return temp;
}


//program to find nth node from end in a linked list
int printfromTail(node *head,int postail) {
	node *temp=head;
	node *result=head; //a pointer to store the address of kth element from tail
	
	int k=0;
	
	//traversing the list
	while(temp!=NULL) {
		
		
		if(k++ > postail) {
			
			result=result->next;
			
		}
		
	
		
		temp=temp->next;
	}
	
	return result->data;
}


int main()
{
	node *head = newNode(1);
	
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	head->next->next->next->next->next = newNode(6);
	head->next->next->next->next->next->next = newNode(7);
	
	
	cout<<midItem(head)->data;
	cout<<endl;
	cout<<MiddleOddCount(head);
	
//	cout<<endl;
//	
//	cout<<printfromTail(head,2);
//	cout<<endl;
//	cout<<MiddleNode(&head);
	
	
}
