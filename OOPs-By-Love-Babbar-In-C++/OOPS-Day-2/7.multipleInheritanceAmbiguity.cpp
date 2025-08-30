#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "A's show()" << endl;
    }
};

class B {
public:
    void show() {
        cout << "B's show()" << endl;
    }
};

class C : public A, public B {
    // Inherits both A::show() and B::show()
};

int main() {
    C obj;
    // obj.show();  // ❌ Error: ambiguous
    obj.A::show();  // ✅ Call A's show
    obj.B::show();  // ✅ Call B's show

    return 0;
}
/*


How obj.A::show() works:
This is called explicit qualification using the scope resolution operator (::).

You’re telling the compiler:

"Hey, I know both A and B have a function called show(), but I want the one from class A."

Internally (conceptual memory layout):
In C++, when a class (C) inherits from multiple classes (A and B), the memory layout of obj looks like this:

obj (C)
├── A part
│   └── show() → A's version
└── B part
    └── show() → B's version

    So when you do:

obj.A::show(); → goes to the A subobject inside obj and calls A::show().

obj.B::show(); → goes to the B subobject inside obj and calls B::show().

*/