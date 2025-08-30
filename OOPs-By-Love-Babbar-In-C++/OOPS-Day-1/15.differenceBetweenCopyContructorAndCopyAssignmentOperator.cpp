#include <iostream>
using namespace std;

class Hero {
public:
    int health;

    // Constructor
    Hero(int h) {
        health = h;
        cout << "Constructor called\n";
    }

    // Copy Constructor
    Hero(const Hero& other) {
        health = other.health;
        cout << "Copy Constructor called\n";
    }

    // Display Function
    void print() {
        cout << "Health: " << health << endl;
    }
};

int main() {
    // Step 1: Original object
    Hero a(100);

    // Step 2: Copy Constructor (used when making a new object using an existing one)
    Hero b = a; // Copy constructor is called here
    b.print();

    // Step 3: Copy Assignment Operator (used after both objects already exist)
    Hero c(200); // c already exists
    c = a;       // Assignment happens here
    cout << "After assignment:\n";
    c.print();   // No copy constructor here, just assignment

    return 0;
}
