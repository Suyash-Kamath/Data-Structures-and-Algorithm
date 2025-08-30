#include <iostream>
using namespace std;

class Hero {
public:
    int health;
    char level;

    // Constructor
    Hero(int health, char level) {
        this->health = health;  // Using 'this' pointer to refer to the current object's attributes
        this->level = level;
    }

    void print() {
        cout << "Health: " << health << " Level: " << level << endl;
    }
};

int main() {
    Hero hero(80, 'C');
    hero.print();
    return 0;
}
