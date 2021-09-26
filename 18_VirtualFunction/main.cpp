// main.cpp
#include <iostream>

using namespace std;

class A {
public:
  virtual void funcX() { // Virtual make asset for overriding function in Class B
    cout << "Class A function X" << endl;
  }
  void funcY() { // Virtual make asset for overriding function in Class B
    cout << "Class A function Y" << endl;
  }
};

class B: public A {
public:
  void funcX() {
    cout << "Class B function X" << endl;
  }
  void funcY() {
    cout << "Class B function Y" << endl;
  }
};


int main(int argc, char** argv) {

    cout << "C++ VirtualFunction" << endl;

    B b;
    A *a = &b;
    // A *p = new B;
    a->funcX();
    a->funcY();

    return 0;
}
