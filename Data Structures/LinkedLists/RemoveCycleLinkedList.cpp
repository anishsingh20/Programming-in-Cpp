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
	return 0;
	
}
