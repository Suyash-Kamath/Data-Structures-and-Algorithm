/*

Given an array of N integers , and an integer K,, find the number of pairs of elements
in the array whose sum is equal to K

N=4 , K=6
arr[] ={1,5,7,1}
Output : 2

({1,5},{5,1})


arr : 5 3 5 7 4 2 4 8 5 
      0 1 2 3 4 5 6 7 8 

      <int,int> => <element,frequency>

      a+b=k
      a=k-b


      a+5=12 => a=7 

      frequency = {
            {5,2},
            {3,1},
            {7,1},
            {4,2},
            {2,1},
            {8,1}


      }
      

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> frequency;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int b = arr[i];
        int a = k - b;

        if (frequency.find(a) != frequency.end()) {
            ans += frequency[a];
        }
        frequency[b]++;
    }

    return ans;
}

int main() {
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    cout << "Number of pairs: " << getPairsCount(arr, n, k) << endl;

    return 0;
}

//  T.C : O(N)
//  S.C : O(N)