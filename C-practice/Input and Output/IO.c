#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



int main()
{
	
	FILE *fp = fopen("a.txt","r+");//open the file in write mode


	
	char chr[20];
	
	if( fgets(chr,20,fp) != NULL)
	{
		puts(chr);	
	}
	
	fclose(fp);
	
	return 0;
}
