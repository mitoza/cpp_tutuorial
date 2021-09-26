// main.cpp
#include <iostream>

using namespace std;

class B; // Declare friend name of a class
class A {
public:
  int x = 0;
protected:
  int y = 0;
private:
  int z = 0;
friend void func(); // Friend function
friend B; // Friend class
};

// Friend function
void func() {
  A a;
  a.x = 10;
  a.y = 20;
  a.z = 30;
  cout << a.x << "," << a.y << "," << a.z << endl;
}

// Friend class
class B {
public:
  A a;
  void func() {
    a.x = 40;
    a.y = 50;
    a.z = 60;
    cout << a.x << "," << a.y << "," << a.z << endl;
  }
};

int main(int argc, char** argv) {

    cout << "C++ FriendFunction" << endl;

    func();
    B b;
    b.func();

    return 0;
}
