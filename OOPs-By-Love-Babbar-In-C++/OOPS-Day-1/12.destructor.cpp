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
        cout << "Constructor called!" << endl;
    }

    // Destructor
    ~Hero() {
        delete[] name;  // Clean up dynamically allocated memory
        cout << "Destructor called!" << endl;
    }

    void print() {
        cout << "Name: " << name << ", Health: " << health << ", Level: " << level << endl;
    }
};

int main() {
    Hero hero(100, 'A', "Suyash");
    hero.print();
    return 0;  // Destructor is automatically called when the object goes out of scope
}
