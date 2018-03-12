#include<iostream>

using namespace std;


int main()
{
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
       
        
    //we need to only traverse the first 4 rows for hourglass
        int maxsum = -1000 , col = 0;
        for(int i=0;i<4;i++)
        {
            int sum = 0; //to store the sums of hourglass elements
            for(int j = col ; j < col + 3 ; j++ )
            {
                sum += arr[i][j];
                if(j == col )
                    sum += arr[i+1][col+1]; //add the middle of hourglass
            
                sum += arr[i+2][j]; //now add the the third row elements of hourglass
            }
            col = (col<3) ? col+1 : 0 ;  
            if(sum > maxsum)
            {
                maxsum = sum;
            }
            
            if(col!=0) i--;
        }
        
        cout<<maxsum;
        
    
    int a = 15,b=10;
    int c= a|b;
   cout<<c;
    return 0;
}

