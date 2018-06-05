#include<iostream>

using namespace std;


//program to detect a cycle in linked list and remove it.-Asked in Amazon,Microsoft, Ebay etc

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

//function to get the starting of the cycle in a list-uses Floyd's algorithm
ListNode *detectStartCycle(struct ListNode *head) {
    
    	if(!head)
                return NULL ;
        
        struct ListNode *temp = head;
        struct ListNode *temp1 = head;
        
        while(temp1 && temp1->next)
        { 
             
            temp = temp->next;
            temp1 = temp1->next->next;
            
            //cycle is there when both fast and slow are equal
            if(temp==temp1)
            {
                temp1 = head;
        	while(temp!=temp1)
        	{
               		temp = temp->next;
			temp1 = temp1->next;
			
        	}
		
		//returning the first node of the cycle
		return temp;	 
            }
            
        }
        
       return NULL;
}


//main program to remove the cycle by making the last node of cycle point to NULL
struct ListNode *RemoveCycle(ListNode **head)
{
	//getting the starting node of the cycle
	ListNode *start = detectStartCycle(*head);

	ListNode *last = start;
	
	while(last->next!=start)
	{
		last = last->next;
	}
	
	cout<<last->val<<endl;
	//breaking the cycle.
	last->next = NULL;
	return *head;	
}

bool hasCycle(ListNode *head) {
        
	if(head==NULL || head->next==NULL)
    {
        return false;
    }
    
    struct ListNode *temp = head;
    struct ListNode *temp1 = head;
    
    while(temp!=temp1)
    {
       
       if( temp1->next==NULL || temp1==NULL)
       {
           return false;
        }
        
        temp = temp->next;
        temp1 = temp1->next->next;
        
	}
	
	return true;
}


void TraverseList(ListNode *head)
{
	if(head)
	{
		cout<<head->val<<" ";
		TraverseList(head->next);
	}
}

void TraverseCLL(ListNode *head)
{
	ListNode *temp  = head;
	
	while(temp->next!=head)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	 } 
	 
	 
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
	
	n2->next = head;
	
	n3->next = NULL;
	
	

	RemoveCycle(&head);
	
	//to verify if the cycle is removed
	TraverseList(head);
	
	return 0;
	
}
