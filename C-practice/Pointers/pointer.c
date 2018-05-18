#include<stdio.h>
#include<conio.h>
#include<string.h>




	void fun(char *p)
	{
		if(p[0]=='\0') return;
		
		fun(p+1);
		fun(p+1);
	
		
		printf("%c",p[0]);
	}


int main()
{
	//Program 1
//	int a[3][4] = {2,3,4};
//	
//	printf("%u %u %u",a[0] + 1, *(a[0] + 1 ) , *(*(a + 0) + 2 ) ) ;
	//prints address of 2, 3 , 4 
	
	
	//program 2
	
//	int a[3] = {3,5,6};
//	
//	char *ptrc = (char*)a;
//	
//	printf("%d ",*ptrc);
//	printf("%d \n",*ptrc + 1); //prints 4, value incremented by 1
//	
//	ptrc = ptrc + 1; // or *ptr++; //address incremented to next byte
//	printf("%d \n", *ptrc); //value is 0
//	
//	int arr[5];
//	char arrc[5];	
//	printf("%d %d\n",sizeof(arr),sizeof(&arr)); //&arr is the size of pointer 8 bytes
//	
//	printf("%d %d\n",sizeof(arrc),sizeof(&arrc));//prints 5 and 8 as c char
//	
//	int b = 5;
//	printf("%d %d",sizeof(b),sizeof(&b)); // prints 4 and 8
	
	//program 3
	
	
//	float a=10.5576;
//	float *j;
//	
//	void *k;
//	
//	k = &a;
//	
//	j = k; //usually we require to typecast a void pointer when assigning values to and from a void pointer
	//conversions are done automatically in gcc compilers

//	printf("%lf ", *j );
	

	//program 4
	
//	int a[] = {10,20,30,40,50};
//	
//	char *p  = (char*)a;//p points to the base address(address of 1st byte) of a i.e points to 10
//	
//	p = (p + 16); //p now points to 50, as c char is 1 byte long
//
//	int *p1 = a;
//	
//	printf("%d %d",*p,*(p1+4)); //both will point to 50
	
	
	//program 5
		 
//	printf("%c",1["anish"]); //would print i
	
	
	//program 6
	
//	char *ch = "anish";
//	
//	int j=65;
//	
//	void *pt ;
//	
//	pt = ch;
//	
//	printf("%c ",  *((char*)pt+3)  + 2); //prints u
//	
//	pt = &j;
//	
//	printf("%c", *( (int*)pt) + 1 );//prints B
//	
	
	
	
	
	//program 7
	
//	fun("123"); make a recursion tree

		
	//program 8
	
//	void *vp;
//	char ch = 74; 
//	char *cp = "JACK";
//	
//	int j = 65;
//	
//	vp = &ch;
//	
//	printf("%c",*(char*)vp); prints J
//	
//	vp = &j;
//	
//	printf("%c",*(char*)vp); prints A
//	
//	vp = cp;
//	
//	printf("%s",(char*)vp+2); //imp-will print CK
	
	
	//program 9
	
//	static char *s[] =  {"black","red","pink","violet"};
//	char **ptr[] = {s+3,s+2,s+1,s},***p;
//	
//	p = ptr;
//	
//	++p;//goes to s+2
//	printf("%s\n",**p+1);//prints ink
//	
//	printf("%s",**(p+1));//goes to s+2 , goes to next element i.e s+1 prints red
	
	
	//program 10
	
//	char *s = "Anish";
//	
//	int n = strlen(s);
//	
//	
//	for(int i=0 ; i<n ; i++)
//	{
//		printf("%s ",s++); 
//		//%s is for strings
//		
//	}


	//program 11
	
//	char str1[] = "anish" ; 
//	char str2[] ="walia" ;
//	
//	char *s1 = str1;
//	char *s2 = str2;
//	while( *s1++ = *s2++); //values changes in s1 pointer will be refelected in str1
		
//	printf("%s",str1); //str1 now becomes walia
	

	//program 12
	
//	int a[5] = {5,1,15,20,25};
//	int i,j,m;
//	
//	i = ++a[1];//i becomes 3
//	printf("%d \n ",a[1]);// a[1] has become 2
//	j = a[1]++; // j is 2
//	
//	
//	
//	m = a[i++]; // m is 15
//	
//	//postfix operator associativity is from left to right
//	
//	printf("%d %d %d",i,j,m);
//	
	
	
	
	
//	char s[20] = "Hello";
//	
//	char *const p = s; //value at s[0] will change, even if p is a const pointer
//	
//	*p = 'M';
//	
//	printf("%s",s);

	
	
	//program 13
	char a[] = "anish";
	
	char *b = "walia";
	
	printf("%d %d\n", sizeof(a),sizeof(b));
	
	printf("%c %c\n",*a,*b); //values at the base address so they are character, hence they are 1 bytes long
	
	
	printf("%d %d\n", sizeof(*a),sizeof(*b));
		
		
		
	
	return 0;
	
	
}
