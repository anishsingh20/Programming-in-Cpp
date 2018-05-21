#include<iostream>


using namespace std;


int main()
{
	int n;
	
	
	cout<<"Enter the limit"<<endl;
	cin>>n;
	
	char ch[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
	
	for(int i = 0 ; i <= n ; i++ )
	{
		cout<<ch[i]<<endl;
		for(int j = 0 ; j <= i ; j++)
		{
			
			cout<<ch[j];
			
		}
		
	}
	
		
	
	return 0;
}
