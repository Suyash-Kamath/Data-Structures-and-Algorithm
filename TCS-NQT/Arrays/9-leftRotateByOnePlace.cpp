#include <iostream>
using namespace std;

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int temp = arr[0];
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before rotation " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
    cout << endl;

    cout << "After Rotation " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
// left rotate the remaining elements , this is what it meants