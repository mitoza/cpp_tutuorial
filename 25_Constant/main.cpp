#include <iostream>

using namespace std;

#define z 15 // Part of pre-compiller language

class A {
private:
  int x = 10;
public:
  void display() const {
    //x++; // const motifier disallow to change the value inside function
    cout << "X:" << x << endl;
  }
};

void showVal(const int &x) {
  // x++; // const motifier disallow to change the value inside function
  cout << "Value: " << x << endl;
}

int main(int argc, char** argv) {

    cout << "C++ Constant" << endl;

    int x = 4;
    const int y = 10; // Constant qualifier that use memory
    //y++; - read-only

    x++;
    cout << "x:" << x << ", y:" << y <<", z:" << z << endl;

    // Pointer constant (value constant)
    const int *ptr = &x;
    // *ptr+=10; // read-only
    ptr = &y; // we can change address
    cout << "ptr:" << *ptr << endl;

    // Pointet constant 2 (value constant)
    int const *ptr2 = &x;
    // *ptr2+=10; // read-only
    ptr2 = &y; // we can change the addres
    cout << "ptr2:" << *ptr2 << endl;

    // Constant Pointer 3 (address constant)
    int * const ptr3 = &x;
    *ptr3+=10; // read-write
    // ptr3 = &y; // can't change address
    cout << "ptr3:" << *ptr3 << endl;

    // Constant Pointer 4 (address and value constant)
    const int * const ptr4 = &x;
    //*ptr4+=10; // read-only
    //ptr4 = &y; //can't change address
    cout << "ptr4:" << *ptr4 << endl;

    A a;
    a.display();

    showVal(10);

    return 0;
}
