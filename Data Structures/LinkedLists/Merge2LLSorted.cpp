
 // Merge two sorted lists A and B as one linked list
  //Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }

//RECURSIVE SOLUTION to MERGING 2 SORTED LINKED LISTS
Node* MergeLists(Node *headA, Node* headB)
{
    Node *new_head = NULL;
   if(headA==NULL) { //if List A is null-our answer is list B
       return headB;
   }
    else if(headB==NULL) {//if List B is null-our answer is list A
        return headA;
    }
      
      
    if(headA->data <= headB->data) 
      {
          new_head = headA;
          new_head->next= MergeLists(headA->next,headB);	
          
      }
      else {
          
          new_head=headB;
          new_head->next = MergeLists(headB->next,headA);
      }
      
   return(new_head);   
  
}

//-----------------------------SOLUTION USING REFERENCES and ITERATIVE SOLUTION--------------------


Node* MergeList(Node *headA, Node *headB) {
	Node *new_head=NULL;
	Node *temp; //the ned dummy variable which will keep track of the sorted list
	
	if(headA==NULL) {
		return headB;
	}
	else if(headB==NULL) {
		return headA;
	}
	
	
	//if data in node A < data in node B then assign temp to the smaller node
	if(headA->data <= headB->data) {
		temp=headA;
		headA = temp->next; //head A moves to the next of temp
	}
	else {
		temp=headB;
		headB=temp->next; //headB moves to next of temp
	}
	 
	new_head=temp;// now we need to assign new_head to temp node which is the node with smallest value
	//this new_head will be returned by the function
	
	while(headA && headB) {
		
		if(headA->data <= headB->data)  {
			temp->next=headA;
			temp=headA; 
			headA=temp->next;
		}
		else {
			temp->next=headB; //temp links to headB
			temp=headB;//temp becomes headB node
			headB=temp->next;//headB moves to next to temp
		}
		
	}
	
	if(headA==NULL) temp->next=headB; //when List A is finished
	if(headB==NULL) temp->next=headA; //when list B is finished
	
	return(new_head); //will return the new header of the sorted merged LL
	
	
	
	
	
	
}

