#include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}

// Function Overloading and Default argument
float add(float x, float y, float z=0) {
  return x + y + z;
}

// Function Template (Java<Generic> or C#<Delegate>)
template<class T>
T add_tmp(T a, T b, T c=0) {
  return a+b;
}

// Parameter pass. Pass by values
void swapByValue(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

// Parameter pass. Pass by pointers
void swapByPointer(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Parameter pass. Pass by reference.
// Function automatically become inline(a part on main program)
// May be call only for simple functions
void swapByReference(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Return Adress
int* getHeepFilledArray(int size) {
  int* p = new int[size];
  for(int i=0; i<size; i++) {
    p[i] = 5*(i+1);
  }
  return p;
}

// Return Reference
int & getReference(int &x) {
  return x;
}

int main(int argc, char** argv) {

    cout << "C++ Functions" << endl;

    // <return type | void> FunctionName([parameters)

    // Function Override
    cout << "2+3.5+4.5=" << add(2.0f, 3.5f, 4.5f) << endl;
    cout << "7+5=" << add(7, 5) << endl;

    // Function Template
    cout << "2+3.5=" << add_tmp(2.0f, 3.5f) << endl;
    cout << "7+5+3=" << add_tmp(7, 5, 3) << endl;

    // Default argument
    cout << "2+3.5=" << add(2.0f, 3.5f) << endl;
    cout << "2+3.5=" << add_tmp(2.0f, 3.5f) << endl;

    // Parameter passing method:
    int x, y;
    // 1. Pass by value
    x=10;
    y=20;
    swapByValue(x,y);
    cout << "Swap by values x:" << x << ", y:" << y << endl;

    // 2. Pass by Address
    x=10;
    y=20;
    swapByPointer(&x,&y);
    cout << "Swap by pointers x:" << x << ", y:" << y << endl;

    // 3. Pass by Reference
    x=10;
    y=20;
    swapByReference(x, y);
    cout << "Swap by pointers x:" << x << ", y:" << y << endl;

    // Return by Address
    int* q = getHeepFilledArray(5);
    for(int i=0; i<5; i++)
    cout << q[i] << endl;
    delete q;

    // Return Reference
    int a = 10;
    getReference(a) = 25;
    cout << "A: " << a << endl;


    return 0;
}
