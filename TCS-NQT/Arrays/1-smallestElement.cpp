// Example 1:
// Input: arr[] = {2,5,1,3,0};
// Output: 0
// Explanation: 0 is the smallest element in the array. 

// Example2: 
// Input: arr[] = {8,10,5,7,9};
// Output: 5
// Explanation: 5 is the smallest element in the array.

#include<iostream>
using namespace std;

int main(){

int arr[]={2,5,1,3,0};


int mini = INT_MAX;

for (int i = 0; i < 5; i++)
{
   if(mini>arr[i]){
    mini =arr[i];
   }
}

cout<<"Smallest Element is : "<<mini<<" ";

    return 0;
}