// main.cpp
#include <iostream>

using namespace std;

class A {
public:
  int x;
  A() {
    x = 1;
    cout << "Constructor A. " << x << endl;
  }
  void funcA() { cout << "funcA: " << x << endl; }
};

class B: virtual public A {
public:
  B() {
    x += 10;
    cout << "Constructor B. " << x << endl;
  }
  void funcB() { funcA(); cout << "funcB: " << x << endl; }
};

class C: virtual public A {
public:
  C() {
    x += 100;
    cout << "Constructor C. " << x << endl;
  }
  void funcC() {
    funcA();
    cout << "funcC: " << x << endl;
  }
};

class D: public B, public C {
public:
  D() {
    x += 1000;
    cout << "Constructor D. " << x << endl;
  }
  void funcD() {
    funcB();
    funcC();
    cout << "funcD: " << x << endl;
  }
};


int main(int argc, char** argv) {

    cout << "C++ Multiple Inheritance" << endl;

    D d;
    d.funcD();

    return 0;
}
