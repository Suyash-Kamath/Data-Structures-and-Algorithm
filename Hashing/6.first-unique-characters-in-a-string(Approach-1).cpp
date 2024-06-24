/*

Given a string s , find the first non-repeating character in it and return its index 
If doesnt exist, return -1

string s = "leetcode"

output is 0th index 

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqueCharacter(string s) {
    unordered_map<char, int> frequency;

    // Populate the frequency map
    for (auto ch : s) {
        frequency[ch]++;
    }

    // Find the first unique character
    for (int i = 0; i < s.size(); i++) {
        if (frequency[s[i]] == 1) {
            return i;
        }
    }

    return -1;  // Return -1 if no unique character is found
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

// T.C : O(N)
// S.C : O(26) => O(1)

