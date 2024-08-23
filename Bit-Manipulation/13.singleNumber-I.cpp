/*

Brute Force

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){

    vector<int>arr={5,1,2,1,2};

    unordered_map<int,int>frequency;

    for(int i=0;i<arr.size();i++){



        frequency[arr[i]]++;
    }
    for(auto it:frequency){
        if(it.second==1){
            cout<<it.first;
        }
    }



    return 0;
}


*/


#include<iostream>
#include<vector>
using namespace std;


int main(){

    vector<int>nums={4,2,2,1,1};

    int ans=0;

    for(int i=0;i<nums.size();i++){
        ans =ans^nums[i];
    }

    cout<<ans;




    return 0;
}



/*

unordered_map gives T.C O(1)
map gives O(logm)

Hint: watch striver's hashmap lecture

*/