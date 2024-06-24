/*

You are given an integer array of size n and you have to process Q queries  .Each query
will contain an element X and we have to output the frequency of X in the array .

Note : All the elements in the array and element X will be in the range from 1 to N

e.g : arr = 8 3 5 2 3 1 6 5 7 4 3 1 4 

Q = 5

queries :
X       Frequency

3       3
1       2
7
4
5


1st Approach :Brute Force Time Complexity is : O(N*Q)

2nd Approach : Declare the size of array n+1

freq :  0 0 0 0 0 0 0 0 0 0  0  0 0  0 
        0 1 2 3 4 5 6 7 8 9 10 11 12 13

        update the value of the freq. array 

        This is known as Pre Computation

        Time Complexity is : O(N+Q)
        Space Complexity is : O(N)

        if there are 10^N elements  sized , it is not feasible to use 
        Frequency Array concept , so Hashmaps are introduced 

*/

/*
Using Frequency Array Concept :

#include<iostream>
#include<vector>
using namespace std;
int main(){

int n,q;
cin>>n>>q;

vector<int>arr(n+1);

for (int i = 1; i <=n; i++)
{
    cin>>arr[i];
}

vector<int>frequency(n+1,0);

for (int i = 1; i<=n; i++)
{
    frequency[arr[i]]++;
}

for (int i = 1; i<=q; i++){
    int x;
    cin>>x;
    cout<<frequency[x]<<endl;
}
    return 0;
}
*/


// Using Hashmap Concept

#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
int main(){

int n,q;
cin>>n>>q;
vector<int>arr(n+1);
for (int i = 1; i <=n; i++)
{
    cin>>arr[i];
}

unordered_map<int,int>frequency;

for (int i = 1; i <=n; i++)
{   
    frequency[arr[i]]++;
}

for(int i = 1; i <=q; i++){
    int x;
    cin>>x;
    cout<<frequency[x]<<"\n";
}
    return 0;
}