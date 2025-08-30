#include <iostream>
using namespace std;

class Hero {
public:
    static int timeToComplete;  // Static variable, shared by all instances

    static void display() {  // Static function
        cout << "Time to complete: " << timeToComplete << endl;
    }
};

// Defining static variable outside the class
int Hero::timeToComplete = 5;

int main() {
    Hero hero1;
    Hero hero2;

    // Accessing static member using object (not recommended)
    cout << hero1.timeToComplete << endl;

    // Accessing static member using class name (recommended)
    Hero::timeToComplete = 10;
    Hero::display();
    
    return 0;
}
