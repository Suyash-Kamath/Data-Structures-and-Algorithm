// Takes an element and places it in its correct place..means swap adjacent  till it can be swapped

#include<iostream>
#include<algorithm>
using namespace std;

int main(){

int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    for(int i =0 ;i<n;i++){
            int j =i;

            while(j>0 && arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
                j--;
            }
    }

     cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// T.C => O(n^2)
