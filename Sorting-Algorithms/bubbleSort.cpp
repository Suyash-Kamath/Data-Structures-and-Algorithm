/*

How Bubble Sort Works:
Bubble Sort sorts the array by repeatedly pushing the largest element to the end of the unsorted section through
adjacent comparisons and swaps.

Adjacent Comparisons:
Each pair of adjacent elements is compared. If the element on the left is greater than the element on the right, they are swapped.

Largest Element "Bubbles Up":
Through repeated passes, the largest element in the unsorted portion gradually moves (or "bubbles") to the end of the array. 
This process is repeated for the remaining unsorted part until the entire array is sorted.

 */

#include<iostream>
using namespace std;

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
