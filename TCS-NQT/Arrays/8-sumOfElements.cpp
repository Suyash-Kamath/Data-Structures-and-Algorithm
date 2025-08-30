// Example 1:
// Input: N = 5, array[] = {1,2,3,4,5}
// Output: 15

#include <iostream>
using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }

    cout << "Sum of the array is " << sum;

    return 0;
}