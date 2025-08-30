#include <iostream>
#include<cstring>
// #include "Hero.cpp"
using namespace std;

class Hero{

    public:
    // char name[100] is not a good practice , we allocate in heap so as to get more space , so dynamically allocated
    char *name;
    private:
    int health;
    public:
    char level;
    static int timeToComplete ;// doesnt depend on heroes or enemy
    
    void print(){
        cout<<endl;
        cout<<"Name: "<<this->name<<" ,";
        cout<<"Health : "<<this->health<<endl;
        cout<<"Level : "<<this->level<<endl;
    }
    
    int getHealth(){
        return health;
    }
    
    char getLevel(){
        return level;
    }
    
    void setHealth(int h){
        health=h;
    }
    
      void setLevel(char ch){
        level=ch;
    }



    Hero(){
       name = new char[100];
        cout<<"Constructor Bhai is called "<<endl;
    }
    
    // paramterise 
    
    
    Hero (int health){
        cout<<"this"<<this<<endl;
        this->health=health;
    }
    
    Hero (int health,char level){
        this->level = level;
        this->health=health;
    }
    
    // // you can write your own copy constructor
    
    Hero(Hero& temp){
        char *ch = new char [strlen(temp.name)+1];
        strcpy(ch,temp.name);
        cout<<"Copy constructor called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
        this->name = ch;
    }
    
    
    void setName(char name[]){
        strcpy(this->name,name);
    }
    
    // Destructor
    ~Hero(){
        
        cout<<"Destructor Bhai is called"<<endl;
    }
    
    // static function can access only static members
    static int random(){
       return timeToComplete;
    }
    
    
    

};

int Hero::timeToComplete =5;

// syntax is datatype classname::fieldname = value

int main()
{
    
    

    // hero type ka object
    // Hero h1;

    // cout<<sizeof(h1);
    // ans is 4 , memory is allocated 

    // suyash.health=70;
    // suyash.level='A';
    // cout<< "health is :" <<suyash.health<<endl;
    // cout<<"print level: "<<suyash.level<<endl;
    
    // cout<<suyash.getHealth();
    // cout<<sizeof(suyash);

    // Hero suyash;
    // Hero *b = new Hero;
    // b->setHealth(70);
    // b->setLevel('A');
    // cout<< suyash.level<<endl;
    // cout<< suyash.getHealth()<<endl;
    // cout<< (*b).getHealth()<<endl;
    // cout<<b->getLevel()<<endl;
    
    // cout<<"Hi"<<endl;
    // Hero suyash(10);
    
    // suyash.print();
    // cout<<"Adress"<< &suyash<<endl;
    // cout<<endl;
    // cout<<"Hello"<<endl;
    
    // cout<<endl;
    
    // Hero*h = new Hero(11); // agar Hero ko hero() kardu , to bhi same chee hogi , constructor called
    // h->print();
    // Hero temp(22,'B');
    
    
    // temp.print();
    
    
    
    
    // Hero suyash(70,'C');
    
    
    
    
    // Copy Constructor gets called -> jab aap class likhte hai to aapka in built ek aur copy constructor apne aap generate ho jata hai. apne aap ko  copy kar degaa
    
    
    // Hero vikas(suyash);
    
    // vikas.print();
    
    // suyash.print();
    
    
   
//   Hero hero1;
//   hero1.setHealth(12);
//   hero1.setLevel('D');
//   char name[7]= "Suyash";
//   hero1.setName(name);
   
//   hero1.print();
   
   
   // use default copy constructoe
    
    // Hero hero2(hero1);
    
    // Hero hero2=hero1  dono case me copy constructor call hone wala hai 
    
    // hero2.print();
    
    // hero1.name[0] = 'G';
    
    // hero1.print();
    // hero2.print();
    // this was above shallow copy
    
    //  default copy constructor shallow copy karta hai , dekho *name hai naa isliye
    
    // in shallow copy , you are accessing the same memory by two names
    
    
    // deep copy me same memory nahi , infact aur copy banti 
    
    //  so khudka banao copy constructor uskeliye
    
    // so in case of deep copy ,  you made entirely different array
    
    // copy assignment operator
    
    
    // simple a = b hai
    
    // object is already created ,after that you want to copy , then you will use copy assignment operator and copy in this way
    
    
    // hero1=hero2;
    
    // hero1.print();
    // hero2.print();
    
    // Destructor concept => memory ko deallocate karne keliye it is used
    
    // As your objects becomes out of scope means lifetime khatam , then destructor is called , and it frees the memory


// destructor is also created by default by system

// statically allocated
    // Hero a;
    
    // dynamically
    
    
    // Hero *b = new Hero();
    // manually destructor is called
    // delete b;
    
    // Remember : The object you form by static allocation , for them the destructor is called automatically so does for Hero a
    
    
    
    // Constructor for any object is called once , in the same way destructor is also called once for each element during its destruction time
    
    // As we write our own destructor , inbuilt destructor will be removed
    
    
    // Static keyword belongs to class, means to access there is no need to make object
        cout<<Hero::timeToComplete<<endl;
        Hero a;
        cout<<a.timeToComplete<<endl;// bad practice of accessing  static member 

    Hero b;
    b.timeToComplete = 10;
    cout<<a.timeToComplete<<endl;
      cout<<b.timeToComplete<<endl;
      
      
      
      
    //   also for static function ->
    // 1.no need to create object , you can simply call it using class name and 2. there is no this keyword , this is pointer to current object but here there is no object
    
    
    cout<<Hero::random()<<endl;
    return 0;
}