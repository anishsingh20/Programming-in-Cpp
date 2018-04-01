//algorithm to find reverse inorder traversal using morris traversal based on inorder successor of current node

void MorrisReverseInorder(Node *root)
{
	
	if(!root)	return ;
	
	Node *curr,*Insuccessor;
	
	curr=root;
	
	while(curr)
	{
		//case 1 if curr has no rightchild then visit current and move to left child
		if(curr->right==NULL)
		{
			cout<<curr->data<<" ";
			curr = curr->left;
		}
		
		else
		{
			//find the inorder successor of current node i.e left most node in right subtree or right child itself
			Insuccessor = curr->right;
			
			while(Insuccessor->left!=NULL && Insuccessor->left!=curr)
				Insuccessor = Insuccessor->left;
				
			//if the left of inorder successor is NULL
			if(Insuccessor->left==NULL)
			{
				//then connect left link to current node
				Insuccessor->left = curr;
				
				//move current to right child
				curr = curr->right;
			}
			
			//otherwise inorder successor's left is not NULL and already left is linked with current node
			elsex
			{
				Insuccessor->left=NULL;
				
				//visiting the current node
				cout<<curr->data<<" ";
				
				curr = curr->left;
			}
		}
	}
	
	
}

