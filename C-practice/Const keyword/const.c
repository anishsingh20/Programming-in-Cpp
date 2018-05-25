
#include <stdio.h>
 
int main()
{
	union name {
		
		int age;
		};
		
		const union name n;
		//n.age=20; age becomes a read only const object
		printf("%d",n.age);
		
}
 
