#include <iostream>
using namespace std;

class Hero {
public:
    static int count;  // Static variable to count Hero objects

    Hero() {
        count++;  // Increment the count for every Hero object created
    }

    // Static function to access static variable
    static void displayCount() {
        cout << "Hero count: " << count << endl;
    }
};

// Defining static variable outside the class
int Hero::count = 0;

int main() {
    Hero hero1;
    Hero hero2;
    Hero::displayCount();  // Call static function using class name

    return 0;
}
