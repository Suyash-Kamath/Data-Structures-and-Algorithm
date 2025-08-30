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

    // Shallow Copy Constructor
    Hero(const Hero &h) {
        health = h.health;
        level = h.level;
        name = h.name;  // This is shallow copy, both objects share the same memory for 'name'
    }

    void print() {
        cout << "Name: " << name << ", Health: " << health << ", Level: " << level << endl;
    }

    // Destructor
    ~Hero() {
        delete[] name;  // Clean up dynamic memory
    }
};

int main() {
    Hero hero1(90, 'A', "Suyash");
    Hero hero2 = hero1;  // Shallow copy
    hero1.print();
    hero2.print();
    
    // Modifying one object will also affect the other due to shallow copy
    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();
    
    return 0;
}
