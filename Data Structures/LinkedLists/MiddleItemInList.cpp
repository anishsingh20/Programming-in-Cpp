#include<iostream>

//SINGLY LINKED LIST
using namespace std;

struct node {
	int data;
	struct Node *next;
};




struct node* midItem(struct node* head)
{
	node *temp,*temp1;
	if(!head)
		return NULL;
	temp = head;
	temp1= head;//pointer which moves 2 steps
		
	if(temp && temp1)
	{
		midItem(temp->next);
		if(temp1->next!=NULL)
			return midItem(temp1->next->next);
			
		if(temp1->next==NULL)
			return temp;
		
		
	}
}


struct node *newNode(int data)
{
	node *temp = new node();
	temp->next=NULL;
	
	temp->data = data;
	
	return temp;
}

int main()
{
	node *head = newNode(1);
}
