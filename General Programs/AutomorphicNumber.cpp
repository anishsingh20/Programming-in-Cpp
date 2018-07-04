#include<iostream>
#include<math.h>

using namespace std;

void isAutomorphic(int n)
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
     if(d==n) cout<<"Automorpihc";
    
     else cout<<"Not Automorphic";
}


int main()
{
	isAutomorphic(76);
	return 0;
}
