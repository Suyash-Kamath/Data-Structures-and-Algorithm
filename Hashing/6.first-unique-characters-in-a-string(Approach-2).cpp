/*

Given a string s , find the first non-repeating character in it and return its index 
If doesnt exist, return -1

string s = "leetcode"

output is 0th index 

idx=0
isfrequency[s[idx]] > 1

<char,int>{char,frequency}


*/

#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqueCharacter(string s) {
    unordered_map<char, int> frequency;
    int idx = 0;

    for (int i = 0; i < s.size(); i++) {
        frequency[s[i]]++;
        if (frequency[s[idx]] > 1) {
            idx++;
            while (idx < s.size() && frequency[s[idx]] > 1) {
                idx++;
            }
            if (idx == s.size()) {
                return -1;
            }
        }
    }

    return idx;
}

int main() {
    string s = "loveleetcode";
    int index = firstUniqueCharacter(s);

    if (index != -1) {
        cout << "The first unique character is at index: " << index << endl;
    } else {
        cout << "There is no unique character in the string." << endl;
    }

    return 0;
}


/*
Time Complexity is O(2*N) => O(N)
Space Complexity is O(26) => O(1)
*/