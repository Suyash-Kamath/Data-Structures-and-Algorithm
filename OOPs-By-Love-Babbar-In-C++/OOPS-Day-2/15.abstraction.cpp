// essential chize dikhado , poori kahani bataane ki need nahi , means implementation hiding

// How can you achive abstraction in classes

/*


You can use access modifiers , through which you decide which you have to make visible and which not

*/

#include<iostream>
using namespace std;

class abstraction{

    private:
    int a;
    int b;

    public:

    void set(int x,int y){
        a=x;
        b=y;
    }

    void display(){


        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
    }

};

int main(){

abstraction obj;

obj.set(10,20);
obj.display();



    return 0;
}

