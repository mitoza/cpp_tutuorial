// main.cpp
#include <iostream>

using namespace std;

class Parent final { // Final Will restrict inheritance of class Parent

};

class Parent2 {
  virtual void show() final { // Restrict inheritance of declaration show method in Child class

  }
};

class Child: Parent2 {
  void show2() {

  }
};

int main(int argc, char** argv) {

  cout << "C++ Final" << endl;


  return 0;
}
