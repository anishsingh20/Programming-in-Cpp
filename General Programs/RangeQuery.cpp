#include<iostream>

int CountSet(int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1)
            count ++;
            
        n = n >> 1;
    }
    
    return count;
}

int RangeQuery(int l,int r)
{
    int count= 0 ;
    for(int i = l ; i <= r;i++)
    {
        if(CountSet(i)<=3)
            count++;
    }
    
    return count;
}

using namespace std;
int main()
 {
	//code
	int t;
	
	cin>>t;
	for(int i = 0 ; i < t;i++)
	{
	    int q;
	    cin>>q;
	    for(int j=0; j < q;j++ )
	    {
	        int l,r;
	        cin>>l>>r;
	        
	        cout<<RangeQuery(l,r);
	        cout<<endl;
	    }
	}
	return 0;
}

