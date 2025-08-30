#include<iostream>
using namespace std;


class Hero{
  private:
  int value;
  
  public:
  char level;
  int health;
  
  
  int getValue(){
      
      return value;
      
  }
  
  void setValue(int v){
      value = v;
    
  }
  
  
    
};

int main(){
    
    Hero a;
    
    cout<<"Value: "<<a.getValue()<<endl;
    cout<<"Level: "<<a.level<<endl;
    cout<<"Health: "<<a.health<<endl;
    
    
    return 0;
}
/*

Great — you're asking how the `this` keyword works **internally** in this class context:

```cpp
class Human {
private:
    int age;
public:
    int eyes;
    int hands;

    void getAge() {
        cout << this->age;
    }
};
```

Let’s break it down step-by-step.

---

## ✅ What is `this` in C++?

The keyword `this` is a **hidden pointer** automatically passed to all **non-static member functions** of a class.

It points to the **current object** — i.e., the object on which the method was called.

So when you write:

```cpp
suyash.getAge();
```

Internally, the compiler translates it to something like:

```cpp
Human::getAge(&suyash);
```

And inside `getAge()`, `this` is a pointer to the memory address of `suyash`.

So:

```cpp
this->age;
```

Means:

```cpp
(*this).age;  // or suyash.age in this case
```

---

## 🔬 Internals — How `this` works in memory

1. You create an object:

   ```cpp
   Human suyash;
   ```

   Memory is allocated for:

   * `age` (private)
   * `eyes`
   * `hands`

2. You call:

   ```cpp
   suyash.getAge();
   ```

   Internally becomes:

   ```cpp
   getAge(Human* this = &suyash);
   ```

3. Inside `getAge()`:

   ```cpp
   cout << this->age;
   ```

   is equivalent to:

   ```cpp
   cout << suyash.age;
   ```

   Even though `age` is private, it can still be accessed within the class using the `this` pointer.

---

## 🧠 Why use `this`?

* To **clarify** which object’s member you're accessing.
* Especially useful when function parameters **have the same name** as member variables:

  ```cpp
  void setAge(int age) {
      this->age = age;  // this->age (member) = age (parameter)
  }
  ```

Without `this`, you'd have no way to distinguish between the two `age` variables.

---

## ⚠️ Output in Your Program

In your code, since you never set `age`, and it's uninitialized, you’ll get **garbage value** printed.

To fix it:

```cpp
Human suyash;
suyash.setAge(21);  // define and use this function
suyash.getAge();    // prints 21
```

Would you like me to add a full working version with `setAge()` included and walk through how it works with `this`?


*/