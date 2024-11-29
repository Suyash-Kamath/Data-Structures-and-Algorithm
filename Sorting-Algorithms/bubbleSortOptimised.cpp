#include<iostream>
using namespace std;

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    bool swapped;

    for (int i = n - 1; i >= 1; i--) {
        swapped = false;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // No swaps means array is already sorted
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
//T.C => O(n)
