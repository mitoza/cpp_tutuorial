// main.cpp
#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int n, ...) {
  va_list list;
  va_start(list, n);
  int sum = 0;
  for(int i=0; i<n; i++) {
     sum+=va_arg(list, int);
  }
  va_end(list);
  return sum;
}

int main(int argc, char** argv) {

  cout << "C++ Ellipsis" << endl;

  cout << "Path: " << argv[0] << endl;

  cout << "Sum: " << sum(8, 1,2,3,4,5,6,7,8,9) << endl;

  return 0;
}
