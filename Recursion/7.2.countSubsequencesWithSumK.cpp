

// Take or Not Take technique

#include<iostream>
#include<vector>
using namespace std;
int printS(int index,int initialSum ,int  sum,int arr[],int n){
    // condition not satisfied
    // strictly done if array contains positives only 
    if(initialSum>sum) return 0;
    if(index==n){
        // condition satisfied
        if(initialSum==sum){
            
            return 1;
        } else{

        return 0 ;
        }
    }
    
    initialSum+=arr[index];
    int l =printS(index+1,initialSum,sum,arr,n);
      
    initialSum-=arr[index];


    //not pick
   int r = printS(index+1,initialSum,sum,arr,n);
   return l+r;
}
int main(){


int arr[] = {1,2,1};
int n = 3;
int sum = 2;

cout<<printS(0,0,sum,arr,n);

    return 0 ;
}

// T.C is o(2^n) but we can slight reduce it by stating if(initialSum>0) return 0 ;