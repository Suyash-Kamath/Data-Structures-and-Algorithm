// Example 1:
// Input: arr[] = {10,5,10,15,10,5};
// Output:  10  3
// 	        5  2
//          15  1


/*

Approach 1: Query Based



#include<iostream>
using namespace std;

int main() {

    int arr[] = {10, 5, 10, 15, 10, 5};  // Array of integers
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    // Find the maximum element in the array to determine the size of metaData array
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (maxi < arr[i]) {
            maxi = arr[i];
        }
    }

    // Initialize metaData array to store frequencies of elements
    int metaData[maxi + 1] ;  // Initialize all elements to 0

    for(int i =0;i<maxi+1;i++){
        metaData[i]=0;
    }

    // Count frequencies of each element in the array
    for (int i = 0; i < size; i++) {
        metaData[arr[i]] += 1;
    }

    // Query input size
    int sizeOf = 0;
    cout << "Enter the number of queries: ";
    cin >> sizeOf;

    // Input elements whose frequencies need to be found
    cout << "Enter the elements whose frequencies to be found:" << endl;
    int queries[sizeOf];  // Dynamically sized array for queries
    for (int i = 0; i < sizeOf; i++) {
        cin >> queries[i];
    }

    // Output the frequency of queried elements
    for (int i = 0; i < sizeOf; i++) {
        // Ensure that the query is within the bounds of metaData
        if (queries[i] >= 0 && queries[i] <= maxi) {
            cout << queries[i] << " " << metaData[queries[i]] << endl;
        } else {
            cout << queries[i] << " is out of range" << endl;
        }
    }

    return 0;
}
 */


#include<iostream>
#include<vector>
using namespace std;
int main(){
    int  arr[] = {10,5,10,15,10,5};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    vector<bool>visited(size,false);
    
    for(int i =0;i<size;i++){
        
        if(visited[i]==true){
            continue;
        }
        
        int count =1;
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                visited[j]=true;
                count++;
            }
        }
        cout<<" Count of "<<arr[i]<<" is "<< count<<endl; 
    }
    
    return 0;
    
}