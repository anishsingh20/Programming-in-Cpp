#include<stdio.h>
#include<conio.h>



int main()
{
	char ch[10] = "Anish";
	char *fp = fopen("a.txt","w");//open the file in write mode
	
	fputs(ch,fp); //writing the the file
	
	return 0;
}
