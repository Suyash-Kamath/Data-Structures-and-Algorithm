/*

Theory 

As the name suggests, Selection Sort focuses on selecting the minimum element repeatedly. 
It works by selecting the smallest element from the unsorted part of the array and placing it at the beginning.

In essence, it’s a simple swap game:

Find the minimum element in the entire unsorted array.
Place it in the correct position (at the start of the unsorted part).
Swap it with the current element at that position.

*/

// 13 46 24 52 20 9
#include <iostream>
using namespace std;

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    for (int i = 0; i <= n - 2; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// T.C is O(n^2)
