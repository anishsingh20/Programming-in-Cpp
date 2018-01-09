#include<iostream>

//SINGLY LINKED LIST
using namesapce std;

struct Node {
	int data;
	Node *next;
};

Node *head;

/*BASIC OPERATIONS- 1)INSERTION-Insertion at beginning-O(1) , insertions at end-O(n) , insertion in middle-O(n)
		    2)DELETION
		    3)TRAVERSAL	-O(n)
*/


//Function to traverse the list and return the count of items in LL

int listlength() {
	Node *current = head;
	int count = 0 ;
	while(current!=NULL) {
		count++;
		cout<<current->data<<" | "<<"\t";
		current=current->next;
	}
	
	return count;
}



