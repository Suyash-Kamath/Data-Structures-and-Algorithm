// By Default Classes has private access modifiers
// In C++, the default access modifier in a class is private.


#include<iostream>
using namespace std;


class Hero{
    
//   int value;
  
  public:
  char level;
  int health;
    
};

int main(){
    
    Hero a;
    
    // cout<<"Value: "<<a.value<<endl; // value is private by default
    cout<<"Level: "<<a.level<<endl;
    cout<<"Health: "<<a.health<<endl;
    
    
    
}
