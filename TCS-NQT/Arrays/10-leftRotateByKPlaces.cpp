/*

 Brute force

#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int d) {
    d = d % n;
    int temp[d];

    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    int j = 0;
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[j];
        j++;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int d = 3;

    leftRotate(arr, n, d);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}



*/



// Better solution
/*


#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;

    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;

    rotate(arr, d);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
*/




// Optimal solution

/*
#include<iostream>
#include<vector>
using namespace std;
void leftRotate(int arr[],int n,int d ){

    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);

}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n = 7;
    int d = 3;

    leftRotate(arr,n,d);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

*/

// without inbuilt

#include <iostream>
using namespace std;

// Helper function to reverse a part of the array using a temp variable
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        // Using a temporary variable to swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

// Function to perform left rotation
void leftRotate(int arr[], int n, int d) {
    d = d % n; // Handle cases where d > n

    // Reverse the first d elements
    reverseArray(arr, 0, d - 1);

    // Reverse the remaining elements
    reverseArray(arr, d, n - 1);

    // Reverse the entire array
    reverseArray(arr, 0, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int d = 3;

    leftRotate(arr, n, d);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}






