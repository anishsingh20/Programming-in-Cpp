#include<iostream>
#include<string.h>

using namespace std;

void substr(char *t,char *s,int pos,int len)
{
	t[0] = '\0';
	
	
	
	strncat(t,s+pos,len);
}

int main()
{
	char s[] = "aaanish Singh";
	char t[25];
	
	substr(t,s,1,3);
	
	printf("%s",t);
	
	return 0;
}
