/*

Max Distance between same element

arr : 3 2 1 3 4 1 2 3
      0 1 2 3 4 5 6 7 

      maxi=0

      <element,firstOccurrence>

      Approach : Traverse the array and check in the map 
      if not then push into the map with their first occurred index 
      and do this , if you encounter the same element again then check
      yes if present then subtract and compare the current maxi and distance 

      note : dont push the index of the tree in the map because first occurence is there
            in order to find maximum distance



*/


#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxDistance(int arr[], int n) {
    unordered_map<int, int> firstOccurrence;
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        if (firstOccurrence.find(arr[i]) != firstOccurrence.end()) {
            maxi = max(maxi, i - firstOccurrence[arr[i]]);
        } else {
            firstOccurrence[arr[i]] = i;
        }
    }

    return maxi;
}

int main() {
    int arr[] = {1, 2, 3, 2, 1, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum distance: " << maxDistance(arr, n) << endl;

    return 0;
}


// T.C -> O(N)
// S.C -> O(N)

