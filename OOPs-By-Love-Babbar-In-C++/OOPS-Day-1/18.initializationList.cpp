// new way of writing constructor is initialization list


/*
#include<iostream>
using namespace std;


class Hero{

    public:
    int a;
    int b;
    const int c;
    // constant ko bhi initialise kardegaa , no need to do this->c = j; // normal constructor ke initialisation se error degaa
    
    Hero(int i,int j ):a(i),b(j),c(j){



    }

};

int main(){

Hero obj(10,20);

    return 0;
}
*/


/*

An initialization list in C++ is a way to initialize class members (variables) directly in the constructor, rather than assigning values to them within the constructor body. It's a more efficient and preferred way of initializing class members, especially for constant or reference members, or when you need to initialize base class members.


Required for Constant or Reference Members: You cannot assign values to const variables or references in the constructor body, but you must use an initialization list for them.


Const Members: For const members, you must initialize them using an initialization list, because you can't assign values to them in the body of the constructor.

Reference Members: For reference members, the initialization must also be done via an initialization list, as references must be bound to a valid object at the time of construction.






References Must Be Initialized: In C++, a reference must always be bound to an existing object at the time it is declared. You cannot create a reference without initializing it to some variable.

Cannot Rebind: Once a reference is initialized, it cannot be changed to refer to another object. This is different from pointers, which can be reassigned to point to different objects during their lifetime.

Initialization in Constructor: Since references must always be initialized to refer to an object, you cannot assign a reference in the constructor's body (like you would with normal members). Instead, you must initialize references in the initialization list of the constructor.


*/


#include <iostream>
using namespace std;

class Example {
    const int x;      // Const member, must be initialized
    int& y;           // Reference member, must be initialized
public:
    Example(int a, int& b) : x(a), y(b) {  // Initialization list
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main() {
    int num = 100;
    Example obj(10, num);
    return 0;
}


/*


#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 10;
    int& ref = x;  // ref is a reference to x
    
    cout << "Before: " << ref << endl;  // Output: 5

    // ref = y;  // This does NOT rebind ref to y. Instead, it changes the value of x to the value of y.
    
    ref = y;  // WRONG way to try and rebind a reference. It assigns the value of y to x (not what we want)
    
    cout << "After: " << ref << endl;  // Output: 10 (x's value is now 10)
    
    // ref = &y;  // WRONG: You can't change the reference itself (bind it to another variable)
    
    return 0;
}


*/