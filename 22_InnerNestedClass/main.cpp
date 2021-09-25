#include <iostream>

using namespace std;

class A {
public:
  int x = 10;
  static int y;
  void func() {
    cout << "X: " << x << endl;
  }
  class B {
  public:
    int z = 10;
    void show() {
      cout << "Show class B. y: " << y << ", z: " << z << endl;
    }
  };
  B b;
};

int A::y=20;

int main(int argc, char** argv) {

  cout << "C++ Inner/Nested Class" << endl;

  A a;
  a.func();
  a.b.show();
  cout << "Y: " << a.y << endl;

  return 0;
}
