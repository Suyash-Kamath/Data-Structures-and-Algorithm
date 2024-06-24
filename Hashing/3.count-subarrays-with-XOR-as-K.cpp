#include<iostream>
#include <vector>
#include <unordered_map>

int countSubarraysWithXOR(const std::vector<int>& A, int B) {
    std::unordered_map<int, int> freq;
    int currentXOR = 0;
    int count = 0;

    for (int num : A) {
        // Compute current prefix XOR
        currentXOR ^= num;

        // If the current prefix XOR is equal to B, increment the count
        if (currentXOR == B) {
            count++;
        }

        // Check if there is a prefix XOR that when XORed with currentXOR gives B
        int requiredXOR = currentXOR ^ B;

        // If such a prefix XOR exists, add its frequency to the count
        if (freq.find(requiredXOR) != freq.end()) {
            count += freq[requiredXOR];
        }

        // Increment the frequency of the current prefix XOR in the map
        freq[currentXOR]++;
    }

    return count;
}

int main() {
    std::vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;
    std::cout << "Number of subarrays with XOR " << B << " is: " << countSubarraysWithXOR(A, B) << std::endl;
    return 0;
}