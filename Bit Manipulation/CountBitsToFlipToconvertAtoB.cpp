#include<iostream>


using namespace std;

//count number of bits to be flipped in a to convert it to b
int CountFlip(int a ,int b)
{
	int XOR = a^b; //XOR of a and b will be 1 whereever a and b bits are different
	
	
	int count= 0 ;
	while(XOR)
	{
		//counting number of set bits which is equal to number of bits to flip in a
		if(XOR & 1) count++;
		XOR /= 2;
		
	
	}
	
	return count;
}

int main()
{
	cout<<CountFlip(7,10);
	

	return 0;
}
