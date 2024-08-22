/*

Using Left Shift Operator

#include<iostream>
using namespace std;

int main(){

    int n=0;
    int i=2;

    if(n&(1<<i)!=0)
    {
    cout<<"It is Set";

    }

    else{
        cout<<"It is not Set";
    }

    return 0;
}

*/

// Using right shift Operator

#include<iostream>
using namespace std;
int main(){


    int n = 13;
    int i =2;

    if((n>>i)&1!=0){
        cout<<"It is set";
    }
    else{
        cout<<"It is unset";
    }


    return 0;
}