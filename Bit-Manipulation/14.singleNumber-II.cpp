/*
Bruteforce - Map


#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){

    vector<int>arr={5,5,5,6,1,1,1};

    unordered_map<int,int>frequency;

    for(int i=0;i<arr.size();i++){



        frequency[arr[i]]++;
    }
    for(auto it:frequency){
        if(it.second==1){
            cout<<it.first;
        }
    }



    return 0;
}
*/

// Better Solution
/*
#include<iostream>
#include<vector>
using namespace std;

int  main(){

    int ans =0;
    vector<int>arr={5,5,5,6,4,4,4};
    int n =arr.size();
    for(int bitIndex=0;bitIndex<=31;bitIndex++){
        int count =0;

        for(int i=0;i<=n-1;i++){
            if(arr[i]&(1<<bitIndex)){
                count++;
            }
        }
        if(count%3==1){
            ans = ans | (1<<bitIndex);
        }
        
    }
    cout<<ans;


    return 0;
}

T.C O(32*N)
S.C = O(1)
*/

/*
Again Better solution than the previous


#include<iostream>
#include<vector>
using  namespace std;

int main(){

    vector<int>arr = {5,5,5,4,4,4,7};
    int n = arr.size();

    for(int i=1;i<n;i+=3){
        if(arr[i]!=arr[i-1]){
            cout<<arr[i-1];
            return 0;
        }
    }
    cout<<arr[n-1];


    return 0;
}
*/

// T.C is O(nlogn + n/3)
// S.C is O(1)


// Latest Solution 


// Concept of Buckets

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={2,2,2,13};
    int n=arr.size();
    int ones=0,twos=0,threes=0;
    for(int i=0;i<n;i++){
        ones = (ones^arr[i])& ~twos;
        twos = (twos^arr[i])& ~ones;
    }

    cout<<ones;
    return 0;
}