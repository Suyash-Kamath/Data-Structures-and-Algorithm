#include <iostream>
using namespace std;

class A {
public:
    void sayHello() {
        cout << "Hello Suyash (no args)" << endl;
    }

    int sayHello(char name) {
        cout << "Hello Suyash (char arg)" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name << " (string arg)" << endl;
    }
};

int main() {
    A obj;

    obj.sayHello();            // Calls: void sayHello()
    obj.sayHello('S');         // Calls: int sayHello(char)
    obj.sayHello("Kamath");    // Calls: void sayHello(string)

    return 0;
}


/*

Compile-Time Polymorphism (Static Binding / Early Binding)
Definition:
Compile-time polymorphism means the decision of which method or function to call is made at the time of compilation.
Function Overloading


overloading is not allowed in this case


void speak() and int speak() , both are not same i mean cannot be overloaded

if you wanna overload then change the arguments


If I have to do function overloading then I have to change input arguments.


*/
