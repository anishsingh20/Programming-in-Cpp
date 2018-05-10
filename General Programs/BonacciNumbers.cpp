#include<iostream>


using namespace std;

/*Program to print N-Bonacci numbers.
 when N=2 , then it becomes Fibonacci, ie sum of previous 2 numbers,
 when N = 3 the series becomes Tri-bonacci, i.e the next number is the sum of previous 3 numbers
 eg. N =3 , 0 0 1 1 2 4 7 13 24 .. .. 

*/

 
// Function to print bonacci series
void BonacciSeries(long n, int m)
{
 
    // Assuming m > n.
    int a[m] = { 0 };
    a[n - 1] = 1;
    a[n] = 1;
 
    // Uses sliding window
    for (int i = n + 1; i < m; i++)
        a[i] = 2 * a[i - 1] - a[i - n - 1];
 
    // Printing result
    for (int i = 0; i < m; i++)
        cout << a[i] << " ";
}
//Time complexity = O(M), Space complexity = O(M)


int main()
{
	BonacciSeries(2,10);//fibonacci series
	cout<<endl;
	
	BonacciSeries(3,10);//tri-bonacci series
}
