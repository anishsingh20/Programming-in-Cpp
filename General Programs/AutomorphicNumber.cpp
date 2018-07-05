#include<iostream>
#include<math.h>

using namespace std;

bool isAutomorphic(int n)
{
    int sq = (n*n);
    int count = 0;
    int nn = n;
    //counting number of digits of n
    while(nn)
    {
        count++;
        nn /= 10;
    }
    int dig = pow(10,count);
    
     int d = (sq % dig);
     if(d==n) return true;
    
     else return false;
}


void nAutomorphic(int n)
{
	for(int i = 1 ; i <= n; i++)
	{
		if(isAutomorphic(i)) cout<<i<<endl;
		
		
	}	
}

int main()
{
	nAutomorphic(200);
	return 0;

}
