// Example 1:
// Input: [2,4,1,3,5]
// Output: 3

// Example 2:
// Input: [2,5,1,7]
// Output: 3.5
#include<iostream>
using namespace std;

int main(){

    int n = 5;
    int arr[]={2,4,1,3};

    sort(arr,arr+n);

    if(n%2==0){
        int index1 = n/2;
        int index2 = (n/2)-1;

        cout<<(double)((arr[index1]+arr[index2])/2);

    }
    else{
        cout<<arr[n/2];
    }

    return 0;

}