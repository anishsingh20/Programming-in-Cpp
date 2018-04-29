#include<iostream>
#include<math.h>

/*Program demonstarting the XOR relation a XOR b = c, then to find sq(a) XOR sq(b) = c, then we can find b = sqrt( sq(a) XOR b )
eg- 11*11 XOR 12*12 = 233, then sqrt(11*11  XOR 233) = 12
*/
using namespace std;




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
