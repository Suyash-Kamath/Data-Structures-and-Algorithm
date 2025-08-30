// [1,2,-1,1,3,1]
// brute

// #include<iostream>
// using namespace std;

// int main(){

// int arr[] = {1,2,-1,1,3,1};

// int n = sizeof(arr)/sizeof(arr[0]);


// bool checkRepeat;

// for(int i =0;i<n;i++){
//     checkRepeat = false;
//     for(int j =0;j<n;j++){
//         if(arr[i]==arr[j] && i!=j){
//             checkRepeat = true;
//             break;
//         }
//     }
//     if(!checkRepeat)cout<<arr[i]<<" ";
// }


//     return 0;
// }



// better

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

int arr[] = {1,2,-1,1,3,1};

int n = sizeof(arr)/sizeof(arr[0]);

unordered_map<int,int>uniqueCount;

for(int i =0;i<n;i++){
    uniqueCount[arr[i]]++;
}

for(unordered_map<int,int>::iterator it = uniqueCount.begin();it!=uniqueCount.end();it++){
    if(it->second==1){
        cout<<it->first<<" ";
    }
}

    return 0;
}



// optimal
/*
#include<iostream>
using namespace std;

int main(){

    int arr[] = {1,2,-1,1,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    

    sort(arr,arr+n);
    if(arr[0]!=arr[1]) cout<<arr[0]<<" ";

    for(int i =1;i<n-1;i++){
        if(arr[i]!=arr[i+1] && arr[i-1]!=arr[i]){
            cout<<arr[i]<<" ";
        }
    }

    if(arr[n-1]!=arr[n-2]) cout<<arr[n-1]<<" ";


    return 0;



}
*/

