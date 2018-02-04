#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<numeric>
#include <algorithm>

using namespace std;

template <class T>
void pop_front(vector<T>& v)
{
  if (!v.empty())
      //will erase the element at front of vector
    v.erase(v.begin());
}
unsigned long long int findMaxSum(unsigned long long int a, unsigned long long int b,unsigned long long int c ) {
    if(a>b && a>c) {
        return a;
    }
    if(b>a && b>c) return b;
    
    else {
        return c;
        
    }
}


int main() {
    
   
    long int n1,n2,n3;
    
    unsigned long long int sum1=0,sum2=0,sum3=0;
    cin>>n1>>n2>>n3;
    vector<int>s1(n1);
    vector<int>s2(n2);
    vector<int>s3(n3);
    

    
    //reading cylinder's heights into vectors
    for(long int i=0;i<n1;i++) {
        cin>>s1[i];
        sum1 += sum1 + s1[i];
        
    }
    for(long int i=0;i<n2;i++) {
        cin>>s2[i];
        sum2 += sum2 + s1[i];
       
    }
    for(long int i=0;i<n3;i++) {
        cin>>s3[i];
        sum3 +=sum3 + s3[i];
        
    }
    
   long int top1=0,top2=0,top3=0;
    //if the sums of ht is different 
    while(sum1 != sum2 && sum1!=sum3) {
        
        if(findMaxSum(sum1,sum2,sum3)==sum1) {
            sum1 = sum1 - s1[top1];
            top1++;
            if(top1>n1) {
                return 0;
            }
            
            
        }
        
        else if(findMaxSum(sum1,sum2,sum3)==sum2) {
            sum2 = sum2 - s2[top2];
            top2++;
            if(top3>n2) {
                return 0;
            }
            
            
            
        }
        
        else {
            sum3 = sum3 - s2[top3];
           
            top3++;
            if(top3>n3) {
                return 0;
            }
            
        }
        
        
    }
    
    cout<<sum1;
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

