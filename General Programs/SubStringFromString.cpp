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
	return 0;
}
