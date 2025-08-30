// padding concept

/*


Why Padding Happens:
CPU works faster with aligned memory:

Most CPUs like variables (like int, double) to be aligned — placed at memory addresses divisible by their size.

For example, a 4-byte int wants to start at an address divisible by 4.

Compiler inserts padding automatically:

To satisfy alignment rules, the compiler adds extra unused bytes between members.

This makes memory access faster but can increase the size of the object.


Here's a clearer explanation:
Memory Alignment and CPU Efficiency:

CPUs are optimized to access aligned data quickly. For example, an int (which is typically 4 bytes) works best when it is stored at a memory address that is a multiple of 4 (like 0x04, 0x08, etc.).

When data isn't aligned correctly, the CPU may need extra cycles to access the data, which slows things down. This is because the CPU has to do extra work to fetch data that's not aligned on natural boundaries.

How Padding Helps:

Padding adds unused bytes between members of a struct or class to make sure that each member is aligned at an address that the CPU can access efficiently.

For example, if you have a char (1 byte) followed by an int (4 bytes), the compiler will add 3 bytes of padding between them to ensure that the int is aligned at a memory address that is a multiple of 4.

CPU's Cycle and Memory Access:

When a variable is aligned, the CPU can read or write it in a single cycle (or fewer cycles).

Without padding, if the data isn't aligned, the CPU may need multiple cycles to fetch the value, which slows things down.


*/



#include<iostream>
using namespace std;


class Hero{
    
  public:
  int x;
  int y;
  char c;
    
};

int main(){
    
    Hero a;
    cout<<"Size of Object is : "<<sizeof(a)<<endl;
    
    return 0;
}


/*

Alignment refers to the arrangement of data in memory according to certain boundaries or rules. The goal of alignment is to ensure that the CPU can access data efficiently, typically by aligning variables to addresses that are multiples of their sizes or required boundaries.

Why Alignment is Important:
CPU Efficiency: CPUs are designed to read data faster when it’s aligned to certain memory boundaries. Misaligned data requires additional cycles to access, making memory access slower.

Hardware Constraints: Some CPUs have strict alignment requirements. If data is not aligned correctly, the hardware might not even allow it to be accessed, or it might cause inefficient memory access, which can lead to slower performance.

How Alignment Works:
1. Basic Alignment Rule:
Data types have alignment requirements. For example:

char (1 byte) is typically aligned to any address.

int (4 bytes) is typically aligned to addresses that are multiples of 4.

double (8 bytes) is typically aligned to addresses that are multiples of 8.

This means that a char can start at any address, but an int must start at an address that is a multiple of 4 (for example, 0x04, 0x08, etc.).

also one rule



char a ;
int b;
char c;


here ans is 12

rule is intger is bigger right 


it tries dividing 4 by 9 , if not divide then it will select the closest that gets divided and ans is 12


what greedy alignment says is 

sabse bada wala datatype likho top me , then uske neeche wala chote chote size ka  likhnaa

e.g int a;
    char c;
    char b;

this is correct

*/