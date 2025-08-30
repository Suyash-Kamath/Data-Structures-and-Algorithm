#include<iostream>
using namespace std;


class Hero{
    
    
    
};

int main(){
    
    Hero a;
    cout<<"Size of an object: "<<sizeof(a)<<endl;
}


/*

✅ Reason:
C++ requires every object to have a unique memory address.
If it were 0 bytes, you couldn’t give each object a separate location in memory.

So C++ gives empty classes 1 byte to ensure:

You can create an object.

It has a unique address.

It supports features like inheritance and polymorphism.


empty class instantiate , system said property nahi hai lekin tera identification keliye , tera track rakhne keliye 1 deta hu so 1 byte of memory is allocated


*/