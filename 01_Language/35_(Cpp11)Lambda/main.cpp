// main.cpp
#include <iostream>

using namespace std;

template<typename T>
void func(T f) {
  f();
}

int main(int argc, char** argv) {

  cout << "C++ Lambda expressions or Unnamed functions" << endl;

  // [captured_list](parameter_list)->returntype{body};

  // Function Call
  [](){cout<<"Hello Lambda"<<endl;}();
  [](int x, int y) {cout << "Sum:" << x + y << endl;} (3,5);

  // Function return
  auto f = [](){cout<<"Hello Lambda"<<endl;};
  f();

  int x = [](int x, int y) {return x + y;}(5,3);
  cout << "SumX: " << x << endl;

  // Declare typedef of return type
  int y = [](int x, int y) -> int{return x + y;}(10,5);
  cout << "SumY: " << y << endl;

  // Access local variables inside functions
  int a = 10;
  int b = 5;
  [a,b](){cout << a << " " << b << endl;}();

  // Changing of captured variables
  [&a,&b](){cout << a++ << " " << b++ << endl;}();

  // Changing all the values in the scope
  [&](){a=200; b=300;}();
  cout << "Scope values: " << a << " " << b << endl;

  // Function call inside function
  func(f);


  return 0;
}
