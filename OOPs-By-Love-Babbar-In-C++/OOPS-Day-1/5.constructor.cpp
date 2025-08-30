#include <iostream>
using namespace std;

class Hero {
public:
    int health;
    char level;

    // Default Constructor
    Hero() {
        cout << "Constructor called!" << endl;
        health = 100; // Setting default values
        level = 'A';
    }

    void print() {
        cout << "Health: " << health << " Level: " << level << endl;
    }
};

int main() {
    Hero hero;  // Default constructor is called here
    hero.print();
    return 0;
}


/*

Simple Analogy:
A void function is like a worker who finishes a task and reports back, but brings nothing with them.

A constructor is like a setup team that prepares your house before you move in — they don't bring the house back to you, they set it up where it already exists.

Excellent! You're asking:

> **How is `void` return in a function different from a constructor, which also returns nothing?**

Let’s compare them **clearly and deeply**.

---

## 🟢 Similarity: Both `void` functions and constructors do **not return any value**

But that’s where the similarity ends.
Now let's break down **how they’re different** in purpose and behavior.

---

## 🔁 1. **Function (`void`)**

```cpp
void sayHello() {
    cout << "Hello";
}
```

### 🔹 Purpose:

* A `void` function **performs an action**, then exits.
* It **does not return** any value.
* Control just goes back to the caller.

### 🔹 Internally:

* CPU calls the function.
* After executing, it jumps back to where it was called from.
* **Nothing is placed in a return register** (like EAX in x86).

---

## 🧱 2. **Constructor**

```cpp
class Human {
public:
    Human() {
        cout << "Constructor called!";
    }
};
```

### 🔹 Purpose:

* A constructor **initializes a newly created object**.
* It **cannot have a return type at all** — not even `void`.
* It's **automatically called** when an object is created.

### 🔹 Internally:

* Memory for the object is already allocated.
* Constructor gets called with a hidden `this` pointer.
* It **modifies the memory** of the object (`this->member = ...`)
* Then, control returns — but **no object is returned**, because it's already created in-place.

---

## ⚙️ Key Differences:

| Feature                  | `void` Function                | Constructor                          |
| ------------------------ | ------------------------------ | ------------------------------------ |
| Return type              | `void` (explicit)              | No return type allowed               |
| Purpose                  | Perform action                 | Initialize a new object              |
| Called by                | Manually (e.g., `sayHello();`) | Automatically when object is created |
| Returns control to       | Calling function               | Object creation context              |
| Returns value?           | No                             | No                                   |
| Creates object?          | No                             | Yes (initializes one)                |
| Can you write `return;`? | Yes (optional)                 | No need; ends naturally              |

---

### 🧠 Visual Example:

```cpp
Human h;  // memory allocated → constructor called → memory initialized
```

vs.

```cpp
sayHello();  // function called → message printed → returns to caller
```

---

### 💬 Simple Analogy:

* A `void` function is like a **worker** who finishes a task and reports back, but brings **nothing** with them.
* A constructor is like a **setup team** that prepares your house **before you move in** — they don't bring the house back to you, they **set it up where it already exists**.

---

Would you like to see a code example showing how memory and calls differ between both?
The constructor is called automatically by the object creation context, not by the programmer directly. This is why the constructor doesn't "return" anything — including void — back to the programmer or the flow.
*/