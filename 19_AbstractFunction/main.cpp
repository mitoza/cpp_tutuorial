// main.cpp
#include <iostream>

using namespace std;

// Interface class
class A {
public:
  virtual void func1() = 0;
};

// Abstract class
class B: public A {
public:

  void func2() {
    cout << "Class A function 2" << endl;
  }

  virtual void func3() = 0; // Pure virtual function

};

// Implementation class
class C: public B {
public:

  void func1() {
    cout << "Class B function 1" << endl;
  }

  void func3() {
    cout << "Class B function 3" << endl;
  }

};


int main(int argc, char** argv) {

    cout << "C++ VirtualFunction" << endl;

    //C c;
    //B *b = &c;
    B *b = new C;

    b->func1();
    b->func2();
    b->func3();

    return 0;
}
