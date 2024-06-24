/*

Two Sum :

nums = 3 4 6 5 8 2 1
       0 1 2 3 4 5 6

       target = 12
    

approach  a+b = 12

suppose we know that b=10

a+10 = 12

a = 2 , this is the intuition 


if a = 2 is not tpesent in the hashmap then push b value in the hashmap and increment
make sure you push element along with the index

Always check before pushing th element , this can avoid duplicates


****************************** Question **************************************

Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int target = 12;
    vector<int> arr = {3, 4, 6,
 5, 8, 2, 1};

    unordered_map<int, int> indexMap;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int remaining = target - arr[i];

        if(indexMap.find(remaining) != indexMap.end()){
            vector<int> ans = {indexMap[remaining], i};
            for(int j = 0; j < ans.size(); j++){
                cout << ans[j] << " ";
            }
            return 0;
        }
        indexMap[arr[i]] = i;
    }

    vector<int> ans = {-1, -1};
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
