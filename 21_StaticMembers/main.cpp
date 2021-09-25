#include <iostream>

using namespace std;

class A {
public:
  static int count; // Static member
  A() {
    count++;
  }
  static int getCount() { // Static member function
    return count;
  }
};

int A::count=0; // Global declaration of static variable

int main(int argc, char** argv) {


  cout << "C++ Static Member" << endl;

  A a1;
  A a2;
  A a3;

  cout << "Count: " << a1.count << endl;
  cout << "Count: " << a2.getCount() << endl;

  cout << "Count: " << A::count << endl;
  cout << "Count: " << A::getCount() << endl;



  return 0;
}
