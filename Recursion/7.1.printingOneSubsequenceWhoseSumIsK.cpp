// Take or Not Take technique
/*

Recommendation is do not use Global Variables

#include<iostream>
#include<vector>
using namespace std;
bool flag = false;
void printS(int index,vector<int>&ds,int initialSum ,int  sum,int arr[],int n){
    if(index==n){
        if(initialSum==sum && flag==false){
            flag=true;
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
        }
        return  ;
    }
    ds.push_back(arr[index]);
    initialSum+=arr[index];
    printS(index+1,ds,initialSum,sum,arr,n);
    initialSum-=arr[index];
    ds.pop_back();

    //not pick
    printS(index+1,ds,initialSum,sum,arr,n);
}
int main(){


int arr[] = {1,2,1};
int n = 3;
int sum = 2;
vector<int>ds;
printS(0,ds,0,sum,arr,n);

    return 0 ;
}

*/
// Functional method , not using Global Variable

// Technique to print only one answer

/*

bool f(){
base case satisfied , return a true else false


if(f()==true)
return;
f()
return false
}

*/



// Take or Not Take technique

#include<iostream>
#include<vector>
using namespace std;
bool printS(int index,vector<int>&ds,int initialSum ,int  sum,int arr[],int n){
    if(index==n){
        // condition satisfied
        if(initialSum==sum){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
            return true;
        } else{

        return false ;
        }
    }
    ds.push_back(arr[index]);
    initialSum+=arr[index];
    if(printS(index+1,ds,initialSum,sum,arr,n)==true){
        return true;
    }
    initialSum-=arr[index];
    ds.pop_back();

    //not pick
   if( printS(index+1,ds,initialSum,sum,arr,n)==true){
    return true;
   }
   return false;
}
int main(){


int arr[] = {1,2,1};
int n = 3;
int sum = 2;
vector<int>ds;
printS(0,ds,0,sum,arr,n);

    return 0 ;
}

//  what are you doing is you are avoiding future recursion calls if you are getting an answer