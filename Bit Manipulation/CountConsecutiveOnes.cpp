#include<iostream>


using namespace std;

/*Program to count number of consecutive ones using left shifting the number until it becomes 0
*/

int countConsecutiveOnes(int n){
	
	int count=0;
	while(n)
	{
		n &= n << 1;
		count++;
	}
	
	return count;
}


int main()
{
	cout<<countConsecutiveOnes(15);
	return 0;
}
