#include<iostream>
using namespace std;

int solve(int n){

    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;


}

int main(){



    int l=5;
    int r=8;

    int ans = solve(l-1)^solve(r);
    cout<<ans;
    return 0;
}