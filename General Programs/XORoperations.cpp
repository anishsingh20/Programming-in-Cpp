#include<iostream>
#include<math.h>

using namespace std;


//Program demonstarting the XOR relation a XOR b = c, then to find sq(a) XOR sq(b) = c, then we can find b = sqrt( sq(a) XOR b )
//eg-

int XORops(int a,int c)
{
	int sq = (a*a);
	
	int pro = (sq ^ c);
	
	return sqrt(pro);
}


int main()
{
	cout<<XORops(12,233);
}
