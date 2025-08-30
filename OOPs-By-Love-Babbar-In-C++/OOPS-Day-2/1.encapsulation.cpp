// Encapsulation : Wrapping up Data Members and functions into single unit , usually a class
// Data members are also called as Properties/State and functions are also called as Methods/Behaviours
// Synonym for Encapsulation is information/data hiding.
// Abstraction is implementation hiding.

/*

Fully Encapsulated Class : in this all data members are marked private which means you can use them in same class only

Advantages : 1. Data Hide -> security increase
             2.Becomes read-only if using getter function , class can be made read-only.
             3.Code Reusability.
             4.Unit Testing.




*/

#include <iostream>
using namespace std;
class Student
{

private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this->age;

    }
};

int main()
{
    Student first;

    cout<<"Everything is alright "<<endl;
    return 0;
}
