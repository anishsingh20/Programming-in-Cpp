#include<iostream>

using namesapce std;

/*Program to calculate nth CATALAN NUMBER-catalan number is simply a sequence of number which has lots of applications in DSA.

We have the recurrence relation for Catalan no(s) as C(0) = 1, C(1) = 1 so C(n<=1) = 1, 
else C(n>=1) =  sum( C(i) * C(n-i)) where i = 2 to n

Method to calculate CATALAN NUMBER-
1) Using the above recurrence relation and recursion
2) Using Dynamic programming to optimize 
3) Binomial coefficient = C(n) =  1/(n+1) * (2n c n) , linear time algorithm
4) C(n) = product(n+k/k) , where  k = 2 to n 	, linear time algorithm
					      
				 

*/
