/*
#include<iostream>
using namespace std;

int main(){

    int n=13;

    int count =0;

    while (n>1)
    {
        if(n%2==1) count++;
        n/=2;
    }
    if(n==1) count++;


    cout<<count;
    


    return 0;
}
*/

// optimised
/*
#include<iostream>
using namespace std;

int main(){

    int count =0;
    int n=13;

    while(n>1){
        count+=n&1;
        n=n>>1;
    }

    if(n==1) count++;


    cout<<count;


    return 0;
}

*/

// Best Approach


#include<iostream>
using namespace std;


int main(){

    int n =13;
    int count=0;
    while(n!=0){
        n= n&(n-1);
        count++;
    }
    cout<<count;

    return 0;
}