// Quick Sort =>Sort in ascending order also descending order
/*

1. Pick  a pivot and place it in its correct place  in a sorted array, here pivot can be  any element in the array , it 
can be 1st , last , median , random , your choice

it is more like pick up and pick down

2. smaller on the left and larger on the right , 

it can be said that in one step , one element is in its correct place

,make sure you treat as individual array , whenever array has one element no need to do anything

Summary :

Quick Sort in Ascending Order and Descending Order

Pick a Pivot: Choose an element to partition the array. Here, the last element is used as the pivot.

Partition: Rearrange the elements such that smaller elements go to the left and larger elements go to the 
right (for ascending) or vice versa (for descending).

Recursive Sorting: Recursively apply the same logic to the subarrays on the left and right of the pivot.


 */

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    cout << "Before Using Quick Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);

    cout << "After Using Quick Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// T.C => O(nlogn) and S.C => O(1) 