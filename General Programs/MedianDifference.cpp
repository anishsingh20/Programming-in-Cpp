#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>

using namespace std;

long MedianDiff(int *v,int size)
{
	vector<int>s;//to store the differences
	int i = 0 ;
	int j = size-1;
	
	while(i<j)
	{
		//again finding difference between all items of array
		while(j > i)
		{
			s.push_back(abs(v[i]-v[j--]));
		}
		
		j = size-1;	
		i++;
	}
	
	//sorting the vector of differences to find the median
	stable_sort(s.begin(),s.end());
	

	int start = 0;
	int end = s.size()-1;
	int mid = start + (end-start)/2;
	
	return s[mid];
	
}

int main()
{	
	int v[] = {1,3,2,4};
	cout<<MedianDiff(v,4);
	return 0;
}
