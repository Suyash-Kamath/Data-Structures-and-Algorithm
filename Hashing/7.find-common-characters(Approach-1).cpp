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


<char,int>
a to z

minimum frequency = {

{a,1000}
{0,1000},
{l,1000},
{k,1000}

}

for(a,z)

frequency of each word ={
{o,2},
{k,2}
}


*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> commonChars(vector<string>& words) {
    unordered_map<char, int> minimumFrequencyOverAll;

    // Initialize minimumFrequencyOverAll with a large number for each character
    for (char ch = 'a'; ch <= 'z'; ch++) {
        minimumFrequencyOverAll[ch] = 1000;
    }

    // Process each word to update the minimum frequency of each character
    for (auto word : words) {
        unordered_map<char, int> frequency;
        for (auto ch : word) {
            frequency[ch]++;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            minimumFrequencyOverAll[ch] = min(minimumFrequencyOverAll[ch], frequency[ch]);
        }
    }

    // Collect the common characters based on their minimum frequency
    vector<string> ans;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        while (minimumFrequencyOverAll[ch] > 0) {
            ans.push_back(string(1, ch));
            // it means we want the string of one character as we are outputting seperately
            minimumFrequencyOverAll[ch]--;
        }
    }

    return ans;
}

int main() {
    vector<string> words = {"bella", "label", "roller"};
    vector<string> result = commonChars(words);

    cout << "Common characters: ";
    for (const string& ch : result) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}


/*

Time Complexity is : O(N)
Space Complexity is O(2*26) => O(1)

*/