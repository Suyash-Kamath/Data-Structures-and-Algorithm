// Brute Force
/*
#include<iostream>
#include<set>
using namespace std;

int removeDuplicates(int arr[],int n){

    set<int>uniqueSet;

    for(int i =0;i<n;i++){
        uniqueSet.insert(arr[i]);
    }

    int k = uniqueSet.size();
    int j =0;
    

    for (set<int>::iterator it = uniqueSet.begin(); it != uniqueSet.end(); it++) {
        arr[j++] = *it;
    }


    return k;
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

*/

// Optimal

#include<iostream>
using namespace std;

int removeDuplicates(int arr[],int n){
    int i =0;
    for(int j = 1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]  =arr[j];
        }
    }
    return i+1;
}

int main() {

  int arr[] = {1,1,2,2,2,3,3};

  int n = sizeof(arr)/sizeof(arr[0]);

  int k = removeDuplicates(arr, n);

  cout << "The array after removing duplicate elements is " << endl;

  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}