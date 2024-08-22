#include<iostream>
#include<string>
#include<algorithm>
using  namespace std;

string convert2Binary(int n){
    string result="";
    while(n!=0){
        if(n%2==1){
            result+='1'; 

        }
        else{
            result+='0';

        }
        n=n/2;
    }
        reverse(result.begin(),result.end());
        return result ;
}
int main(){

    int n =13;
    cout<<convert2Binary(n);
}


