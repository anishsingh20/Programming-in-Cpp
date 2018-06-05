#include<iostream>

using namespace std;


//program to detect a cycle in linked list and remove it.

struct ListNode {
	
	int val;
	ListNode *next;
};


ListNode *newNode(int data)
{
	ListNode *temp = new ListNode();
	
	temp->val = data;
	
	return temp;
}

int main()
{
	struct ListNode *head = newNode(1);
	
	struct ListNode *n1 = newNode(2);
	
	struct ListNode *n2 = newNode(0);
	
	struct ListNode *n3  = newNode(4);
//	
	
	head->next = n1;
	n1->next = n2;
	
	n2->next = n3;
	
	n3->next = n2;
	return 0;
	
}
