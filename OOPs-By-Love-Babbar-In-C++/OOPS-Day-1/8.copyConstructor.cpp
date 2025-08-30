// Yes, the copy constructor is also built-in (provided by the compiler by default), just like the default constructor and destructor.
// Copy constructor by default does shallow copy
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

    // Copy Constructor (Deep copy)
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
    Hero hero2 = hero1;  // Copy constructor is called
    hero1.print();
    hero2.print();
    return 0;
}


/*

Great question, Suyash. Let’s break this down step by step — especially what’s happening in your code and why that warning is showing up.

---

### ✅ **What the code is doing:**

You’ve created a class `Hero` that holds:

* a dynamic character array `name`
* an integer `health`
* a character `level`

You also correctly defined:

1. A **parameterized constructor** that dynamically allocates memory for `name` and copies the input.
2. A **copy constructor** that performs a **deep copy** of the `name` (to avoid shallow copy issues).
3. A `print()` function to display member variables.
4. A **destructor** to `delete[] name`.

You then create:

```cpp
Hero suyash(90,'A',"Suyash"); // parameterized constructor
Hero kamath = suyash;         // copy constructor
```

### ⚠️ **Why this warning appears:**

```
warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
```

This is the key part:

```cpp
Hero suyash(90,'A',"Suyash");
```

You're passing a **string literal** (`"Suyash"`) to a parameter `char *n` in the constructor. But in C++, string literals like `"Suyash"` are of type `const char[]`, which decay to `const char*`.

So you're passing a `const char*` to a `char*` parameter — this is **dangerous** because `char*` implies the data can be modified, but **string literals are read-only**, and modifying them is undefined behavior.

---

### ✅ **How to fix this properly:**

Update your constructor to accept `const char*`:

```cpp
Hero(int h, char l , const char *n){
    health = h;
    level = l;
    name = new char[strlen(n)+1];
    strcpy(name, n);
}
```

This will fix the warning. You're not modifying the input `n`, just copying it — so it’s perfectly safe and proper to accept it as `const char*`.

---

### 🧠 Bonus tip:

Because you are allocating memory using `new[]`, and your copy constructor does a deep copy, you're correctly preventing double deletion or aliasing issues (which would have happened if `kamath.name` and `suyash.name` pointed to the same memory).

---

Would you like me to explain deep vs shallow copy in detail with a small diagram or analogy?


*/