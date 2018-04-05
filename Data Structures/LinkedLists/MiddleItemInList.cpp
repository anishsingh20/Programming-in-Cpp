#include<iostream>

//SINGLY LINKED LIST
using namespace std;

struct node {
	int data;
	struct node *next;
};




node *midItem(struct node **head)
{
	struct node *temp,*temp1;
	
	if(!head)
		return NULL;
		
	temp = *head;
	temp1 = *head;//pointer which moves 2 steps
		
	while(temp && temp1)
	{
		
		temp = temp->next;
		temp1 = temp1->next->next;
		
		
	}
	
	if(temp)
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


struct node *newNode(int data)
{
	node *temp = new node();

	
	temp->data = data;
	
	temp->next = NULL;
	
	return temp;
}

int main()
{
	node *head = newNode(1);
	
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	
	
	cout<<midItem(&head)->data;
	
	
	cout<<endl;
	
	cout<<MiddleNode(&head);
	
	
}
