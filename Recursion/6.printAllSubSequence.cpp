// Print All Subsequence


/*
Subsequence -> contiguous or non-contiguous sequence which follows the order

arr = [3,1,2] =>(), 3,1,2,(3,1),(1,2),(3,2),(3,1,2)..you cannot say (3,2,1)  because it is not
following the order,make sure it follows the order of the array ..so order has to be maintained to be called as 
subsequence...Subarrays can also be subsequence as (3,2) is only non-contiguous
Empty set is also subsequence because we are not picking anything from the array .

for n=3 there are 8 subsequence
*/

/*

Power set method

s="abc" -> substrings :- "",a,b,c,ab,ac,bc,abc -> this is basically a subsequence

n=3 then no. of substring is 8

*/

// Powerset Approach

/*

Bitwise Subset Generation
Understanding the Bit Mask:

Each subset can be represented by a bitmask where each bit represents whether an element
 from the string is included (1) or excluded (0) in the subset.
For a string of length n, there are 2^n possible subsets, including the empty subset.
 This is why the loop runs from 0 to pow(2, n) - 1.
*/





/*
#include<iostream>
#include<string>
#include<math.h>

using namespace std;
int main(){

string s="abc";

int n = s.size();

for(int num =0;num<=pow(2,n)-1;num++){
    string sub ="";
    for(int i=0;i<n;i++){
        if(num & (1<<i)) sub+=s[i];
    }
    cout<<sub<<",";
}

    return 0 ;
}

*/





// Recursive Approach

/*
Pseudo Code

f(index,[]){
if(index>=n) {print([]) return};

[].add(arr[i]);
f(index+1,[]); ->take
[].remove(arr[i]);

f(index+1,[]); -> not take
}

main(){
arr = [3,1,2]
f(0,[]);
}
*/

#include<iostream>
#include<vector>
using namespace std;

void printF(int ind,vector<int>&ds,int arr[],int n){
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
         if(ds.size()==0) cout<<"{}";
        cout<<endl;
        return ;
    }
    //Take or pick particular index into subsequence
    ds.push_back(arr[ind]);
    printF(ind+1,ds,arr,n);
    ds.pop_back();
    // Not pick, or not take condition, this element is not added to your subsequence
    printF(ind+1,ds,arr,n);
}

int main(){
   int arr[]= {3,1,2};
    int n = 3;
    vector<int>ds;
    printF(0,ds,arr,n);
return 0 ;
}

// T.C -> For very index you are having 2 options and into  every subsequence you use for loop to print so O(2^n * n)
//Auxillary Stack Space is : O(N)

