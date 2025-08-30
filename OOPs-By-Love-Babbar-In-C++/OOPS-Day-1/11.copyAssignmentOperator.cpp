// Copy assignment operator works only when two objects are created
/*

 Simple Definitions in English:
Copy Constructor ⇒ Used when you create a new object by copying data from an existing object.

Copy Assignment Operator (=) ⇒ Used when you assign values from one already existing object to another already existing object.
*/
#include <iostream>
#include <cstring>
using namespace std;

class Hero {
public:
    char* name;
    int health;
    char level;

    // Constructor
    Hero(int h, char l, const char* n) {
        health = h;
        level = l;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy Constructor (Deep Copy)
    Hero(const Hero &h) {
        health = h.health;
        level = h.level;
        name = new char[strlen(h.name) + 1];
        strcpy(name, h.name);
    }

    // Copy Assignment Operator (Deep Copy)
    Hero& operator=(const Hero &h) {
        if (this != &h) {  // Self-assignment check
            delete[] name;  // Free previous memory
            health = h.health;
            level = h.level;
            name = new char[strlen(h.name) + 1];
            strcpy(name, h.name);
        }
        return *this;  // Return the current object
    }

    void print() {
        cout << "Name: " << name << ", Health: " << health << ", Level: " << level << endl;
    }

    // Destructor
    ~Hero() {
        delete[] name;
    }
};

int main() {
    Hero hero1(90, 'A', "Suyash");
    Hero hero2(50, 'B', "Vikas");

    hero2 = hero1;  // Copy assignment operator
    hero1.print();
    hero2.print();

    return 0;
}
