/*

We have an array of n integers and we have Q queries , each query will have 2 integers
l and r and we have to output the sum of the subarray starting from l to r


e.g : 2 4 3 1 6 5 7 3 2
      1 2 3 4 5 6 7 8 9


      Q  = 3

      1 = 4, r =  5     7
      l = 3 , r = 5     10
      l = 4 , r = 9     24



Formula : S(l,r) = PrefixSum[r] - PrefixSum[l-1]
*/

#include <iostream>
using namespace std;
#include <vector>
int main()
{

      int n, q;
      cout << "Enter the size of an array";
      cin >> n;

      vector<int> arr(n + 1);
      cout << "Enter the elements of an array";
      for (int i = 1; i <= n; i++)
      {
            cin >> arr[i];
      }
      vector<int> prefixSum(n + 1, 0);
      for (int i = 1; i <= n; i++)
      {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
      }
      cout << "Enter the number of queries";
      cin >> q;
      cout << "Enter the range of queries";
      for (int i = 1; i <= q; i++)
      {
            int l, r;
            cin >> l >> r;
            l++;
            r++;
            // queries 0-based karega , I did increment so as to become 1-Based Indexing
            cout << prefixSum[r] - prefixSum[l - 1] << "\n";
      }

      return 0;
}