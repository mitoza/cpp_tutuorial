#include <iostream>

using namespace std;

class DivizionByZeroException: exception {
public:
  char * what() {
    return "Divizion by Zero";
  }
};

int divizion(int a, int b) throw (DivizionByZeroException) {
  if (b==0) {
      throw DivizionByZeroException();
  }
  return a/b;
}

int divizion2(int a, int b) throw () { // this function will doesn't throw any exceptions
  return a/b;
}

int main(int argc, char** argv) {

  cout << "C++ Exception Handler" << endl;

  int a,b;
  try {
    cout << "Enter a number A: ";
    cin >> a;
    cout << "Enter a number B: ";
    cin >> b;
    int c = divizion(a,b);
    cout << a << "/" << b << "=" << c << endl;
  } catch (exception e) {
      cout << "Divizion by Zero: " << e.what() << endl;
  } catch (int e) {

  } catch (...) { // "..." - ellipse

  }

  return 0;
}
