#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

long MedianDiff(int *v,int size)
{
	vector<int>s;//to store the differences
	int i = 0 ;
	int j = size-1;
	
	while(i<j)
	{
		//again finding difference between all items of array
		while(i<j)
		{
			s.push_back(abs(v[i]-v[j--]));
		}
		
		j = size-1;	
		i++;
	}
	
	for(vector<int>::iterator it = s.begin(); it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
}

int main()
{	
	int v[] = {1,3,2,4};
	MedianDiff(v,4);
	return 0;
}
