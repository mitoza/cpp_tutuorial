// main.cpp
#include <iostream>

using namespace std;

class A {
public:
  A() {
    cout << "Constructor A" << endl;
  }
  virtual ~A() {
    cout << "Destructor A" << endl;
  }
};

class B: public A {
public:
  B() {
    cout << "Constructor B" << endl;
  }
  ~B() {
    cout << "Destructor B" << endl;
  }
};

class C {
private:
  A *a;
public:
  C() {
    a = new A;
  }
  ~C() {
    delete a;
  }
};

void func() {
  cout << "Function" << endl;
  C c;
}

int main(int argc, char** argv) {

  cout << "C++ Destructor" << endl;

  A *y = new B;
  delete y;

  //A x;

  //func();

  cout << "Bye!" << endl;

  return 0;
}
