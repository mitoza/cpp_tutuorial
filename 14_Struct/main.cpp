#include <iostream>

using namespace std;

struct Demo {
  int x;
  int y;

  void Display() {
    cout << x << "," << y << endl;
  }
};

class Demo2 {
public:
  int x;
  int y;

  void Display() {
    cout << x << "," << y << endl;
  }
};

int main(int argc, char** argv) {

    cout << "C++ Class VS Struct" << endl;

    // Struct
    Demo demo;
    demo.x = 10;
    demo.y = 20;
    demo.Display();

    // Class
    Demo2 demo2;
    demo2.x = 10;
    demo2.y = 20;
    demo2.Display();

    return 0;
}
