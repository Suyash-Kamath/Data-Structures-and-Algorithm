#include<iostream>
using namespace std;
class A{
    public:
    int a ;
    int b;

    public:
    int add(){
        return a+b;
    }

    void operator+(A &obj){
        // int value = this->a;
        // int value2 = obj.a;
        // cout<<"output "<< value2-value<<endl;

        cout<<"Hi Suyash I am operator Overloaded"<<endl;

    }


    void operator() (){
        cout<<"I am round bracket "<<this->a<<endl ;
    }
};
int main(){

A obj1;
A obj2;

obj1.a=4;
obj2.a=7;

obj1+obj2;


obj1();
    return 0;
}