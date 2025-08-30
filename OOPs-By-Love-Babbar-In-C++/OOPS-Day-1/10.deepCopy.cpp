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

    // Deep Copy Constructor
    Hero(const Hero &h) {
        health = h.health;
        level = h.level;
        name = new char[strlen(h.name) + 1];  // Allocate new memory
        strcpy(name, h.name);
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
    Hero hero2 = hero1;  // Deep copy
    hero1.print();
    hero2.print();
    
    // Modifying one object will not affect the other due to deep copy
    hero1.name[0] = 'G';
    hero1.print();
    hero2.print();
    
    return 0;
}
