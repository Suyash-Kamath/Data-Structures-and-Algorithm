// Compile time polymorphism is called Static Polymorphism
// Run time Polymorphism is called Dynamic Polymorphism

// These are something which you know at run time, that these will exist in multiple forms

// 1.Method Overriding


/*

At run time something is existing in multiple forms , but you don't know it at compile time, you will know when you use it



*/

// Method Overriding 

/*

One class inherit from parent class, and it is implemented same method with different way
There is a method in parent class , which is already implemented, and it has put its own implementation in it.



Rules: 1.The method of parent class and of the child class must be of same name
       2.Also methods of parent and child class mus have same parameters
       3. it is possible through inheritance only


       runtime polymorphism depends on inheritance
*/




#include<iostream>
using namespace std;

class Animal{

public:
void speak(){
    cout<<"Speaking "<<endl;
}

};


class Dog:public Animal{
    public:
    void speak(){
        cout<<"Barking "<<endl;
    }
};

int main(){


Dog obj;
obj.speak(); // it called barking 

// so it means there is speak function of Dog , so we got this

// so when you have not put any implementation in dog , it is giving speaking else barking





    return 0;
}
