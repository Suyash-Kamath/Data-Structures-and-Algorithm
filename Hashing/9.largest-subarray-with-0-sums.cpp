/*

Given an array having both positive and negative integers , The task is to compute the length of the
largest subarray with 0 sum

Example :

N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output : 5

Explanation : The largest subarray with sum 0 will be -2 2 -8 1 7.




Intuition :
                l     r
arr : X X X X X X X X X X X X X 

p(r) = sum of elements from 0 till r
p(l-1) = sum of elements from 0 till l-1

say , we are at index r and there is a subarray starting from some l ending at r index
whose sum is 0

now p(r) = p(l-r) + S(l,r)

if S(l,r)= 0    
 p(r) = p(l-r)



A   3 1 5 -3 -2 1 2 3 -5 3 -3 6   7
    0 1 2  3  4 5 6 7  8 9 10 11 12

Sum 3 4 9  6  4 5 7 10 5 8 5  11 18    

sum = 5
maxLength = 3

unordered_map<int,int>{prefixSum,firstOccurrence}

prefixSumIndex = {

{3,0} , {4,1} , {9,2} , {6,3} , {5,5} , {7,6} , {10,7} , {8,9} , {11,11} , {12,12}

}


Always Check if sum ==0 and and is it occured in hashmap , if not then push in Hashmap
If it is occured it means we have find p(r) and p(l-1)  , ..4 in this case

current index is i - prefixSumIndex[4] = > 4-1 = 3 ...size is 3 of subarray , in this way you can 
calculate the suubarray size ..update maxLength

8 - 5  = 3
maxLength = 3

10 - 5 = 5
maxLength  = 5

why check sum  = 0 is because

2 4 -3 -3 4 7

2 6  3  0  4  11

prefix Sum itself 0 then I will update maximum to this i+1

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLength(vector<int> &A, int n) {
    unordered_map<int, int> prefixSumIndex;
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // If the sum is zero, update maxLength to the current index + 1
        if (sum == 0) {
            maxLength = i + 1;
        } else {
            // If sum is found in the map, it means we have found a subarray with sum 0
            if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[sum]);
            } else {
                // Otherwise, store the sum with its index
                prefixSumIndex[sum] = i;
            }
        }
    }
    return maxLength;
}

int main() {
    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = A.size();

    cout << "Length of the largest subarray with 0 sum: " << maxLength(A, n) << endl;

    return 0;
}


// T.C AND S.C is O(N)