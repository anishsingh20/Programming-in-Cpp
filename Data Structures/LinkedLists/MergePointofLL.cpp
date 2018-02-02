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
	
	struct Node *temp = headB;
	//trversing lists
	
	for(int i=0; i < m ;i++) {
		
		//resetting headB to starting node
		headB = temp;
		
		for(int j=0; j < n; j++) {
			//comparing address
			if(headA==headB) {
				//the address or pointer to the merge point
				cout<<headA->data<<endl;
				return headA;
			}
			
			headB=headB->next;
			
		}
		headA= headA->next;
	}
	return NULL;
}
//Inefficient-TIME CPMPLEXITY - O(mn) and high space complexity due to use of pointers



int main() {
	
	//List A
	struct Node *n1 = new Node();
	struct Node *n2 = new Node();
	struct Node *n3 = new Node();
	struct Node *n4 = new Node();
	
	n1->data = 1;
	n2->data = 3;
	n3->data = 4;
	n4->data = 6;
	
	//creating links
	
	n1->next = n2;
	n3->next = n4;
	n2->next = n3;
	n4->next = NULL;
	
	//LIST-A
	//1(n1) --> 3(n2) --> 4(n3) --> 6(n4) -->NULL
	
	//List B
	struct Node *m1 = new Node();
	struct Node *m2 = new Node();
	struct Node *m3 = new Node();
	
	
	m1->data = 2;
	m2->data = 5;
	m3->data = 4;

	//LIST-B
	//2(m1) --> 5(m2) --> 4(n3) --> NULL
	
	//creating links
	m1->next = m2;
	m2->next = n3;
	n3->next = NULL;
	
	
	cout<<FindMergePoint(n1,m1);
	//in this case the Merge point is node n3 which is common in both

	
	
	
	
}


