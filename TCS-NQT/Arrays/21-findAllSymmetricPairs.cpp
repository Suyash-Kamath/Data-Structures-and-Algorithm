/*

#include<iostream>

using namespace std;
int main() {
  int n = 5;
 
  int arr[][2] = {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}}; 
  cout << "The Symmetric Pairs are: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j][0] == arr[i][1] && arr[j][1] == arr[i][0]) {
        cout << "(" << arr[i][1] << " " << arr[i][0] << ")" << " ";
        break;
      }
    }
  }

}

// T.C is O(N*N)
// S.C is O(1)


*/

// Better Approach but trade off between time and space

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

   int arr[][2] = {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int>mp;
    for(int i =0 ;i<n;i++){
        int first = arr[i][0];
        int second = arr[i][1];

        if (mp.find(second) != mp.end() && mp[second] == first) {
            cout<< " ( "<< second << " "<<first <<" )"<<" ";

        }
        else{
            mp[first] = second;
        }
    }

    return 0;
}


// T.C is O(N) = S.C