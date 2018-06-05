#include<iostream>

using namespace std;


//program to detect a cycle in linked list and remove it.

/*
1)Method1
We can easily use Hashing or Visited node techniques to get the pointer to the last node. 
Idea is simple: the very first node whose next is already visited (or hashed) is the last node.
If such a node is found then we can set this last node's next to NULL

2)Method 2- Floyd's cycle detection algorithm
 a)Make a function to return the starting node of the cycle using FLoyd's cycle ddtection algo using fast and slow pointers or by using
 hash map(unordered_set).
 b)Then make another function to remove cycle i.e make the last node of cycle point to NULL starting from the start of cycle.
*/


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


bool RemoveCycle(ListNode *head)
{
	
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
