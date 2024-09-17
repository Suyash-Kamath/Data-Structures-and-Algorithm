/*
Brute Force

class Solution {
  public:
    
    int countSetBits(int n) {
        int totalCount = 0;
        for (int i = 1; i <= n; i++) {
            totalCount += countBits(i);
        }
        return totalCount;
    }
    
    
    int countBits(int num) {
        int count = 0;
        while (num > 0) {
            num = num & (num - 1); 
            count++;
        }
        return count;
    }
};

*/

// Optimal Solution

#include<iostream>
#include<math.h>
using namespace std;
int countSetBits(int n){
    if(n==0){
        return 0;
    }
    int p =0;
    while(n>=pow(2,p)){
        p++;
    }
    p--;
    int result = 2 * pow(2,p)/2 + (n-pow(2,p)+1) + countSetBits(n-pow(2,p));
    return result;
}
int main(){
    int n = 4;
    cout<<countSetBits(n);
}

// T.C is about Logarithmic
