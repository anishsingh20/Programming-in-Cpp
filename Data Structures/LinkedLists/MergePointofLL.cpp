#include<iostream>
#include<set>
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


//Method-b-using SETS to store address of nodes in list B - SETS are implementd using BST -and the ops have Logarithmic time -O(logn)
Node *FindMergePointUsingSet(Node *headA , Node *headB) {
	
	//lengths of lists A and B
	int m = length(headA);
	int n = length(headB);
	
	set <Node *> add;
	
	
	//inserting address of nodes in Set
	for(int i = 0 ; i < n ; i++) { //O(nlogn)
		
		add.insert(headB);//O(logn)
		headB = headB->next;
	}
	
	
	for(int i = 0 ; i < m; i++) { //O(mlogn)
		
		//finding address of List A in SET
		if(add.find(headA) != add.end()) { //O(logn)
			
			cout<<headA->data<<endl;
			return headA;
		}
		
		headA=headA->next;
	}
	
	return NULL; //if no merge point
		
}//Overall TIME CPMPLEXITY = O(nlogn + mlogn) , but has high space complexity  = O(n^2)




//Recursive implementation to find merge point of 2 linked lists
int MergePointRecursion(Node *headA, Node *headB)
{
	//base condition
	if(headA==NULL && headB==NULL)
		return 0;
				
	if(headA==headB)
	{
//		cout<<headA->data;
		return headA->data;
	}
		
	if(headA && headB)
	{
		
		//recursively traverse the list A and compare the addresses
	
		int A = MergePointRecursion(headA->next,headB);
		
		if(A) 
		{
			return A;
		}
		
		//recursively traverse the list B and compare the addresses
		else return MergePointRecursion(headA,headB->next);
	}
	
	
}



//Method-3 :BEST POSSIBLE SOLUTION

Node *FindMergePointUsingDiff(Node *headA, Node *headB) {
	
	int m = length(headA);
	int n = length(headB);
	
	int d = (n-m);
	
	//if list A is greater in size then simply swap the pointers to head node
	if(m>n) 
	{
	
	  Node *temp = headA;
	  headA=headB;
	  headB=temp;
	  	  
	  int d = (n-m);
	  	
	  
	}
	
	//traversing d nodes in list B to reach at same length of List A
	for(int i=0 ; i<d ; i++) { //O(m+n)
		headB = headB->next;
	}
	
	//now both pointers headA and headB are equidistant from the merge point if any-so we only need a single loop
	
	while( headA!=NULL && headB!=NULL ) {
		
		//comparing the address in lists
		if(headA==headB) {
	
			return headA;
		}
		headA = headA->next;
		headB = headB->next;
		
	}
	return NULL;
}
//Most efficient approach- T(n) = O(m+n) , space complexity = O(1)



int main() {
	
	//List A
	struct Node *n1 = new Node();
	struct Node *n2 = new Node();
	struct Node *n3 = new Node();
	struct Node *n4 = new Node();
	
	n1->data = 1;
	n2->data = 3;
	n3->data = 10;
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
	
	
	cout<<FindMergePointUsingDiff(n1,m1)->data;
	cout<<endl;
	
	cout<<MergePointRecursion(n1,m1);
	//in this case the Merge point is node n3 which is common in both

	
	
	
	
}


