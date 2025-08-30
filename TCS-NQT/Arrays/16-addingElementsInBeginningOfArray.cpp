// #include <iostream>
// using namespace std;
// void insertatbegin(int *arr,int n,int value)
// {
//     for(int i=n-1;i>=0;i--)
//     {
//         arr[i+1]=arr[i];
//     }
//     arr[0]=value;
//     // cout<<arr[8];
// }
// int main()
// {
//     int n=8;
//     int arr[8]={10,9,14,8,20,48,16,9};
//     int value=40;
//     cout<<"Before inserting the value at beginning:"<<endl;
//      for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     insertatbegin(arr,n,value);
//     cout<<"After inserting the value at beginning:"<<endl;
//     for(int i=0;i<=n+1;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//     // cout<<arr[8];
//     return 0;
// }

// /*

// Understanding Out-of-Bounds Array Access

// Why you can access arr[8] in the insertatbegin function:

// While it might seem counterintuitive, the reason you can access arr[8] within the insertatbegin function is due to the way arrays are passed to functions in C++. When you pass an array to a function, you're essentially passing a pointer to the first element of the array. This pointer can be used to access elements beyond the declared size of the array, leading to undefined behavior.

// However, this doesn't mean it's safe or correct. Accessing elements beyond the array's bounds can lead to unpredictable results, such as:

// Memory Corruption: Overwriting memory that belongs to other variables or data structures.
// Segmentation Faults: The program may crash if it tries to access memory that it's not allowed to.
// Why you can't access arr[8] in the main function:

// In the main function, the array arr is declared with a size of 8. This means it has elements from arr[0] to arr[7]. Accessing arr[8] is beyond the array's bounds, and it will result in undefined behavior.

// To avoid these issues, always ensure that you access array elements within their valid bounds.

// Corrected Code:

// To fix the issue and insert the element correctly, you can modify the insertatbegin function as follows:

// C++

// void insertatbegin(int* arr, int n, int value) {
//     for (int i = n - 1; i >= 0; i--) {
//         arr[i + 1] = arr[i];
//     }
//     arr[0] = value;
// }
// In this corrected version, the loop iterates from n-1 to 0, ensuring that the elements are shifted within the bounds of the array.

// Remember to be cautious with array indexing and always check the array bounds to prevent unexpected behavior.


// The reason for the difference in behavior between the insertatbegin function and the main function lies in how arrays are passed to functions in C++.

// In the insertatbegin function:

// When you pass an array to a function, you're essentially passing a pointer to the first element of the array.
// This pointer can be used to access elements beyond the declared size of the array, but it's undefined behavior.
// In some cases, accessing out-of-bounds memory might not immediately crash the program, but it can lead to unpredictable results.
// In the main function:

// The array arr is declared with a fixed size of 8.
// Accessing arr[8] is clearly out of bounds and will lead to undefined behavior, which often manifests as a segmentation fault or other errors.
// To avoid these issues, it's crucial to always access array elements within their valid bounds.

// Here's a corrected version of the insertatbegin function that avoids out-of-bounds access:

// C++

// void insertatbegin(int arr[], int n, int value) {
//     for (int i = n - 1; i >= 0; i--) {
//         arr[i + 1] = arr[i];
//     }
//     arr[0] = value;
// }
// In this corrected version, the loop iterates from n-1 to 0, ensuring that the elements are shifted within the bounds of the array.

// Remember, while you might be able to access elements beyond the array's bounds in some cases, it's not recommended and can lead to unpredictable behavior. Always be mindful of array boundaries to write safe and reliable C++ code.






// void insertatbegin(int arr[], int n, int value) {

//     for (int i = n - 1; i >= 0; i--) {

//         arr[i + 1] = arr[i];

//     }

//     arr[0] = value;

// cout<<arr[8]; // how did i get the value as 9 , it should have shown errro

// }





// As I've explained before, accessing elements beyond the array's bounds is undefined behavior. This means the results can be unpredictable and vary depending on various factors.

// In your specific case, accessing arr[8] might have worked by chance due to the specific memory layout and compiler optimizations. However, it's not guaranteed behavior, and relying on it can lead to unexpected results and potential crashes.

// To avoid such issues, always ensure that you access array elements within their valid bounds.

// Here's a corrected version of the insertatbegin function that avoids out-of-bounds access:

// C++

// void insertatbegin(int arr[], int n, int value) {
//     for (int i = n - 1; i >= 0; i--) {
//         arr[i + 1] = arr[i];
//     }
//     arr[0] = value;
// }
// In this corrected version, the loop iterates from n-1 to 0, ensuring that the elements are shifted within the bounds of the array.

// Remember, writing code that adheres to array bounds is crucial for producing reliable and predictable software. By avoiding out-of-bounds access, you can prevent potential errors and ensure the correctness of your programs.



// In C++, out-of-bounds array access is not detected at compile time, and this is one of the reasons why it's considered unsafe. When you write code like:

// cpp
// Copy code
// for (int i = 0; i <= n + 1; i++) {
//     cout << arr[i] << " ";
// }
//  */


#include <iostream>
using namespace std;
void insertatbegin(int* arr,int n,int value)
{
    for(int i=n-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=value;
}
int main()
{
    int n=8;
    int arr[9]={10,9,14,8,20,48,16,9};
    int value=40;
    cout<<"Before inserting the value at beginning:"<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertatbegin(arr,n,value);
    cout<<"After inserting the value at beginning:"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}