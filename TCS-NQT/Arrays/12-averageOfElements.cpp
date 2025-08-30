#include<iostream>
using namespace std;
int main(){

    int n = 5;
    int arr[]={1,2,3,4,5};

    int sum =0;

    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }

    cout<<"Average of all the elements of an array is "<< sum/n;
    
    return 0;
}