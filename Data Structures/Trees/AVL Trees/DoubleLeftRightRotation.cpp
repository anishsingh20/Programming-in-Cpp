#include<iostream>


using namespace std;


struct AVLnode {
	
	int data,height;
	struct AVLnode *left,*right;	
};



AVLnode *DoubleLeftRightRotation(AVLnode *X)
{

	X->left = SingleRightRotation(X->left);
	
	return SingleLeftRotation(X); 
	
}
