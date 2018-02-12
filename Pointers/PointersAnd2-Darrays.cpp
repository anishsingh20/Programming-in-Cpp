#include<iostream>


using namespace std;


int main()
{
	int arr[3][4] = {
	{1,2,4},
	{2,3,4} , 
	{5,6,7}  };
	
	
	cout<<sizeof(arr)<<endl;
	cout<<arr<<endl;
	cout<<"address of arr + 5 = add "<<arr<<" incremented by + 5*4*4 bytes in hex "<<arr + 5<<endl;
	
	//size = base addess + incremented by sizeof(int)*no of cols*5 as it is a 2-d array of size 4(no of cols)
	
	

return 0;
}
