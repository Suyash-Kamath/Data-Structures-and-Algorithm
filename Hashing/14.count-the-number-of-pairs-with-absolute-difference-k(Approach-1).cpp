/*
Given an integer array nums and an integer k , return the number of pairs (i,j) where
i<j such that [nums[i]-nums[j]] == k

Input : nums = [1,2,2,1] , k = 1
Output : 4

Explanation :

The pairs with an absolute difference of 1 are :

1,2
1,2
2,1
2,1

from the above array 


Brute Force :

Traversing the array for each element , finding the difference and count++

Take 2 loop , if [nums[i]-nums[j]] == k , then count++ 

Time Complexity is 0(n^2)


Concept of Modulus

| x-y | =k

nums[i] = x
nums[j] =y

it can be written as

+(x-y) = k or  -(x-y) = k

x - y = k   or -x+y=k.....(i)

y = x-k  or  x = x+k......(ii)

these are the two conditions I have to satisfy 
if any pair satisfies the conditions then I get the answer

If I need to get the y , I can get either  of theses conditions


if i and j points to nums[i]  and nums[j] means 

x= nums[i]  <- i 
y= nums[j]   <- j 


we can write as 

j = i-k  or j =i+k

we can use hashmap because while traversing we need to find the element or condition if I can get x+k or x-k

So this was the intuition for using hashmap 


2 kind of HashMap : 1. Before Hand 2. On the Go 

we will use On the Go because pairs can be made

we wanted i<j pair
if we use Before Hand HashMap , we will also include i>j pair which is completely wrong





another approach : Read question

see the constraints 
Here we can use non comparison Based Sorting algorithm like Count Sort

We have given Fact that all the Numbers are in the range of 1 to 100

We can simply use Count Sort

Use array as frequency array
run  a loop 

if I do arr[i]*arr[i-k] then I would get all possible answers

while starting the loop from i=k+1 to i<=101 ; i++

what we are doing is that we have to do arr[i]*arr[i-k] and we require I < J

if we start from k+1 , we wont get negative index in the array


k blocks backword ....this is the count sort algorithm for you 
This is how count sort works

*/




#include <iostream>
#include <vector>
#include <unordered_map>

int countPairsWithDifference(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freqMap;
    int count = 0;

    for (int num : nums) {
        if (freqMap.find(num - k) != freqMap.end()) {
            count += freqMap[num - k];
        }
        if (freqMap.find(num + k) != freqMap.end()) {
            count += freqMap[num + k];
        }
        freqMap[num]++;
    }

    return count;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 1};
    int k = 1;
    std::cout << "Number of pairs with absolute difference " << k << ": " << countPairsWithDifference(nums, k) << std::endl;
    return 0;
}
























// T.C and S.C is O(N)