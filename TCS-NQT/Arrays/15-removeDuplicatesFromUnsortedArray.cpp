// Example 1:
// Input: arr[]={2,3,1,9,3,1,3,9}
// Output:  {2,3,1,9}


#include<iostream>
using namespace std;

int main(){
    
    int arr[]={2,3,1,9,3,1,3,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int marks[n];
    
    for(int i=0;i<n;i++){
        marks[i] = 1;
    }
    
    for(int i =0;i<n;i++){
        if(marks[i]==1){
            for(int j = i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    marks[j]=0;
                }
            }
        }
    }
    
    for(int i =0;i<n;i++){
        if(marks[i]==1){
            cout<<arr[i]<<" ";
        }
    }
    
    return 0;
}