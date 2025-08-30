/*

 Brute forces

 #include <iostream>
using namespace std;

void rightRotate(int arr[], int n, int d) {
    d = d % n;  
    int temp[d];

    for(int i =0;i<d;i++){
        temp[i] = arr[n-d+i];
    }
    
    for(int i = n-1; i>= d;i-- ){
        arr[i] = arr[ i-d];
    }
    for(int i =0;i<d;i++){
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int d = 2;

    rightRotate(arr, n, d);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


 */


/*

Another Approach 1

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> rotated(n);

    for (int i = 0; i < k; i++) {
        rotated[i] = nums[n - k + i];
    }

    for (int i = k; i < n; i++) {
        rotated[i] = nums[i - k];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = rotated[i];
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}


*/

/*

Another Approach 2

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> rotated(n);

    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = nums[i];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = rotated[i];
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}


*/


//  Optimal


#include <iostream>
using namespace std;
// Function to Reverse the array
void Reverse(int arr[], int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
void Rotate(int arr[], int n, int k)
{
 
  Reverse(arr, 0, n - k - 1);

  Reverse(arr, n - k, n - 1);
 
  Reverse(arr, 0, n - 1);
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 2;
  Rotate(arr, n, k);
  cout << "After Rotating the k elements to right ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
