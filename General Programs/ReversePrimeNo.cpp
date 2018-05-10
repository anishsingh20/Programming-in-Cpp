#include<iostream>
#include<vector>


using namespace std;



//function to check if a number n is prime or not-
bool isPrime(long n,int i=2)
{
	if(n==1)
		return false;

	if(n > i)
	{
		if(n%i==0)
			return false;
			
		if(n%i!=0)
		{
			return isPrime(n,++i);
		}
	}
	
	return true;
}



//function to store all numbers from 2 till n in a vector, and print only prime in this rang in reverse order
void ReversePrime(long n)
{
	vector<int>v; 
	//vector to store the prime numbers
	int count = 0;
	if(!isPrime(n))
	{
		cout<<"Not a prime number"<<endl;
		return;
	}
	
	for(int i=2;i<n;i++)
	{
		v.push_back(i);
	}
	
	vector<int>::reverse_iterator it;
	
	for(it = v.rbegin();it!=v.rend();++it)
	{
		//if numbers in vector are prime, then print them
		
		if(isPrime(*it))
		{
			cout<<*it<<" ";
			count++;
			
		}

		
			
	}
	cout<<endl;
	cout<<"Count of prime numbers till"<<" "<< n<<" is :"<<count;
	
	
}


int main()
{
	ReversePrime(19);
	return 0;
}
