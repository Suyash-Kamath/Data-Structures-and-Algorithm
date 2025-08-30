// arr[] = {1,1,2,3,4,4,5,2};
// brute
/*

#include<iostream>
using namespace std;

int main(){

    int arr[] = {1,1,2,3,4,4,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int dp[1000];

    int dpIndex =0;

    for(int i =0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            dp[dpIndex] = arr[i];
            dpIndex++;
        }
    }
    cout<<"Repeated Elements are ";
    for(int i =0;i<dpIndex;i++){
        cout<<dp[i]<<" ";
    }

    return 0;
}
*/

// T.C => O(nlogn) + O(n)
// S.C => O(N)


//better

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    int arr[] = {1,1,2,3,4,4,5,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int,int>elementCount;

    for(int i =0;i<n;i++){
        elementCount[arr[i]]++;
    }
    cout<<"Repeated Elements are ";
    for(unordered_map<int,int>::iterator it = elementCount.begin();it!=elementCount.end();it++){
        if((*it).second>1){
            cout<<(*it).first<<" ";
            
        }
    }

    return 0;
}

// T.C is O(N)
// S.C is O(N)


// optimal
/*
#include<iostream>
using namespace std;

int main(){

    int arr[] = {1,1,2,3,4,4,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    
     cout<<"Repeated Elements are ";
    for(int i =0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            cout<<arr[i]<<" ";
        }
    }
   
   

    return 0;
}
*/
// only S.C is reduced to O(1)

