/*


Inheritance : There will be a class, it will have some properties,behaviour, and you will inherit
it in any other class




*/
/*
#include<iostream>
using namespace std;

class Human{

    public:
    int height;
    int weight;
    int age;

    public:

    int getAge(){

        return this->age;
}
    void setWeight(int w){
        this->weight = w;
    }
};
*/
// public : konse mode se aap inherit karna chahte hai 

/*

If any attribute in base class is public and I have inherited it in public mode in child class then the
 inherited part will be public in child class also .

 When super class is public , and the mode of inheritance is private ,then your answer will be private

Private attributes of super class can't be inherited.



| Access Modifier | Same Class | Subclass | Other Classes |
| --------------- | ---------- | -------- | ------------- |
| `private`       | ✅          | ❌        | ❌             |
| `protected`     | ✅          | ✅        | ❌             |
| `public`        | ✅          | ✅        | ✅             |


*/
/*
class Male : protected Human{

    public:
    string color;

    void sleep(){
        cout<<"Male is sleeping"<<endl;
    }

    int getHeight(){
        return this->height;
    }

};

int main(){

    Male obj1;
    // cout<<obj1.age<<endl;
    // cout<<obj1.weight<<endl;
    // cout<<obj1.height<<endl;
    cout<<obj1.getHeight()<<endl;
    cout<<obj1.color<<endl;
    // obj1.setWeight(84);
    // cout<<obj1.weight<<endl;
    obj1.sleep();

    return 0;
}

*/


#include<iostream>
using namespace std;

class Human {

    protected:
    int height;

    public: 
    int weight;

    private:
    int age;

    public:
    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;

    }

};

class Male: private Human {

    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }

    int getHeight() {
        return this->height;
    }

};



int main() {

    Male m1;
    //cout << m1.height << endl;



/*
    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;

    cout << object1.color << endl;

    object1.setWeight(84);
    cout << object1.weight << endl;
    object1.sleep();
    */

    return 0;
}