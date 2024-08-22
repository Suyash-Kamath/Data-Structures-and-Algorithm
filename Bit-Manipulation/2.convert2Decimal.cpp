#include <iostream>
#include <string>
using namespace std;

int convert(string n) {
    int length = n.length();
    int num = 0;
    int pow2 = 1;

    
    for (int i = length - 1; i >= 0; i--) {
        if (n[i] == '1') {
            num += pow2;  
        }
        pow2 *= 2;  
    }

    return num;
}

int main() {
    string n = "1101";
    cout << convert(n);
    return 0;
}
