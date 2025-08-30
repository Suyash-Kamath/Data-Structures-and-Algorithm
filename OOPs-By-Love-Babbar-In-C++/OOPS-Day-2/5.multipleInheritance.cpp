// one class can inherit many class


#include<iostream>
using namespace std;


class Animal {

    public:
    int age;
    int weight;


    public:
    void bark() {
        cout << "Barking " << endl;
    }
};

class Human {
    public:
    string color;

    public:
    void speak() {
        cout << "Speaking " << endl;
    }
};

//Multiple Inheritance
class Hybrid: public Animal, public Human {

};


int main() {

    Hybrid obj1;
    obj1.speak();
    obj1.bark();


    return 0;
}


/*

Why are multiple inheritances not supported by JAVA?
Multiple inheritances cause ambiguity. When we have a function with the same name in both the classes, the compiler cannot decide which function to inherit; therefore, it is not supported by java.


Why Java does NOT support multiple inheritance with classes?
Because of ambiguity. Suppose:

Class A has a method show().

Class B also has a method show().

Now if class C inherits from both A and B, and we call show(), the compiler won’t know which one to call — A’s or B’s.

This is called the Diamond Problem.

*/