// main.cpp
#include <iostream>

using namespace std;

namespace First {
void func() {
  cout << "First Function" << endl;
}
}

namespace Second {
void func() {
  cout << "Second Function" << endl;
}
}

namespace Third {
void func() {
  cout << "Third Function" << endl;
}
}

using namespace Third;

int main(int argc, char** argv) {

  cout << "C++ Namespaces" << endl;


  First::func();
  Second::func();
  func();

  return 0;
}
