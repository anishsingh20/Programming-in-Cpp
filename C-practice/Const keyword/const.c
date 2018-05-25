
#include <stdio.h>
 
int main()
{
	union name {
		
		int age;
		};
		
		const union name n;
		//n.age=20;
		printf("%d",n.age);
		
}
 
