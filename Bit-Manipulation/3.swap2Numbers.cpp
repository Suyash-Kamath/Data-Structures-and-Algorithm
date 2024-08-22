#include<iostream>
using namespace std;

int main(){

    int a=0;
    int b=0;

    cout<<"Enter the value of a: ";

    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;
    cout<<"Values are "<<a<<" "<<b<<endl;
    a= a^b;
    b=a^b;
    a = a^b;


    cout<<"Swapped Value of a and b are "<<a<<" "<<b;





    return 0;
}