#include<iostream>


using namespace std;


int main()
{
	int n;
	
	
	cout<<"Enter the limit"<<endl;
	cin>>n;
	
	char ch[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
	
	for(int i = 0 ; i < n ; i++ )
	{
	
		for(int j = 0 ; j < i ; j++)
		{
			
			cout<<ch[j]<<" ";
			
		}
		cout<<ch[i]<<endl;
	}
	
		
	
	return 0;
}
