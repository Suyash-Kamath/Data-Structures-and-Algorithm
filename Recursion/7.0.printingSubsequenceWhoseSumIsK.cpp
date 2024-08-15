// Take or Not Take technique

#include<iostream>
#include<vector>
using namespace std;
void printS(int index,vector<int>&ds,int initialSum ,int  sum,int arr[],int n){
    if(index==n){
        if(initialSum==sum){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
        }
        return  ;
    }
    ds.push_back(arr[index]);
    initialSum+=arr[index];
    printS(index+1,ds,initialSum,sum,arr,n);
    initialSum-=arr[index];
    ds.pop_back();

    //not pick
    printS(index+1,ds,initialSum,sum,arr,n);
}
int main(){


int arr[] = {1,2,1};
int n = 3;
int sum = 2;
vector<int>ds;
printS(0,ds,0,sum,arr,n);

    return 0 ;
}