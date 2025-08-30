#include<iostream>

using namespace std;

int main(){
    
    int x = 100;
    int y = 200;
    
    
    int &z=x;
    
    cout<<z<<endl;
    
    z = y;
    
    cout<<z<<endl;
    cout<<x<<endl;
    
    
    
    
    return 0;
}

/*

Great question, Suyash! Let's break it down clearly and simply.

---

### ✅ **1. Normal Variable (Value Variable)**

A **normal variable** stores **actual data** (the value itself).
When you assign one variable to another, the **value is copied**, and both variables are independent.

#### Example (C++):

```cpp
int a = 10;
int b = a;  // b gets a copy of a
b = 20;
// a is still 10
```

#### In Memory:

* `a` has its own memory space holding `10`.
* `b` has a different memory space holding a **copy** of `10`.

```
Memory:
[Address1] -> 10 (a)
[Address2] -> 10 (b)
```

---

### ✅ **2. Reference Variable**

A **reference variable** is just another **name (alias)** for an already existing variable.
It **doesn't have its own memory** — it refers to the **same memory** as the original.

#### Example (C++):

```cpp
int a = 10;
int& ref = a;  // ref is a reference to a
ref = 20;
// a is now 20
```

#### In Memory:

* `a` and `ref` both refer to the **same memory address**.
* Changing one affects the other.

```
Memory:
[Address1] -> 20 (a, ref)
```

---

### 🧠 Key Differences

| Feature            | Normal Variable          | Reference Variable              |
| ------------------ | ------------------------ | ------------------------------- |
| Stores             | Its **own value**        | Refers to **existing variable** |
| Memory             | Separate memory location | Shares memory with original var |
| Copy or Alias?     | **Copy** of the value    | **Alias** to the value          |
| Independent?       | Yes                      | No — they are the same thing    |
| Can be reassigned? | Yes                      | No — must be initialized once   |

---

Would you like a visual diagram to help see how this looks in memory?


No, a reference variable does not create a new memory space for the value itself.
It shares the memory address of the original variable.

[0x100] --> 100  (a and ref both refer to this same address)


*/