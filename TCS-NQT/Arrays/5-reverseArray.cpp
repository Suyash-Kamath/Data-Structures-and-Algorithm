// Example 1:
// Input: N = 5, arr[] = {5,4,3,2,1}
// Output: {1,2,3,4,5}


#include<iostream>
using namespace std;

int main(){

    int arr[]={5,4,3,2,1};

    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Reversing ";
for(int i=0;i<size;i++){
    cout<<arr[i];
}

   cout<<endl;
    
   int first=0;
   int last= size -1;

  while(first<last){
    int temp = arr[first];
    arr[first]=arr[last];
    arr[last]=temp;
    first++;
    last--;
  }

cout<<"After Reversing ";
for(int i=0;i<size;i++){
    cout<<arr[i];
}

 

    
}