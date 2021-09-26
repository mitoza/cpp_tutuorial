// main.cpp
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cout << "C++ Pointers" << endl;

    // Pointers - it's a variable which is using to storing the address of a data.
    int x = 10; // Data variable
    int *p; // Declaration. Address variable
    p = &x; // Initialization of pointer variable. p -> pointing on -> x

    cout << "x: "<< x << endl; // value of data variable
    cout << "&x: "<< &x << endl; // address of variable
    cout << "p: "<< p << endl; // address of data variable
    cout << "&p: "<< &p << endl; // address of pointer. Referencing
    cout << "*p: "<< *p << endl; // value of data variable. Dereferencing.

    // p=(int*)0x5638; - also can initialize pointer

    // Heep memory allocation. (usually arrays)
    int A[5] = {1,2,3,4,5}; // declaration in Stack memory, and will delite automatically
    //int *p; // declaration in Stack memory
    p = new int[5]; // declaration in Heep memory (allocation)

    // p = NULL; - will call memmory leak
    delete []p; // deallcation of
    p = nullptr;


    // Dynamic Allocation
    p = new int[5];
    cout << "Size of Pointer: " << sizeof(p) << " bytes" << endl;

    p[0] = 15;
    p[1] = 16;
    p[2] = 17;
    p[3] = 18;
    p[4] = 19;
    cout << "p[0]: " << p[0] << endl;
    p+=2;
    cout << "p[0]: " << p[0] << endl;

    delete []p;
    p = nullptr;


    // Problems with Pointers:
    // 1. Uninitialized Pointer
    // 2. Memory Leak
    // 3. Dangling Pointer - when someone already delete() a memmory

    return 0;
}
