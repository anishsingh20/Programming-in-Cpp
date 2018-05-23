#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



int main()
{
	
	FILE *fp = fopen("a.txt","r");//open the file in write mode


	char ch[10];
	fputs(ch,fp);
	fseek(fp,6L,SEEK_CUR);
	fgets(ch,5,fp);//ie store 4 items from the 6 digit in file a.txt 
	
	/*It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached,
	 whichever comes first
	 */
	puts(ch);
	
	return 0;
}
