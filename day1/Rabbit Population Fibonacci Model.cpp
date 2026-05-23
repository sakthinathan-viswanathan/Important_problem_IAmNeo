Predicting Rabbit Population Growth

A biology researcher in Madurai is studying the growth of a special rabbit population. The population follows a pattern where:

In month 0, there are 0 rabbits.
In month 1, there is 1 rabbit.
For every month after that, the number of rabbits is the sum of the rabbits in the previous two months.
Given an integer n, find the number of rabbits present in the nth month.

Note: This is the classic Fibonacci Number problem.

Input format :
The first line contains a single integer n.
Output format :
Print a single integer representing the Fibonacci value at position n.

Code constraints :
0 <= n <= 30

Sample test cases :
Input 1 :
3
Output 1 :
2
Input 2 :
7
Output 2 :
13





  Solution:


// You are using GCC
#include<bits/stdc++.h>
using namespace std;

int GrowthPopulatioin(int n){
    
    if(n == 1){
        return 1;
    }
    
    if( n == 2){
        return 2;
    }
    
    return GrowthPopulatioin(n-1) + GrowthPopulatioin(n-2);
}

int main(){
    
    int n;
    cin>>n;
    
    cout<<GrowthPopulatioin(n);
}
