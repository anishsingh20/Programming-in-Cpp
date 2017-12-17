/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
//RECURSIVE SOLUTION to MERGING 2 SORTED LINKED LISTS
Node* MergeLists(Node *headA, Node* headB)
{
    Node *temp = NULL;
   if(headA==NULL) { //if List A is null-our answer is list B
       return headB;
   }
    else if(headB==NULL) {//if List B is null-our answer is list A
        return headA;
    }
      
      
    if(headA->data <= headB->data) 
      {
          temp = headA;
          temp->next= MergeLists(headA->next,headB);
          
      }
      else {
          
          temp=headB;
          temp->next = MergeLists(headB->next,headA);
      }
      
   return(temp);   
  
}

