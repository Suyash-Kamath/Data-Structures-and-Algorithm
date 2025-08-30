// Example 1:
// Input: 8 7 1 6 5 9
// Output: 1 5 6 9 8 7

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr;
    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(9);

    cout << "Before Sorting " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    sort(arr.begin(), arr.end());
    cout << endl;
    cout << "After Sorting " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
