#include<iostream>
#include "SingleLLRotation.cpp"
#include "SIngleRRrotation.cpp"

using namespace std;


struct AVLnode {
	
	int data,height;
	struct AVLnode *left,*right;	
};



AVLnode *DoubleLeftRightRotation(AVLnode *X)
{

	X->left = SingleRightRotation(X->right);
	
	return SingleLeftRotation(X);  
}
