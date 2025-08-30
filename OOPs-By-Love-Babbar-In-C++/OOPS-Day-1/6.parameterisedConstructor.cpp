#include <iostream>
using namespace std;

class Hero {
public:
    int health;
    char level;

    // Parameterized Constructor
    Hero(int h, char l) {
        health = h;
        level = l;
    }

    void print() {
        cout << "Health: " << health << " Level: " << level << endl;
    }
};

int main() {
    Hero hero(90, 'B');  // Parameterized constructor is called here
    hero.print();
    return 0;
}
