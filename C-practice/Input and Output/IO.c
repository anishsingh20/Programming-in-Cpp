#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



int main()
{
	
	FILE *fp = fopen("a.txt","r");//open the file in write mode
	
//	fputs(ch,fp); //writing the the file
	
	char chr[20];
	
	if( fgets(chr,20,fp) != NULL)
	{
		fseek(fp,3L,5);
		puts(chr);	
	}
	
	fclose(fp);
	
	return 0;
}
