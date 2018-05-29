#include<stdio.h>

union n {
	int age;
	int sal;
		
	};
int main(){
	
  union n n1={10,250};
  //error as when defining a union variable, we can only initialize one member 
  
	printf("%d",n1.age);
	}
