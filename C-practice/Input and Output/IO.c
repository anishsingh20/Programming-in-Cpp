#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



int main()
{
	
//	FILE *fp = fopen("a.txt","r");//open the file in write mode
//
//
//	char ch[10];
//	fseek(fp,-5L,SEEK_END);
//	fgets(ch,5,fp);//ie store 4 items from the 6 digit in file a.txt 
//	
//	/*It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached,
//	 whichever comes first
//	 */
//	puts(ch);
	
	//program2
	int n;
	scanf("%*d",&n);//* symbol after * means. current input is scanned but not stored
	printf("%*d",n,n);//will print only 2 ,* after % in printf() means field width
	
	return 0;
}


