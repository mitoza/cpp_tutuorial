// main.cpp
#include <iostream>

using namespace std;

float func() {
  return 1342.6f;
}

int main(int argc, char** argv) {

  cout << "C++ Auto" << endl;

  // Auto declaration
  double d = 10.65;
  int i = 14;
  auto j = 2 * d + i * 'a';
  cout << "J: " << j << endl;

  // Auto function type return
  auto k = func();
  cout << "K: " << k << endl;

  // Declare the same data type as variable
  decltype(k) g = 342.34f;
  cout << "G: " << g << endl;

  return 0;
}
