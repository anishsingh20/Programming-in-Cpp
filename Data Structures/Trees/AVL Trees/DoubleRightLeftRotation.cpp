#include<iostream>

using namespace std;


struct AVLnode {
	
	int data,height;
	struct AVLnode *left,*right;	
};



AVLnode *DoubleRightLeftRotation(AVLnode *X)
{
	X->right = S::SingleLeftRotation(X->right);
	
	return N::SingleRightRotation(X);  

}
