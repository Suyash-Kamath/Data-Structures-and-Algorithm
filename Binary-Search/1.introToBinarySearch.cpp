/*
Iterative Approach

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr,int target){
    int n  = arr.size();
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        
        if(target ==arr[mid]){
            
        return mid;
        }
        else if (target > arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        
    }
    return -1;
    
    
    
    
}
int  main(){
    
    vector<int>arr={3, 4, 6, 7, 9, 12, 16, 17};
    int target =6;
    int ind = binarySearch(arr,target);
    if(ind==-1){
        cout<<"Element is not present";
    }
    else{
        cout<<"Element "<<target<<" is present";
    }
    
    return 0;
}





*/


// Recursive Approach

#include<iostream>
#include<vector>
using namespace std;


int binarySearch(vector<int>&arr,int target,int low,int high){
    
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(target == arr[mid]){
        return mid ;
    }
    else if(target >arr[mid]){
        return binarySearch(arr,target,mid+1,high);
    }
    else{
        return binarySearch(arr,target,low,mid-1);
    }
    
    
    
}

int main(){
    
    vector<int>arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target =1;
    
    int ind = binarySearch(arr,target,0,8);
    
    if(ind ==-1){
        cout<<"Element is not present";
    }
    else{
        cout<<"Element is Present";
    }
    
    return 0;
}


// recursion is applicant when same step is repeated . !!

//  whenever steps are same , we can reuse the code

/*

Time Complexity

32 -> 16 -> 8 -> 4 -> 2 -> 1

1     1unit operation as you are searching , so 6 total operations


32 = 2^5

T.C is O(logn)

*/



// in case of Overflowing conditions


/*
Imagine search space is not an array and your search space = 0..........INT_MAX
INT_MAX
 where low==high

 mid = (low+high) is impossible 

 so take long long int 

 or 


 mid = low +(high -low)/2;


*/
