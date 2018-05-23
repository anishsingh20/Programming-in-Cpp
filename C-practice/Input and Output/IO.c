#include<stdio.h>
#include<conio.h>



int main()
{
	char ch[20] = "Anish Walia";
	char *fp = fopen("a.txt","r+");//open the file in write mode
	
	fputs(ch,fp); //writing the the file
	
	char chr[30];
	
	while(ch = fgets(strlen(fp)) != EOF)
	{
		
	}
	
	return 0;
}
