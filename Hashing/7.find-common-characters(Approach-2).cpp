/*

Given an String Array words , return an array of all characters that show up in all
strings within the words (including duplicate ) . You may return the answer in any
order


words = [ "bella", "label", "roller"]

Output : ["e","l","l"]


words = [ "cool", "lock", "cook" ]

output =["c","o"]


words = [ "ookloo", "ookkl", "ooollk","oolka" ]

output =["o","o","k","l"]

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<string> commonCharacters(vector<string>& arr) {
    vector<int> hash1(26, 0);
    vector<int> hash2(26, 0);

    // Initialize hash1 with the character counts of the first string
    for (auto ch : arr[0]) {
        hash1[ch - 'a'] += 1;
    }

    // Compare and update hash1 with the minimum counts from each string
    for (int i = 1; i < arr.size(); i++) {
        for (auto ch : arr[i]) {
            hash2[ch - 'a'] += 1;
        }
        for (int j = 0; j < 26; j++) {
            hash1[j] = min(hash1[j], hash2[j]);
            hash2[j] = 0;
        }
    }

    // Prepare the result
    vector<string> ans;
    for (int i = 0; i < 26; i++) {
        if (hash1[i] > 0) {
            int count = hash1[i];
            while (count--) {
                char x = i + 'a';
                string s(1, x); // Convert char to string
                ans.push_back(s);
            }
        }
    }

    return ans;
}

int main() {
    vector<string> arr = {"bella", "label", "roller"};
    vector<string> result = commonCharacters(arr);

    for (auto str : result) {
        cout << str << " ";
    }

    return 0;
}
