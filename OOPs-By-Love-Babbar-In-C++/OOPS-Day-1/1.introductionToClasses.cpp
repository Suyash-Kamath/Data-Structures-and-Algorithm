#include <iostream>
using namespace std;

class Hero{
  public:
  char name[100];
  int health;
  char level;
    
};
int main() {
    
    Hero a;
    // Static
    // a is just a normal object variable, not a reference variable.
    // In C++, Hero a; creates an object of the Hero class without needing the new keyword because it's created on the stack.
    /*
    
    So why does Hero a; work without new Hero();?
    Because C++ allows automatic (stack) allocation. The new keyword is only needed when you explicitly want 
    dynamic allocation (usually for flexibility or when the object’s lifetime needs to extend beyond the current function).
    So, object a directly contains all its data. It's not a pointer, not a reference, and not dynamically allocated.
    */
    cout<<"Name of the Hero : "<<a.name<<endl;
    cout<<"Level of the Hero : "<<a.level<<endl;
    cout<<"Health of the Hero : "<<a.health<<endl;



    // Dynamic 
    
    Hero *b = new Hero;
    // It works without parentheses (Hero()) because in C++, the parentheses are optional when calling a default constructor with no parameters.
    /*
        🤔 Why does C++ allow both?
            Because:

            Hero; and Hero(); both mean “call the default constructor.”

            The parentheses are optional if there are no parameters.

            This is a legacy rule for backward compatibility.
            🔹 Call the default constructor
            🔹 Allocate the object on the heap
            🔹 Return a pointer to that object
            🔹 Parentheses are optional if the constructor takes no arguments

     */
    cout<<"Name of the Hero : "<<b->name<<endl;
    cout<<"Level of the Hero : "<<b->level<<endl;
    cout<<"Health of the Hero : "<<b->health<<endl;
    

    return 0;
}


/*

Great question — this dives deep into how **C++ handles memory initialization** for **primitive types** vs **user-defined types**.

---

### 🔍 Why this happens:

```cpp
int* a = new int;    // ❗️ uninitialized (garbage value)
int* b = new int();  // ✅ initialized to 0
```

This is because of how **C++ distinguishes between value-initialization and default-initialization** for built-in types (like `int`, `double`, etc.).

---

### ✅ Explanation in Simple Terms:

#### 🔹 `new int;` → **default-initialized**

* For **built-in types**, default-initialization means **no initialization at all**.
* So the memory is allocated, but the value is **whatever garbage was already in that memory**.

#### 🔹 `new int();` → **value-initialized**

* For **built-in types**, value-initialization means **set to zero**.
* So this initializes the memory to `0`.

---

### 🧠 But for Classes (like `Hero`):

Both `new Hero;` and `new Hero();` call the **default constructor**, and **constructors always run**, so there's no such confusion.

That’s why:

```cpp
Hero* h1 = new Hero;
Hero* h2 = new Hero();
```

→ Both behave the same.

---

### 🔧 Technical Rule Summary:

| Type                             | `new T`            | `new T()`                        |
| -------------------------------- | ------------------ | -------------------------------- |
| Built-in                         | Uninitialized      | Initialized to 0                 |
| Class (with default constructor) | Constructor called | Constructor called (same effect) |

---

### 💡 Why does C++ do this?

Because C++ is designed to give you **fine control** over performance and memory — it avoids unnecessary initialization **unless you ask for it**.

This lets expert programmers skip zero-initialization when they know they’ll overwrite it anyway — it’s an **optimization feature**.

---

Would you like a visual memory diagram or want to see what happens with `double`, `bool`, or arrays?



*/