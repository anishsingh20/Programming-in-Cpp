#include<iostream>
//Function to find merge point of 2 linked lists

using namespace std;

struct Node {
	struct Node *next;
	int data;
};

//METHOD a) BRUTE FORCE-comparing addresss of nodes in both lists, first matching node is the merge point


//method to return the length of a list-TIME COMPLEXITY-O(n)

int length(struct Node *head) {
	
	int len = 0;
	while(head!=NULL) {
		len++;
		head = head->next;
	}
	
	return len;
	
}

Node *FindMergePoint(Node *headA,Node *headB) {
	//lengths of lists A and B
	int m = length(headA);
	int n = length(headB);
	
	
	
	
}




