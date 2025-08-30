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


int maxi = INT_MIN;

for (int i = 0; i < 5; i++)
{
   if(maxi<arr[i]){
    maxi =arr[i];
   }
}

int secondLargestElement =INT_MIN;

for (int i = 0; i < 5; i++)
{
   if(secondLargestElement<arr[i] && arr[i]!=maxi){
    secondLargestElement =arr[i];
   }
}

cout<<"Largest Element is : "<<maxi<<" "<<endl;

cout<<"Second Largest Element is: "<<secondLargestElement;

    return 0;
}