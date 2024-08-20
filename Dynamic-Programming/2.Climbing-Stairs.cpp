// 0 1 1 2 3 5 8 .....

// Recursion Approach
/*

#include <iostream>
using namespace std;

int nStairs(int k) {
    if (k <= 1) return k;  // Base cases: fibonacci(0) = 0, fibonacci(1) = 1
    return nStairs(k - 1) + nStairs(k - 2);  // Recursive cases
}

int main() {
    int k;
    cout << "Enter the number: ";
    cin >> k;

    cout << "nStairs(" << k << ") = " << nStairs(k) << endl;

    return 0;
}

*/

// Dynamic Programming
/*
#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}


*/

// Optimized way
#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  
  int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}