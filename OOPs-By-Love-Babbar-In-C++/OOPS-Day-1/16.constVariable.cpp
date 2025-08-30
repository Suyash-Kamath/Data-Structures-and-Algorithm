/*


| Use Case                 | Meaning                                             |
| ------------------------ | --------------------------------------------------- |
| `const int x`            | Value can't be changed                              |
| `const int* p`           | Pointer to const value                              |
| `int* const p`           | Const pointer                                       |
| `const int* const p`     | Both pointer and value are const                    |
| `void func(const int x)` | `x` can't be changed in `func()`                    |
| `int getHealth() const`  | Function won't modify the object                    |
| `const Hero h`           | `h` can't be modified, only const functions allowed |



*/

#include <iostream>
using namespace std;

class Hero {
private:
    const int id;        //  const data member (must be initialized)
    int health;

public:
    Hero(int _id, int _health) : id(_id) {
        health = _health;
    }

    int getHealth() const {    // const member function (can't modify any data)
        // health = 100;  Error: can't change data in const function
        return health;
    }

    void setHealth(int h) {
        health = h;
    }

    int getId() const {
        return id;   // Allowed, just accessing
    }

    void print() const {
        cout << "ID: " << id << ", Health: " << health << endl;
    }
};

int main() {

    const int level = 5;  // const variable — can't change later
    // level = 10;  Error: cannot assign to const

    Hero h1(101, 80);      // Normal object
    h1.setHealth(90);
    h1.print();

    const Hero h2(102, 70);   //  const object — can only call const member functions
    // h2.setHealth(100);  Error: can't call non-const function
    cout << "Health of h2: " << h2.getHealth() << endl;
    h2.print();               //  works because print() is const

    return 0;
}


/*
const int level = 5; — makes a constant variable.

const int id; — makes a data member constant (must initialize in constructor).

int getHealth() const — const member function can't modify class members.

const Hero h2(...); — a const object can only use const functions.
*/

/*


Exactly! Since the object is declared as const, it guarantees that its state (i.e., its member variables) cannot be modified after initialization. This ensures that the object remains in a read-only state throughout its lifetime.

Only const member functions can be called because they do not modify the state of the object. Non-const functions, which can change the object's state, are not allowed to be called on a const object.

You got it right! 👍



*/