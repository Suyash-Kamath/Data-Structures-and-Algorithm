/*

#include<iostream>
using namespace std;


int main(){

    int start = 10;
    int goal = 7;
    int ans = start ^ goal;

    cout<< __builtin_popcount(ans);


    return 0;
}
*/


// second way 

/*
#include<iostream>
using namespace std;


int main(){

    int start = 10 ;
    int goal = 7;

    int  ans = start^goal;
    int count =0;
    while(ans){
        ans = ans & (ans-1);
        count++;
    }
    cout<<count;

    return 0;
}

*/

/*

#include<iostream>
using namespace std;

int main(){

    int start = 10 ;
    int goal = 7;
    int ans = start ^ goal;
    int count=0;

    for(int i=0;i<=31;i++){
        if(ans & (1<<i)){
            count++;
        }
    }

    cout<<count;

    return 0;
}
*/

#include<iostream>
using namespace std;

int main(){

    int count=0;
    int start =10;
    int goal =7;

    int ans = start ^ goal;

     while (ans > 0) {
        
        count+=(ans&1);
        ans=ans>>1;
    }

    cout<<count;
    return 0;
}